//
// Created by Vitali Kurlovich on 4/21/16.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>

#include <sstream>
#include <sys/stat.h>

#include "engine/common/common.hpp"

#include "engine/opengl/graphics/viewport/RMGLViewport.hpp"
#include "engine/opengl/graphics/procedural/VBOTorus.hpp"
#include "engine/opengl/graphics/procedural/VBOAxis.hpp"

#include "engine/opengl/graphics/material/technique/program/RMGLShader.hpp"
#include "engine/opengl/graphics/material/technique/program/RMGLShaderProgram.hpp"

#include "engine/graphics/camera/RMCamera3dUtils.hpp"
#include "engine/graphics/transform/TTransform3d.hpp"

#include "libs/math/rmvmath/utils/TQuaternionUtils.hpp"

#include "engine/graphics/geometry/mesh/buffer/RMVertexBufferHeader.hpp"

#include "engine/graphics/geometry/mesh/buffer/RMIndexBuffer.hpp"
#include "engine/graphics/geometry/mesh/buffer/RMVertexBuffer.hpp"
#include "engine/graphics/geometry/mesh/buffer/RMVertexBufferObject.hpp"

using namespace rmengine;
using namespace rmengine::graphics;

using std::ifstream;
using std::ofstream;
using std::ios;
using std::ios_base;


// GLAD_DEBUG is only defined if the c-debug generator was used
#ifdef GLAD_DEBUG
// logs every gl call to the console
void pre_gl_call(const char *name, void *funcptr, int len_args, ...) {
   // printf("Calling: %s (%d arguments)\n", name, len_args);
}
#endif



static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main(void)
{

    std::cout <<"sizeof RMVertexAttributeItem: " << sizeof(RMVertexAttributeItem) << std::endl;

    std::cout <<"sizeof RMVertexBufferHeader: " << sizeof(RMVertexBufferHeader) << std::endl;

    std::cout <<"sizeof RMVertexBuffer: " << sizeof(RMVertexBuffer) << std::endl;
    std::cout <<"sizeof RMIndexBuffer: " << sizeof(RMIndexBuffer) << std::endl;

    std::cout <<"sizeof RMVertexBufferObject: " << sizeof(RMVertexBufferObject) << std::endl;


    ofstream ofile("filemap.txt",  ios_base::out | ios_base::trunc | ios_base::binary);


    if (!ofile.is_open()) {
        std::cout << "File can't bee opend\n"; // напечатать соответствующее сообщение
        return 1;
    }

    ofile << std::string("file/texture.png") << " "<< (uint32)666;

    ofile.close();

    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);

#ifdef __APPLE__
    // Select OpenGL 4.1
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 1 );
#else
    // Select OpenGL 4.3
  glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
  glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
#endif

    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);


    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))

    {
       // std::cout << "Failed to initialize OpenGL context" << std::endl;
        return EXIT_FAILURE;
    }

#ifdef GLAD_DEBUG
    // before every opengl call call pre_gl_call
    glad_set_pre_callback(pre_gl_call);

    // post callback checks for glGetError by default

    // don't use the callback for glClear
    // (glClear could be replaced with your own function)
    glad_debug_glClear = glad_glClear;
#endif


    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    vec2 size(width, height);

    RMViewport* viewport = new RMGLViewport(size);
    viewport->setClearColor(rgbaf(0.8f, 0.2f, 0.1f, 1.0f));
    viewport->setNeedClearColor();
    viewport->setNeedClearDepth();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);

    float phase(0);



    static const char *vert =
            "#version 410\n"\
              "layout (location=0) in vec3 VertexPosition;\n"\
              "layout (location=1) in vec3 VertexColor;\n"\
              "\n"\
              "out vec3 Color;\n"\
              "uniform mat4 MVP;\n"\
              "void main()\n"\
              "{\n"\
              "    Color = VertexColor;\n"\
              "    gl_Position =  MVP*vec4(VertexPosition, 1.0);\n"\
              "}";




    auto vertShader = new RMGLShader(vert, RMShader::RMShaderTypeVertex);

    string fileName ("shader/basic.frag");
    ifstream inFileFrag( fileName, std::ios::in );
    if( !inFileFrag ) {
        string message = string("Unable to open: ") + fileName;
        std::cout << message;
        //std << message;
    }

    // Get file contents
    std::stringstream fragCode;
    fragCode << inFileFrag.rdbuf();
    inFileFrag.close();

    auto fragShader = new RMGLShader(fragCode.str().c_str(), RMShader::RMShaderTypeFragment);

    auto program = new RMGLShaderProgram{vertShader, fragShader};

    program->compile();


    VBOTorus torus(0.8f, 0.6f, 50, 50);
    VBOAxis axis;

    viewport->setClearColor(rgbaf(0.2f, 0.2f, 0.2f, 1.0f));

    transform::TTransform3d transform;


    //rotationQuaternion(0.f, vec3(0,0,1));

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);

        vec2 size(width, height);
        viewport->setSize(size);

        phase += 0.01f;


        transform.setRotation( rmmath::utils::rotationQuaternion(phase, vec3(0,1,0)));

        transform.setPosition(vec3(phase*0.221, 0, 0));
        transform.setScale(vec3(std::sin(phase*2)*std::sin(phase*2) + 0.5f,
                                std::sin(phase*2)*std::sin(phase*2) + 0.5f,
                                std::sin(phase*2)*std::sin(phase*2) + 0.5f));

        //viewport->setClearColor(rgbaf(std::sin(phase*2)*std::sin(phase*2),
        //                              std::cos(phase)*std::cos(phase),
        //                              std::sin(phase*5)*std::sin(phase*5), 1.0f));

        viewport->update();


        auto view = cameraLookAt(vec3(0, 0, 10), vec3::zero(), vec3(0,1,0));

        //auto p = cameraOrthoProjection(size*0.002f, 5.f, 10000000.f);

        auto p = cameraPerspectiveProjection(M_PI/2,  (size.y/size.x)*M_PI/2, 1, 100000);
        auto mvp = mat4x4::identity()*transform.getGlobalTransform()*view*p;


        program->setUniform("MVP",mvp);
        program->use();
       torus.render();

        ratio = width / (float) height;

        axis.render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
