//
// Created by Vitali Kurlovich on 11/19/16.
//

#ifndef RMPROPELLER_RMCODER_HPP
#define RMPROPELLER_RMCODER_HPP

#include "../../common/common.hpp"

#include <string>
#include "../buffer/RMIOBuffer.hpp"

namespace rmengine {

    namespace serialize {

        class RMCoder {
            buffer::RMIOWriteBuffer* _writeBuffer{nullptr};
        public:

            RMCoder(buffer::RMIOWriteBuffer* writeBuffer)
                    : _writeBuffer(writeBuffer) {
                        assert(_writeBuffer != nullptr);
                       rmRetain(_writeBuffer);
                    }

            ~RMCoder() {
                rmRelease(_writeBuffer);
            }

            void encode(const uint8 val) {
                const uint8 buffer(val);
                _writeBuffer->write(&buffer, sizeof(val));
            }

            void encode(const int8 val) {
                const int8 buffer(val);
                _writeBuffer->write(&buffer, sizeof(val));
            }

            void encode(const uint16 val) {
                const uint16 buffer(val);
                _writeBuffer->write(&buffer, sizeof(val));
            }

            void encode(const int16 val) {
                const int16 buffer(val);
                _writeBuffer->write(&buffer, sizeof(val));
            }

            void encode(const uint32 val) {
                const uint32 buffer(val);
                _writeBuffer->write(&buffer, sizeof(val));
            }

            void encode(const int32 val) {
                const int32 buffer(val);
                _writeBuffer->write(&buffer, sizeof(val));
            }

            void encode(const uint64 val) {
                const uint64 buffer(val);
                _writeBuffer->write(&buffer, sizeof(val));
            }

            void encode(const int64 val) {
                const int64 buffer(val);
                _writeBuffer->write(&buffer, sizeof(val));
            }

            void encode(const float val) {
                const float buffer(val);
                _writeBuffer->write(&buffer, sizeof(val));
            }

            void encode(const double val) {
                const double buffer(val);
                _writeBuffer->write(&buffer, sizeof(val));
            }

            void encode(const std::string &str) {
                //const double buffer(val);
                _writeBuffer->write(str.data(), str.length()*sizeof(char));
            }

        };
    }
}


#endif //RMPROPELLER_RMCODER_HPP
