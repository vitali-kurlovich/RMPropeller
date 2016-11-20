//
// Created by Vitali Kurlovich on 11/13/16.
//

#ifndef RMPROPELLER_RMMIME_HPP
#define RMPROPELLER_RMMIME_HPP

#include "../../../common/common.hpp"

namespace rmengine {
    namespace mime {

        struct RMMime {
            typedef enum : uint16 {
                text,
                image,
                audio,
                model,
                video,
                application,
                shader
            } RMMimeType;

            typedef enum : uint16 {
                plain, xml,
                gif, jpeg, png, svg, tiff, webp,
                mp4, aac, mpeg, ogg, vorbis, vnd_wave, webm,
                mesh, vbo,
                json, zip, ref, bin,
                glsl, glsl_vert, glsl_frag, glsl_bin
            } RMMimeFormat;

            const RMMimeType type{text};
            const RMMimeFormat format{plain};

            constexpr
            RMMime() {};

            constexpr
            RMMime(RMMimeType mimetype, RMMimeFormat mimeFormat)
                    : type(mimetype), format(mimeFormat) {
            }
        };

        constexpr
        bool operator==(const RMMime &a, const RMMime &b) {
            return a.type == b.type && a.format == b.format;
        }

        constexpr
        bool operator!=(const RMMime &a, const RMMime &b) {
            return !(a == b);
        }
    }
}

#endif //RMPROPELLER_RMMIME_HPP
