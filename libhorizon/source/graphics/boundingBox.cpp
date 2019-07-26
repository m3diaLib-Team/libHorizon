#include "horizon/graphics/boundingBox.hpp"

namespace horizon {
    BoundingBox::BoundingBox(int x, int y, int width, int height) :
        m_posX(x),
        m_posY(y),
        m_width(width),
        m_height(height) { /* do nothing */    }

    int BoundingBox::getX() {
        return m_posX;
    }

    int BoundingBox::getY() {
        return m_posY;
    }

    int BoundingBox::getWidth() {
        return m_width;
    }

    int BoundingBox::getHeight() {
        return m_height;
    }

    bool BoundingBox::intersects(horizon::BoundingBox box) {
        if (m_posX < (box.getX() + box.getWidth())
            && (m_posX + m_width) > box.getX()
            && m_posY < (box.getY() + box.getHeight())
            && (m_posY + m_height) > box.getY()) {
                return true;
            }

        return false;
    }
} /* horizon */
