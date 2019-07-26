/**
 * @file renderTarget.hpp
 * @brief Defines the rendertarget class
 */
#ifndef RENDERTARGET_HPP
#define RENDERTARGET_HPP

#pragma once

namespace horizon {
    /**
     * @brief Can be used to render something without directly displaying it on screen
     */
    class RenderTarget {
    public:
        /**
         * @brief Creates the rendertarget
         */
        RenderTarget();

        /**
         * @brief Destructs the rendertarget
         */
        ~RenderTarget();

        /**
         * @brief Binds the rendertarget
         *
         * This causes all rendering to be redirected to this rendertarget
         */
        void bind();

    private:
        /* data */
        unsigned int m_framebuffer;
    };
} /* horizon */


#endif /* end of include guard: RENDERTARGET_HPP */
