#include "horizon/graphics/color.hpp"

namespace horizon {
    Color::Color() :
        m_red(0.f),
        m_green(0.f),
        m_blue(0.f),
        m_alpha(1.f) { /* do nothing */ }

    Color::Color(float r, float g, float b) :
        m_red(r),
        m_green(g),
        m_blue(b),
        m_alpha(1.f) { /* do nothing */ }

    Color::Color(float r, float g, float b, float a) :
        m_red(r),
        m_green(g),
        m_blue(b),
        m_alpha(a) { /* do nothing */ }

    void Color::setColor(float r, float g, float b) {
        m_red = r;
        m_green = g;
        m_blue = b;
    }

    void Color::setColor(float r, float g, float b, float a) {
        m_red = r;
        m_green = g;
        m_blue = b;
        m_alpha = a;
    }

    void Color::setRed(float r) {
        m_red = r;
    }

    float Color::getRed() {
        return m_red;
    }

    void Color::setGreen(float g) {
        m_green = g;
    }

    float Color::getGreen() {
        return m_green;
    }

    void Color::setBlue(float b) {
        m_blue = b;
    }

    float Color::getBlue() {
        return m_blue;
    }

    void Color::setAlpha(float a) {
        m_alpha = a;
    }

    float Color::getAlpha() {
        return m_alpha;
    }
} /* horizon */
