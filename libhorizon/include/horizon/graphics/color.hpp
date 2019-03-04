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
         * @param r The red value
         * @param g The green value
         * @param b The blue value
         */
        Color(short r, short g, short b);

        /**
         * @brief Creates a color using a red, green, blue and alpha value
         * @param r The red value
         * @param g The green value
         * @param b The blue value
         * @param a The alpha value
         */
        Color(short r, short g, short b, short a);

        /**
         * @brief Creates a color using a red, green, blue and alpha value
         * @param r The red value
         * @param g The green value
         * @param b The blue value
         * @param a The alpha value (0.0-1.0)
         */
        Color(short r, short g, short b, float a);

        /**
         * @brief Sets the red, green and blue value of the color
         * @param r The red value
         * @param g The green value
         * @param b The blue value
         */
        void setColor(short r, short g, short b);

        /**
         * @brief Sets the red, green, blue and alpha value of the color
         * @param r The red value
         * @param g The green value
         * @param b The blue value
         * @param a The alpha value
         */
        void setColor(short r, short g, short b, short a);

        /**
         * @brief Sets the red, green, blue and alpha value of the color
         * @param r The red value
         * @param g The green value
         * @param b The blue value
         * @param a The alpha value (0.0-1.0)
         */
        void setColor(short r, short g, short b, float a);

        /**
         * @brief Sets the red value of the color
         * @param r The red value
         */
        void setRed(short r);

        /**
         * @brief Returns the red value of the color
         * @return The red value
         */
        short getRed();

        /**
         * @brief Sets the green value of the color
         * @param g The green value
         */
        void setGreen(short g);

        /**
         * @brief Returns the green value of the color
         * @return The green value
         */
        short getGreen();

        /**
         * @brief Sets the blue value of the color
         * @param b The blue value
         */
        void setBlue(short b);

        /**
         * @brief Returns the blue value of the color
         * @return The blue value
         */
        short getBlue();

        /**
         * @brief Sets the alpha value of the color
         * @param a The alpha value
         */
        void setAlpha(short a);

        /**
         * @brief Sets the alpha value of the color
         * @param a The alpha value (0.0-1.0)
         */
        void setAlpha(float a);

        /**
         * @brief Returns the alpha value of the color
         * @return The alpha value
         */
        short getAlpha();

    private:
        /* data */
        short m_red, m_green, m_blue, m_alpha;
    };
} /* horizon */


#endif /* end of include guard: COLOR_HPP */
