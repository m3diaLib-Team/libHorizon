/**
 * @file applet.hpp
 * @brief Defines the applet class (used for running the app)
 */
#pragma once

#ifndef APPLET_H
#define APPLET_H

#include "horizon/libnx.hpp"

/**
 * @brief The general horizon-namespace
 */
namespace horizon {
    /**
     * @brief The applet class (used for running the app)
     */
    class Applet {
    public:

        /**
         * @brief Creates the applet
         * @param enableNxlinkStdio Whether you want to enable nxlinkStdio or not
         */
        Applet(bool enableNxlinkStdio = true);

        /**
         * @brief Destructs the applet
         */
        ~Applet();

        /**
         * @brief Returns if the applet is still running
         */
        bool isRunning();

        /**
         * @brief Exits the applet
         */
        void exit();

        /**
         * @brief Sets whether or not to allow the use of the home button
         * @param allow `true` if the user is allowed to use the home button, `false` otherwise
         */
        static inline void allowHomeButton(bool allow) {
            if (allow) {
                appletEndBlockingHomeButton();
            } else {
                appletBeginBlockingHomeButton(0);
            }
        }

        /**
         * @brief Enables/disables video recording
         * @param enable Whether or not to enable video recording
         */
        static inline void enableVideoRecording(bool enable) {
            if (enable) {
                appletSetGamePlayRecordingState(1);
            } else {
                appletSetGamePlayRecordingState(0);
            }
        }

        /**
         * @brief Returns the current frame
         * @return The currently drawn frame (ranging from 0 to 59)
         */
        int getCurrentFrame();

    private:
        /* data */
        bool m_running;
        int m_currentFrame;
    };
} /* horizon */

#endif /* end of include guard: APPLET_H */
