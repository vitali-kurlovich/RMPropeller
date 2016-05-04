//
// Created by Vitali Kurlovich on 5/3/16.
//

#ifndef RMPROPELLER_RMIMAGE_HPP
#define RMPROPELLER_RMIMAGE_HPP

#include "common/common.hpp"


namespace rmengine {

    namespace graphics {


        typedef enum : uint8 {
            RMImageFormat_ColorIndex = 0,
            RMImageFormat_Red        = 1,
            RMImageFormat_Green      = 2,
            RMImageFormat_Blue       = 3,
            RMImageFormat_Alpha      = 4,
            RMImageFormat_RGB        = 5,
            RMImageFormat_BGR        = 6,
            RMImageFormat_RGBA       = 7,
            RMImageFormat_BGRA       = 8,
            RMImageFormat_Luminance  = 9,
            RMImageFormat_LuminanceAlpha = 10
        } RMImageFormat;

        class RMImage {

        protected:
            uint16 _width:12;
            uint16 _height:12;

            RMImageFormat _format:4;



        public:



            const RMImageFormat getFormat() const {
                return _format;
            }


        };
    }
}


#endif //RMPROPELLER_RMIMAGE_HPP
