/**
 * @file shader.hpp
 * @brief Defines the shader class
 */
#ifndef SHADER_HPP
#define SHADER_HPP

#pragma once

#include <glad/glad.h>
#include <string>

namespace horizon {
    /**
     * @brief A single OpenGL shader
     */
    class Shader {
    friend class ShaderManager;
    public:
        enum class Type {
            Vertex,
            TesselationControl,
            TesselationEvaluation,
            Geometry,
            Fragment,
            Compute
        };

        /**
         * @brief Destructs the shader
         */
        ~Shader();

        /**
         * @brief Compiles a shader from the given source code
         * @param source The shader source code
         * @param type   The shader type.
         * @return       Whether the compilation of the shader was successful
         * @retval true  The shader was successfully compiled
         * @retval false The compilation of the shader resulted in an error
         */
        bool compile(const std::string& source, horizon::Shader::Type type);

        /**
         * @brief Loads a shader from a given file path
         * @param filepath The path of the shader source code
         * @param type     The shader type
         * @return         Whether the loading of the shader was successful
         * @retval true    The shader was successfully loaded and compiled
         * @retval false   The compilation of the shader resulted in an error
         */
        bool load(const std::string& filepath, horizon::Shader::Type type);

        /**
         * @brief Returns the type of the shader
         * @return The shader type
         */
        horizon::Shader::Type getType();

        /**
         * @brief Returns the shader ready to be used with OpenGL
         * @return The shader
         */
        GLint getShader();

        /**
         * @brief Converts a horizon::Shader::Type to an OpenGL shader type
         * @param  type The type to convert
         * @return      The converted type
         */
        GLenum typeToGL(horizon::Shader::Type type) const;

    private:
        /* data */
        horizon::Shader::Type m_type;
        GLint m_shader;
    };
} /* horizon */


#endif /* end of include guard: SHADER_HPP */
