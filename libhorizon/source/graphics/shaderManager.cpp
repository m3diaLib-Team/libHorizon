#include "horizon/graphics/shaderManager.hpp"
#include "horizon/graphics/shaderProgram.hpp"

#include <stdio.h>

namespace horizon {
    void ShaderManager::add(horizon::ShaderProgram program) {
        m_programStack.insert(std::pair<const std::string&, const horizon::ShaderProgram&>(program.getName(), program));
    }

    void ShaderManager::remove(const std::string& name) {
        std::map<const std::string, const horizon::ShaderProgram>::iterator it;
        it = m_programStack.find(name);
        m_programStack.erase(it);
    }

    const horizon::ShaderProgram& ShaderManager::get(const std::string& name) {
        return m_programStack.find(name)->second;
    }

    void ShaderManager::use(const std::string& name) {
        get(name).use();
    }
} /* horizon */
