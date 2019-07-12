/**
 * @file color.hpp
 * @brief Defines the color class
 */
#ifndef COLOR_HPP
#define COLOR_HPP

#pragma once

namespace horizon {
    /**
     * @brief The color class
     */
    class Color {
    public:
        /**
         * @brief Creates a color using an opaque black as the default color
         */
        Color();

        /**
         * @brief Creates a color using a red, green and blue value
         * @param r The red value (0.0-1.0)
         * @param g The green value (0.0-1.0)
         * @param b The blue value (0.0-1.0)
         */
        Color(float r, float g, float b);

        /**
         * @brief Creates a color using a red, green, blue and alpha value
         * @param r The red value (0.0-1.0)
         * @param g The green value (0.0-1.0)
         * @param b The blue value (0.0-1.0)
         * @param a The alpha value (0.0-1.0)
         */
        Color(float r, float g, float b, float a);

        /**
         * @brief Sets the red, green and blue value of the color
         * @param r The red value (0.0-1.0)
         * @param g The green value (0.0-1.0)
         * @param b The blue value (0.0-1.0)
         */
        void setColor(float r, float g, float b);

        /**
         * @brief Sets the red, green, blue and alpha value of the color
         * @param r The red value (0.0-1.0)
         * @param g The green value (0.0-1.0)
         * @param b The blue value (0.0-1.0)
         * @param a The alpha value (0.0-1.0)
         */
        void setColor(float r, float g, float b, float a);

        /**
         * @brief Sets the red value of the color
         * @param r The red value (0.0-1.0)
         */
        void setRed(float r);

        /**
         * @brief Returns the red value of the color
         * @return The red value (0.0-1.0)
         */
        float getRed();

        /**
         * @brief Sets the green value of the color
         * @param g The green value (0.0-1.0)
         */
        void setGreen(float g);

        /**
         * @brief Returns the green value of the color
         * @return The green value (0.0-1.0)
         */
        float getGreen();

        /**
         * @brief Sets the blue value of the color
         * @param b The blue value (0.0-1.0)
         */
        void setBlue(float b);

        /**
         * @brief Returns the blue value of the color
         * @return The blue value (0.0-1.0)
         */
        float getBlue();

        /**
         * @brief Sets the alpha value of the color
         * @param a The alpha value (0.0-1.0)
         */
        void setAlpha(float a);

        /**
         * @brief Returns the alpha value of the color
         * @return The alpha value (0.0-1.0)
         */
        float getAlpha();

    private:
        /* data */
        float m_red, m_green, m_blue, m_alpha;
    };
} /* horizon */


#endif /* end of include guard: COLOR_HPP */
