//
// Created by Vitali Kurlovich on 11/19/16.
//

#ifndef RMPROPELLER_RMDECODER_HPP
#define RMPROPELLER_RMDECODER_HPP



#include "../../common/common.hpp"
#include <vector>

#include "../buffer/RMIOBuffer.hpp"

namespace rmengine {

    namespace serialize {

        class RMDecoder {
            buffer::RMIOReadBuffer* _readBuffer{nullptr};

        protected:
            bool read(void* dst, size_t size) noexcept {
                return _readBuffer->read(dst, size);
            }

        public:

            RMDecoder(buffer::RMIOReadBuffer* readBuffer)
                    : _readBuffer(readBuffer) {
                assert(_readBuffer != nullptr);

            }



            uint8 decode_uint8() {
                uint8 val;
                read(&val, sizeof(val));
                return val;
            }

            uint8 decode_int8() {
                int8 val;
                read(&val, sizeof(val));
                return val;
            }

            uint16 decode_uint16() {
                uint16 val;
                read(&val, sizeof(val));
                return val;
            }

            int16 decode_int16() {
                int16 val;
                read(&val, sizeof(val));
                return val;
            }


            uint32 decode_uint32() {
                uint32 val;
                read(&val, sizeof(val));
                return val;
            }

            int32 decode_int32() {
                int32 val;
                read(&val, sizeof(val));
                return val;
            }

            uint64 decode_uint64() {
                uint64 val;
                read(&val, sizeof(val));
                return val;
            }

            int64 decode_int64() {
                int64 val;
                read(&val, sizeof(val));
                return val;
            }

            RMType decode_rmtype() {
                return (RMType)decode_uint8();
            }

            std::vector<uint8> decode_uint8_array() {
                const RMType type = decode_rmtype();
                assert(type == RMType_UInt8);
                const uint32 lenght = decode_uint32();
                uint8 buffer[lenght];
                read(buffer, lenght* sizeof(uint8));

                std::vector<uint8> array;
                array.reserve(lenght);
                array.assign(buffer, buffer+lenght);

                return array;
            }


            uint32 decode_array(uint8 *dst, uint32 size) {
                const RMType type = decode_rmtype();
                assert(type == RMType_UInt8);
                const uint32 lenght = decode_uint32();
                return lenght;
            }



            std::string decode_string() {
                const RMType type = decode_rmtype();
                assert(type == RMType_Int8);
                const uint32 lenght = decode_uint32();
                char buffer[lenght];
                read(buffer, lenght);
                return std::string((const char *)buffer, lenght);
            }

        };
    }
}

#endif //RMPROPELLER_RMDECODER_HPP
