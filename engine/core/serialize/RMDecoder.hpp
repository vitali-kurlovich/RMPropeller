//
// Created by Vitali Kurlovich on 11/19/16.
//

#ifndef RMPROPELLER_RMDECODER_HPP
#define RMPROPELLER_RMDECODER_HPP



#include "../../common/common.hpp"

#include <../buffer/RMIOBuffer.hpp>

namespace rmengine {

    namespace serialize {

        class RMDecoder {
            buffer::RMIOReadBuffer* _readBuffer{nullptr};
        public:

            RMDecoder(buffer::RMIOReadBuffer* readBuffer)
                    : _readBuffer(readBuffer) {
                assert(_readBuffer != nullptr);
                rmRetain(_readBuffer);
            }

            ~RMCoder() {
                rmRelease(_readBuffer);
            }

            uint8 decode_uint8() {
                 uint8 val;
                _readBuffer->read(&val, sizeof(val));
                return val;
            }
        };
    }
}

#endif //RMPROPELLER_RMDECODER_HPP
