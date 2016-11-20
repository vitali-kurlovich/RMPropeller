//
// Created by Vitali Kurlovich on 11/19/16.
//

#ifndef RMPROPELLER_RMMEMMORYPAGE_HPP
#define RMPROPELLER_RMMEMMORYPAGE_HPP

#include "../../common/common.hpp"
#include <memory>
#include <limits>

#define RMMEM_PAGE_SIZE (4*1024)

namespace rmengine {

    namespace buffer {

        class RMMemmoryPage {
            void* _buffer{nullptr};
            size_t _pagesize{0};
            size_t _offset{0};
        public:

            RMMemmoryPage() {}

            RMMemmoryPage(size_t size)
                    : _pagesize(size)
            {
            }

            virtual ~ RMMemmoryPage() {
                if (_buffer != nullptr) {
                    free(_buffer);
                }
            }

            bool write(const uint8 *src, size_t length) {
                if (length == 0) return true;
                if (!canWrite(length)) return false;
                if (_buffer == nullptr) {

                    size_t reqmem = length;
                    size_t align = length % RMMEM_PAGE_SIZE;
                    if (align != 0) {
                        reqmem += (RMMEM_PAGE_SIZE - align);
                    }

                    _pagesize = (reqmem > _pagesize ? reqmem : _pagesize);
                    _buffer = malloc(_pagesize);
                }

                memcpy( ((uint8*)_buffer) + _offset, src, length);
                _offset += length;

                return true;
            }

            size_t read(void* dst, size_t size) const noexcept {
                return read(0, dst, size);
            }

            size_t read(size_t seek, void* dst, size_t size) const noexcept {

                if (size <= 0) return 0;

                if (_offset >= size + seek) {
                    memcpy(dst, ((const uint8*)_buffer) + seek, size);
                    return size;
                } else {
                    memcpy(dst, ((const uint8*)_buffer)+seek, _offset - seek);
                    return _offset - seek;
                }
            }

            bool canWrite(size_t length) const {
                if (_buffer == nullptr) return true;

                return (_offset + length) <= _pagesize;
            }

            constexpr
            size_t size() const noexcept {
                return _buffer == nullptr ? uint32_max : (_pagesize - _offset);
            }

            constexpr
            size_t pageSize() const noexcept {
                return _pagesize;
            }

            constexpr
            size_t offset() const noexcept {
                return _offset;
            }

            constexpr
            void* buffer() const noexcept {
                return _buffer;
            }

            void recycle() {
                _offset = 0;
            }
        };

    }
}

#endif //RMPROPELLER_RMMEMMORYPAGE_HPP
