/**
 * @file shaderManager.hpp
 * @brief Defines the shader-manager class
 */
#ifndef SHADERMANAGER_HPP
#define SHADERMANAGER_HPP

#pragma once

#include <map>

namespace horizon {
    class ShaderProgram;

    /**
     * @brief Automatically contains all shader-programs with a name, in order to easily switch between them
     */
    class ShaderManager {
    public:
        /**
         * @brief Destructs the manager
         */
        ~ShaderManager();

        /**
         * @brief Adds a shader-program to the manager
         * @param program The shader-program
         */
        static void add(horizon::ShaderProgram program);

        /**
         * @brief Removes a shader-program from the manager by name
         * @param name The name of the program
         */
        static void remove(const std::string& name);

        /**
         * @brief Returns a shader-program by name
         * @param  name The name of the program
         * @return      The shader-program
         */
        static const horizon::ShaderProgram& get(const std::string& name);

        /**
         * @brief Uses a shader-program by name
         * @param name The name of the program
         */
        static void use(const std::string& name);

    private:
        /* data */
        static std::map<const std::string, const horizon::ShaderProgram> m_programStack;
    };
} /* horizon */


#endif /* end of include guard: SHADERMANAGER_HPP */
