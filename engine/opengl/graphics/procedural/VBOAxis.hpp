//
// Created by Vitali Kurlovich on 8/27/16.
//

#ifndef RMPROPELLER_VBOAXIS_HPP
#define RMPROPELLER_VBOAXIS_HPP

#include "../../opengl_common.hpp"


namespace rmengine {

    namespace graphics {

        class VBOAxis {


        private:
            unsigned int vaoHandle;

            static const vec3 axis[];
            static const vec3 axisColor[];
            static const uint8 axisIndexes[];

        public:


            VBOAxis() {
                unsigned int handle[3];
                glGenBuffers(3, handle);

                glBindBuffer(GL_ARRAY_BUFFER, handle[0]);
                glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(vec3), axis, GL_STATIC_DRAW);

                glBindBuffer(GL_ARRAY_BUFFER, handle[1]);
                glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(vec3), axisColor, GL_STATIC_DRAW);

                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handle[2]);
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(uint8), axisIndexes, GL_STATIC_DRAW);


                // Create the VAO
                glGenVertexArrays( 1, &vaoHandle );
                glBindVertexArray(vaoHandle);

                glEnableVertexAttribArray(0);  // Vertex position
                glBindBuffer(GL_ARRAY_BUFFER, handle[0]);
                glVertexAttribPointer( (GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, ((GLubyte *)NULL + (0)) );

                glEnableVertexAttribArray(1);  // Vertex normal
                glBindBuffer(GL_ARRAY_BUFFER, handle[1]);
                glVertexAttribPointer( (GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, ((GLubyte *)NULL + (0)) );

                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handle[2]);

                glBindVertexArray(0);

            }

            void render() const {
                glBindVertexArray(vaoHandle);
                glLineWidth(32);
                glDrawElements(GL_LINES, 6, GL_UNSIGNED_BYTE, ((GLubyte *)NULL + (0)));
            }

        };


        const vec3 VBOAxis::axis[] {
                vec3(0.f, 0.f, 0.f),
                vec3(1.f, 0.f, 0.f),

                vec3(0.f, 0.f, 0.f),
                vec3(0.f, 1.f, 0.f),

                vec3(0.f, 0.f, 0.f),
                vec3(0.f, 0.f, 1.f)
        };

        const  vec3 VBOAxis::axisColor[] {
                vec3(1.f, 0.f, 0.f),
                vec3(1.f, 0.f, 0.f),

                vec3(0.f, 1.f, 0.f),
                vec3(0.f, 1.f, 0.f),

                vec3(0.f, 0.f, 1.f),
                vec3(0.f, 0.f, 1.f)
        };

        const uint8 VBOAxis::axisIndexes[]{
                0,1,
                2,3,
                4,5
        };

    }
}

#endif //RMPROPELLER_VBOAXIS_HPP
