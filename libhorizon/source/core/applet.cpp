#include "horizon/core/applet.hpp"

namespace horizon {
    Applet::Applet() :
         m_running(true),
         m_currentFrame(0) {

         }

    Applet::~Applet() {

    }

    bool Applet::isRunning() {
        if (!appletMainLoop()) return false;

        hidScanInput();
        m_currentFrame++;
        return m_running;
    }

    void Applet::exit() {
        m_running = false;
    }
} /* horizon */
