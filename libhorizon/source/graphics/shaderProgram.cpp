#include "horizon/graphics/shaderProgram.hpp"
#include "horizon/graphics/shader.hpp"

#include <stdio.h>

namespace horizon {
    ShaderProgram::ShaderProgram() :
        m_program(0) { /* do nothing */ }

    ShaderProgram::~ShaderProgram() {
        glDeleteProgram(m_program);
    }

    ShaderProgram& ShaderProgram::attach(const horizon::Shader& shader) {
        if (m_program == 0) {
            m_program = glCreateProgram();
            m_created = true;
        }

        glAttachShader(m_program, shader.getID());
        return *this;
    }

    bool ShaderProgram::link() {
        GLint success;
        glGetProgramiv(m_program, GL_LINK_STATUS, &success);

        if (!success) {
            glLinkProgram(m_program);
            glGetProgramiv(m_program, GL_LINK_STATUS, &success);

            if (!success) {
                char buf[512];
                glGetProgramInfoLog(m_program, sizeof(buf), nullptr, buf);
                printf("ShaderProgram: Link error: %s", buf);
                return false;
            }

            return true;
        }

        return false;
    }

    void ShaderProgram::reset() {
        if (m_program != 0) {
            glDeleteProgram(m_program);
            m_program = glCreateProgram();
            m_linked = false;
        }
    }

    void ShaderProgram::use() const {
        GLint success;
        glGetProgramiv(m_program, GL_LINK_STATUS, &success);

        if (success) {
            glUseProgram(m_program);
        }
    }

    const unsigned int ShaderProgram::getID() const {
        return m_program;
    }
} /* horizon */
