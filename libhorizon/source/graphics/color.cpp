#include "horizon/graphics/color.hpp"

namespace horizon {
    Color::Color() :
        m_red(0),
        m_green(0),
        m_blue(0),
        m_alpha(255) { /* do nothing */ }

    Color::Color(short r, short g, short b) :
        m_red(r),
        m_green(g),
        m_blue(b),
        m_alpha(255) { /* do nothing */ }

    Color::Color(short r, short g, short b, short a) :
        m_red(r),
        m_green(g),
        m_blue(b),
        m_alpha(a) { /* do nothing */ }

    Color::Color(short r, short g, short b, float a) :
        m_red(r),
        m_green(g),
        m_blue(b),
        m_alpha(a * 255) { /* do nothing */ }

    void Color::setColor(short r, short g, short b) {
        m_red = r;
        m_green = g;
        m_blue = b;
    }

    void Color::setColor(short r, short g, short b, short a) {
        m_red = r;
        m_green = g;
        m_blue = b;
        m_alpha = a;
    }

    void Color::setColor(short r, short g, short b, float a) {
        m_red = r;
        m_green = g;
        m_blue = b;
        m_alpha = a * 255;
    }

    void Color::setRed(short r) {
        m_red = r;
    }

    short Color::getRed() {
        return m_red;
    }

    void Color::setGreen(short g) {
        m_green = g;
    }

    short Color::getGreen() {
        return m_green;
    }

    void Color::setBlue(short b) {
        m_blue = b;
    }

    short Color::getBlue() {
        return m_blue;
    }

    void Color::setAlpha(short a) {
        m_alpha = a;
    }

    void Color::setAlpha(float a) {
        m_alpha = a * 255;
    }

    short Color::getAlpha() {
        return m_alpha;
    }
} /* horizon */
