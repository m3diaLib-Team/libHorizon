/**
 * @file shaderProgram.hpp
 * @brief Defines the shader-program class
 */
#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP

#pragma once

#include <glad/glad.h>
#include <string>

namespace horizon {
    class Shader;

    /**
     * @brief Combines multiple different shaders in order to use them in union
     */
    class ShaderProgram {
    public:
        /*
         * @brief Constructs the shader program
         */
        ShaderProgram();

        /**
         * @brief Destructs the shader program
         */
        ~ShaderProgram();

        /**
         * @brief Attaches the given shader to the program
         * @param shader The shader to attach
         * @return       This shader-program, in order to easily attach multiple shaders
         */
        ShaderProgram& attach(const horizon::Shader& shader);

        /**
         * @brief Links the shader program
         * @return       Whether the linking was successful
         * @retval true  The program was successfully linked
         * @retval false The linking of the program resulted in an error
         */
        bool link();

        /**
         * @brief Resets the program ("un-attaches" all shaders)
         */
        void reset();

        /**
         * @brief Uses the shader program
         */
        void use() const;

        /**
         * @brief Returns the ID of the OpenGL-program
         * @return The ID
         */
        const unsigned int getID() const;

    private:
        /* data */
        bool m_created, m_linked;
        std::string m_name;
        unsigned int m_program;
    };
} /* horizon */


#endif /* end of include guard: SHADERPROGRAM_HPP */
