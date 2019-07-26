#include "horizon/graphics/renderTarget.hpp"
#include "horizon/private/opengl.hpp"

namespace horizon {
    RenderTarget::RenderTarget() {
        glGenFramebuffers(1, &m_framebuffer);
    }

    RenderTarget::~RenderTarget() {
        glDeleteFramebuffers(1, &m_framebuffer);
    }

    void RenderTarget::bind() {
        glBindFramebuffer(GL_FRAMEBUFFER, m_framebuffer);
    }
} /* horizon */
