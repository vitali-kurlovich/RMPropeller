//
// Created by Vitali Kurlovich on 11/19/16.
//

#ifndef RMPROPELLER_RMMEMMORYBUFFER_HPP
#define RMPROPELLER_RMMEMMORYBUFFER_HPP

#include "../../common/common.hpp"
#include <list>

#include "RMMemmoryPage.hpp"
#include "RMIOBuffer.hpp"

namespace rmengine {

    namespace buffer {

        class RMMemmoryBuffer final : public RMIOReadBuffer, RMIOWriteBuffer {
            std::list<RMMemmoryPage*> _pages;
            std::list<RMMemmoryPage*> _pool;
            size_t _size{0};
            size_t _seek{0};
        public:


            ~RMMemmoryBuffer() {
                for (auto it =_pages.begin(); it!=_pages.end() ; ++it) {
                   delete *it;
                }

                for (auto it =_pool.begin(); it!=_pool.end() ; ++it) {
                    delete *it;
                }
            }

            virtual bool write(const void *buffer, size_t size) noexcept override {
                //bool flag = currentPage(size)->write((const uint8*)buffer, size);
                _size += size;

                size_t offset = 0;
                size_t bytesToWrite = size;

                if (!_pages.empty()) {
                    auto page = _pages.back();
                    auto pageSize = page->size();

                    if (pageSize < bytesToWrite) {

                        page->write(((const uint8 *) buffer) + offset, pageSize);
                        offset += pageSize;
                        bytesToWrite -= pageSize;
                    } else {
                        page->write(((const uint8 *) buffer) + offset, bytesToWrite);
                        bytesToWrite = 0;
                    }
                }

                if (bytesToWrite == 0)
                    return true;

                auto pages = pagesBySize(bytesToWrite);

                for (auto it = pages.begin(); it!=pages.end() ; ++it) {
                    auto page = *it;
                    auto pageSize = page->size();
                    if (pageSize < bytesToWrite) {
                        page->write(((const uint8*)buffer) + offset, pageSize);
                        offset += pageSize;
                        bytesToWrite -= pageSize;
                    } else {
                        page->write(((const uint8*)buffer) + offset, bytesToWrite);
                    }

                    _pages.push_back(page);
                }

                return true;
            }

            virtual bool read(void* dst, size_t size) noexcept override {
                assert((_seek+ size) <= _size);

                if (_seek + size > _size)
                    return false;

                size_t copysize = size;
                size_t offset = 0;
                size_t skipped = 0;

                for (auto it =_pages.begin(); it!=_pages.end() ; ++it) {
                    auto page = *it;

                    auto newpos = skipped + page->offset();
                    if (newpos < _seek) {
                        skipped = newpos;
                        continue;
                    }

                    auto readBytes = page->read((_seek-skipped),  ((uint8 *)dst) + offset, copysize);
                    copysize -= readBytes;
                    offset += readBytes;
                    _seek += readBytes;
                    skipped = _seek;
                    if (copysize == 0) return true;
                }
                return false;
            }

            virtual bool seek(size_t offset) noexcept override {
                assert(offset  < _size);
                if (offset  >= _size)
                    return false;
                _seek = offset;
                return true;
            }

            virtual size_t seek() noexcept override {
                return _seek;
            }
            virtual  size_t size() const noexcept override {
                return _size;
            }

            void recycle() noexcept {
                _size = 0;
                _seek = 0;
                for (auto it =_pages.begin(); it!=_pages.end() ; ++it) {
                    auto page = *it;
                    page->recycle();
                    _pool.push_back(page);
                }
                _pages.clear();
            }

        protected:

            std::list<RMMemmoryPage*> pagesBySize(size_t size) {
                std::list<RMMemmoryPage*> pages;

                if (_pool.empty()) {
                    auto page = new RMMemmoryPage(size);
                    pages.push_back(page);
                } else {
                    size_t rqsize = size;

                    for (auto it =_pages.begin(); it!=_pages.end() ; ++it) {
                        auto page = *it;
                    }

                }
                return pages;
            }
        };


    }
}


#endif //RMPROPELLER_RMMEMMORYBUFFER_HPP
