/**
 * @file vertex.hpp
 * @brief Defines the vertex class
 */
#ifndef VERTEX_HPP
#define VERTEX_HPP

#pragma once

#include "color.hpp"

namespace horizon {
    /**
     * @brief Represents a vector of 2 floats
     */
    struct Vector2f {
        float u; ///< The first component
        float v; ///< The second component
    };

    /**
     * @brief Represents a vector of 3 floats
     */
    struct Vector3f {
        float x; ///< The first component
        float y; ///< The second component
        float z; ///< The third component
    };

    /**
     * @brief Represents a vector of 2 doubles
     */
    struct Vector2d {
        double u; ///< The first component
        double v; ///< The second component
    };

    /**
     * @brief Represents a vector of 3 doubles
     */
    struct Vector3d {
        double x; ///< The first component
        double y; ///< The second component
        double z; ///< The third component
    };

    /**
     * @brief Represents a vector of 2 ints
     */
    struct Vector2i {
        int u; ///< The first component
        int v; ///< The second component
    };

    /**
     * @brief Represents a vector of 3 ints
     */
    struct Vector3i {
        int x; ///< The first component
        int y; ///< The second component
        int z; ///< The third component
    };

    /**
     * @brief Represents a GPU vertex
     */
    class Vertex {
    public:
        /**
         * @brief Default constructor
         */
        Vertex();

        /**
         * @brief Creates the vertex with the given values
         * @param x     The x-position
         * @param y     The y-position
         * @param z     The z-position
         * @param u     The u texture-coordinate
         * @param v     The v texture-coordinate
         * @param nx    The x-normal
         * @param ny    The y-normal
         * @param nz    The z-normal
         * @param color The color
         */
        Vertex(float x,
               float y,
               float z,
               float u = 0.f,
               float v = 0.f,
               float nx = 0.f,
               float ny = 0.f,
               float nz = 0.f,
               horizon::Color color = horizon::Color());

        /**
         * @brief Creates the vertex with the given values
         * @param position  The position
         * @param texCoords The texture coordinates
         * @param normals   The normals
         * @param color     The color
         */
        Vertex(horizon::Vector3f position,
               horizon::Vector2f texCoords = { 0.f, 0.f },
               horizon::Vector3f normals = { 0.f, 0.f, 0.f },
               horizon::Color color = horizon::Color());

        /**
         * @brief Sets the position of the vertex
         * @param x The x-position
         * @param y The y-position
         * @param z The z-position
         */
        void setPosition(float x, float y, float z);

        /**
         * @brief Sets the position of the vertex
         * @param position The position
         */
        void setPosition(Vector3f position);

        /**
         * @brief Returns the position of the vertex
         * @return The position
         */
        horizon::Vector3f getPosition();

        /**
         * @brief Sets the texture-coordinates of the vertex
         * @param u The u texture-coordinate
         * @param v The v texture-coordinate
         */
        void setTexCoords(float u, float v);

        /**
         * @brief Sets the texture-coordinates of the vertex
         * @param texCoords The texture-coordinates
         */
        void setTexCoords(Vector2f texCoords);

        /**
         * @brief Returns the texture coordinates of the vertex
         * @return The texture coordinates
         */
        horizon::Vector2f getTexCoords();

        /**
         * @brief Sets the normals of the vertex
         * @param nx The x-normal
         * @param ny The y-normal
         * @param nz The z-normal
         */
        void setNormals(float nx, float ny, float nz);

        /**
         * @brief Sets the normals of the vertex
         * @param normals The normals
         */
        void setNormals(Vector3f normals);

        /**
         * @brief Returns the normals of the vertex
         * @return The normals
         */
        horizon::Vector3f getNormals();

        /**
         * @brief Sets the color of the vertex
         * @param color The color
         */
        void setColor(horizon::Color color);

        /**
         * @brief Returns the color of the vertex
         * @return The color
         */
        horizon::Color getColor();

    private:
        /* data */
        horizon::Vector3f m_position;
        horizon::Vector2f m_texCoords;
        horizon::Vector3f m_normals;
        horizon::Color m_color;
    };
} /* horizon */


#endif /* end of include guard: VERTEX_HPP */
