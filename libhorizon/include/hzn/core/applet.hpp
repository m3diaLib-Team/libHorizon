/**
 * @file applet.hpp
 * @brief Defines the applet class (used for running the app)
 */
#pragma once

#ifndef APPLET_H
#define APPLET_H

#include "hzn/libnx.hpp"

/**
 * @brief The general hzn-namespace
 */
namespace hzn {
   /**
    * @brief The applet class (used for running the app)
    */
   class Applet {
   public:
       /**
        * @brief Defines the ids of various applets
        */
       enum class AppletId {
           None,
       };

       /**
        * @brief Creates the applet
        */
       Applet();

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
        * @brief Returns the current frame
        * @return The currently drawn frame (ranging from 0 to 59)
        */
       int getCurrentFrame();

    private:
       /* data */
       bool m_running;
       int m_currentFrame;

   };
} /* hzn */

#endif /* end of include guard: APPLET_H */
