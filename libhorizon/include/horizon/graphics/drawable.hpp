/**
 * @file drawable.hpp
 * @brief Defines the base class for all drawable classes
 */
#ifndef DRAWABLE_H
#define DRAWABLE_H

#pragma once

namespace horizon {
    /**
     * @brief The base class for all drawable classes.
     *
     * To create your own drawable class, create a child class of this one and implement the draw()-method.
     */
    class Drawable {
    public:
        /**
         * @brief Draws the drawable object
         *
         * Implement this function in your own class to draw stuff on the screen using horizon::quickdraw or OpenGL-functions
         */
        virtual void draw() = 0;
    };
} /* horizon */


#endif /* end of include guard: DRAWABLE_H */
