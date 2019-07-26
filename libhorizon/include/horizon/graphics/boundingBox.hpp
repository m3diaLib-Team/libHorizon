/**
 * @file boundingBox.hpp
 * @brief Defines the BoundingBox class
 */
#ifndef BOUNDING_BOX
#define BOUNDING_BOX

#pragma once

namespace horizon {
    /**
     * @brief A 2D bounding-box
     */
    class BoundingBox {
    public:
        /**
         * @brief Initializes the bounding box
         * @param x      The x position
         * @param y      The y position
         * @param width  The width
         * @param height The height
         */
        BoundingBox(int x, int y, int width, int height);

        /**
         * @brief Returns the x position of the bounding box
         * @return The x position
         */
        int getX();

        /**
         * @brief Returns the y position of the bounding box
         * @return The y position
         */
        int getY();

        /**
         * @brief Returns the width of the bounding box
         * @return The width
         */
        int getWidth();

        /**
         * @brief Returns the height of the bounding box
         * @return The height
         */
        int getHeight();

        /**
         * @brief Checks whether two BoundingBoxes intersect
         * @param  box The BoundingBox to compare with
         * @return     Whether or not the two boxes interect
         */
        bool intersects(horizon::BoundingBox box);

    private:
        /* data */
        int m_posX, m_posY, m_width, m_height;

    };
} /* horizon */

#endif /* end of include guard: BOUNDING_BOX */
