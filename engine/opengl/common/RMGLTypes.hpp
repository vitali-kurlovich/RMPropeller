//
// Created by Vitali Kurlovich on 11/2/16.
//

#ifndef RMPROPELLER_RMGLTYPES_HPP
#define RMPROPELLER_RMGLTYPES_HPP

#include <glad/glad.h>

#include "../../common/RMType.hpp"


namespace rmengine {

    namespace graphics {

        constexpr
        GLenum glEnum(RMType type) {

            if (isIntegerType(type)) {
                if (isUnsignedType(type)) {

                    switch (type) {
                        case RMType_UInt8:
                            return GL_UNSIGNED_BYTE;
                        case RMType_UInt16:
                            return GL_UNSIGNED_SHORT;
                        case RMType_UInt32:
                            return GL_UNSIGNED_INT;
                    }
                } else {
                    switch (type) {
                        case RMType_Int8:
                            return GL_BYTE;
                        case RMType_Int16:
                            return GL_SHORT;
                        case RMType_Int32:
                            return GL_INT;
                    }
                }

            } else {
                switch (type) {
                    case RMType_HalfFloat:
                        return GL_HALF_FLOAT;
                    case RMType_Float:
                        return GL_FLOAT;
                }
            }

            return GL_FLOAT;
        }


        constexpr
        GLenum glEnum(RMIntegerType type) {
            if (isUnsignedType(type)) {
                switch (type) {
                    case RMIntegerType_U8:
                        return GL_UNSIGNED_BYTE;
                    case RMIntegerType_U16:
                        return GL_UNSIGNED_SHORT;
                    case RMIntegerType_U32:
                        return GL_UNSIGNED_INT;
                }
            } else {
                switch (type) {
                    case RMIntegerType_8:
                        return GL_BYTE;
                    case RMIntegerType_16:
                        return GL_SHORT;
                    case RMIntegerType_32:
                        return GL_INT;
                }
            }
            return GL_INT;
        }
    }
}


#endif //RMPROPELLER_RMGLTYPES_HPP
