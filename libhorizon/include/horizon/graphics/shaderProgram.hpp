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
     *
     * In order to load and switch between shader-programs easier, please refer to horizon::ShaderManager.
     */
    class ShaderProgram {
    public:
        /*
         * @brief Constructs the shader program
         * @param name The name of the program, for the shader manager. See horizon::ShaderManager for more information
         *
         * Leave `name` blank if you don't want to add the program to the shader manager.
         */
        explicit ShaderProgram(const std::string& name = "");

        /**
         * @brief Destructs the shader program
         */
        ~ShaderProgram();

        /**
         * @brief Returns the name of the program
         * @return The name
         *
         * For more information, please refer to horizon::ShaderManager.
         */
        const std::string getName();

        /**
         * @brief Attaches the given shader to the program
         * @param shader The shader to attach
         */
        void attach(const horizon::Shader& shader);

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

    private:
        /* data */
        std::string m_name;
        GLuint m_program;
    };
} /* horizon */


#endif /* end of include guard: SHADERPROGRAM_HPP */
