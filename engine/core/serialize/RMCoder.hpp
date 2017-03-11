//
// Created by Vitali Kurlovich on 11/19/16.
//

#ifndef RMPROPELLER_RMCODER_HPP
#define RMPROPELLER_RMCODER_HPP

#include "../../common/common.hpp"

#include <string>
#include <vector>
#include <array>

#include "../buffer/RMIOBuffer.hpp"

namespace rmengine {

    namespace serialize {

        //template <typename T>
        class RMCoder {
            buffer::RMIOWriteBuffer* _writeBuffer{nullptr};

        protected:
            bool write(const void *buffer, size_t size) noexcept {
                return _writeBuffer->write(buffer, size);
            }

        public:

            RMCoder(buffer::RMIOWriteBuffer* writeBuffer)
                    : _writeBuffer(writeBuffer) {
                        assert(_writeBuffer != nullptr);
                    }

            template <typename T>
            void encode(const T val) {
                const T buffer(val);
                write(&buffer, sizeof(T));
            }

            void encode(RMType type) {
                encode((uint8) type);
            }

            template <typename T>
            void encode(const T* buffer, uint32 lenght) {
                encode(lenght);
                write(buffer, lenght*sizeof(T));
            }

            void encode(const std::vector<uint8> &vector) {
                encode(vector.data(),vector.size());
            }

            void encode(const char* str) {
                uint32 length = strlen(str);
                encode(length);
                write(str, length*sizeof(str[0]));
            }

            void encode(const wchar_t* str) {
                const uint32 length = wcslen(str);
                encode(length);
                write(str, length*sizeof(str[0]));
            }

            void encode(const std::string &str) {
                const uint32 length = str.length();
                encode(length);
                write(str.data(), length*sizeof(char));
            }

            void encode(const std::wstring &str) {
                const uint32 length = str.length();
                encode(length);
                write(str.data(), length*sizeof(wchar_t));
            }
        };
    }
}


#endif //RMPROPELLER_RMCODER_HPP
