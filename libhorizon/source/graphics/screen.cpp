#include "horizon/graphics/screen.hpp"

#include <stdio.h>
#include <switch.h>

#include <EGL/eglext.h>
#include <glad/glad.h>

EGLDisplay horizon::Screen::m_display;
EGLContext horizon::Screen::m_context;
EGLSurface horizon::Screen::m_surface;
horizon::Color horizon::Screen::m_clearColor;

namespace horizon {
    Screen::Screen() {
        // Connect to the EGL default display
        m_display = eglGetDisplay(EGL_DEFAULT_DISPLAY);

        if (!m_display) {
            printf("EGL: Could not connect to display! error: %d", eglGetError());
            return;
        }

        // Initialize the EGL display connection
        eglInitialize(m_display, nullptr, nullptr);

        // Select OpenGL (Core) as the desired graphics API
        if (eglBindAPI(EGL_OPENGL_API) == EGL_FALSE) {
            printf("EGL: Could not set OpenGL-API! error: %d", eglGetError());
            eglTerminate(m_display);
            m_display = nullptr;
            return;
        }

        // Get an appropriate EGL framebuffer configuration
        EGLConfig config;
        EGLint numConfigs;

        static const EGLint framebufferAttributeList[] = {
            EGL_RENDERABLE_TYPE, EGL_OPENGL_BIT,
            EGL_RED_SIZE,     8,
            EGL_GREEN_SIZE,   8,
            EGL_BLUE_SIZE,    8,
            EGL_ALPHA_SIZE,   8,
            EGL_DEPTH_SIZE,   24,
            EGL_STENCIL_SIZE, 8,
            EGL_NONE
        };

        eglChooseConfig(m_display, framebufferAttributeList, &config, 1, &numConfigs);

        if (numConfigs == 0) {
            printf("EGL: No config found! error: %d", eglGetError());
            eglTerminate(m_display);
            m_display = nullptr;
            return;
        }

        // Create an EGL window surface
        m_surface = eglCreateWindowSurface(m_display, config, nwindowGetDefault(), nullptr);

        if (!m_surface) {
            printf("EGL: Surface creation failed! error: %d", eglGetError());
            eglTerminate(m_display);
            m_display = nullptr;
            return;
        }

        // Create an EGL rendering context
        static const EGLint contextAttributeList[] = {
            EGL_CONTEXT_OPENGL_PROFILE_MASK_KHR, EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT_KHR,
            EGL_CONTEXT_MAJOR_VERSION_KHR, 4,
            EGL_CONTEXT_MINOR_VERSION_KHR, 3,
            EGL_NONE
        };

        m_context = eglCreateContext(m_display, config, EGL_NO_CONTEXT, contextAttributeList);

        if (!m_context) {
            printf("EGL: Context creation failed! error: %d", eglGetError());
            eglDestroySurface(m_display, m_surface);
            m_surface = nullptr;
            eglTerminate(m_display);
            m_display = nullptr;
            return;
        }

        // Connect the context to the surface
        eglMakeCurrent(m_display, m_surface, m_surface, m_context);
        gladLoadGL();
    }

    Screen::~Screen() {
        if (m_display) {
            eglMakeCurrent(m_display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);

            if (m_context) {
                eglDestroyContext(m_display, m_context);
                m_context = nullptr;
            }

            if (m_surface) {
                eglDestroySurface(m_display, m_surface);
                m_surface = nullptr;
            }

            eglTerminate(m_display);
            m_display = nullptr;
        }
    }

    void Screen::render(bool clear) {
        if (clear) {
            glClear(GL_COLOR_BUFFER_BIT);
        }

        eglSwapBuffers(m_display, m_surface);
    }

    void Screen::setClearColor(horizon::Color color) {
        m_clearColor = color;
        glClearColor(color.getRed(), color.getGreen(), color.getBlue(), 1.0f);
    }

    horizon::Color Screen::getClearColor() {
        return m_clearColor;
    }
} /* horizon */
