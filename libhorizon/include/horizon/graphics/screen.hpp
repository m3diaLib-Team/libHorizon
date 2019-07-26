/**
 * @file screen.hpp
 * @brief Defines the screen class
 */
#ifndef SCREEN_HPP
#define SCREEN_HPP

#pragma once

#include <EGL/egl.h>
#include "color.hpp"

namespace horizon {
    /**
     * @brief Used for rendering stuff on the Switch's main screen
     */
    class Screen {
    public:
        /**
         * @brief Creates the screen
         */
        Screen();

        /**
         * @brief Destructs the screen
         */
        ~Screen();

        /**
         * @brief Renders the current screen
         * @param clear Whether or not to clear the screen between frames
         */
        void render(bool clear = true);

        /**
         * @brief Sets the clear color
         * @param color The clear color of the screen
         */
        void setClearColor(horizon::Color color);

        /**
         * @brief Returns the currently set clear color
         * @return The clear color of the screen
         */
        horizon::Color getClearColor();

    private:
        /* data */
        static EGLDisplay m_display;
        static EGLContext m_context;
        static EGLSurface m_surface;

        static horizon::Color m_clearColor;
    };
} /* horizon */


#endif /* end of include guard: SCREEN_HPP */
