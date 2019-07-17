#include "horizon/graphics/vertex.hpp"

namespace horizon {
    Vertex::Vertex() :
         m_position({ 0.f, 0.f, 0.f }),
         m_texCoords({ 0.f, 0.f }),
         m_normals({ 0.f, 0.f, 0.f }),
         m_color(0.f, 0.f, 0.f, 0.f) { /* do nothing */ }

    Vertex::Vertex(float x,
           float y,
           float z,
           float u,
           float v,
           float nx,
           float ny,
           float nz,
           horizon::Color color) :
                m_position({ x, y, z }),
                m_texCoords({ u, v }),
                m_normals({ nx, ny, nz }),
                m_color(color) { /* do nothing */ }

    Vertex::Vertex(horizon::Vector3f position,
           horizon::Vector2f texCoords,
           horizon::Vector3f normals,
           horizon::Color color) :
                m_position(position),
                m_texCoords(texCoords),
                m_normals(normals),
                m_color(color) { /* do nothing */ }

    void Vertex::setPosition(float x, float y, float z) {
        m_position = { x, y, z };
    }

    void Vertex::setPosition(Vector3f position) {
        m_position = position;
    }

    horizon::Vector3f Vertex::getPosition() {
        return m_position;
    }

    void Vertex::setTexCoords(float u, float v) {
        m_texCoords = { u, v };
    }

    void Vertex::setTexCoords(Vector2f texCoords) {
        m_texCoords = texCoords;
    }

    horizon::Vector2f Vertex::getTexCoords() {
        return m_texCoords;
    }

    void Vertex::setNormals(float nx, float ny, float nz) {
        m_normals = { nx, ny, nz };
    }

    void Vertex::setNormals(Vector3f normals) {
        m_normals = normals;
    }

    horizon::Vector3f Vertex::getNormals() {
        return m_normals;
    }

    void Vertex::setColor(horizon::Color color) {
        m_color = color;
    }

    horizon::Color Vertex::getColor() {
        return m_color;
    }
} /* horizon */
