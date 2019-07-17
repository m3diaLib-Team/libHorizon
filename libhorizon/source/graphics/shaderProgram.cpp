#include "horizon/graphics/shaderProgram.hpp"
#include "horizon/graphics/shader.hpp"

#include <stdio.h>

namespace horizon {
    ShaderProgram::ShaderProgram(const std::string& name) :
        m_name(name) {
        m_program = glCreateProgram();

        if (name != "") {
            // TODO: Add program to shader manager
        }
    }

    ShaderProgram::~ShaderProgram() {
        glDeleteProgram(m_program);
    }

    const std::string ShaderProgram::getName() {
        return m_name;
    }

    void ShaderProgram::attach(const horizon::Shader& shader) {
        glAttachShader(m_program, shader.getShader());
    }

    bool ShaderProgram::link() {
        glLinkProgram(m_program);

        GLint success;
        glGetProgramiv(m_program, GL_LINK_STATUS, &success);

        if (!success) {
            char buf[512];
            glGetProgramInfoLog(m_program, sizeof(buf), nullptr, buf);
            printf("ShaderProgram: Link error: %s", buf);
            return false;
        }

        return true;
    }

    void ShaderProgram::reset() {
        glDeleteProgram(m_program);
        m_program = glCreateProgram();
    }

    void ShaderProgram::use() const {
        glUseProgram(m_program);
    }
} /* horizon */
