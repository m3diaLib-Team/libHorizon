/**
 * @file horizon.hpp
 * @brief The master header which includes all other files from the library
 */
#pragma once

#include "horizon/libnx.hpp"

// horizon includes
#include "horizon/core/core.hpp"
#include "horizon/graphics/graphics.hpp"

#ifdef _DOXYGEN_
    /**
     * @def HORIZON_DEBUG
     * @brief If set, this enables NxLink and the HORIZON_DEBUGPOINT and HORIZON_BREAKPOINT macros
     */
    #define HORIZON_DEBUG

     /**
     * @def HORIZON_NO_LIBNX
     * @brief If set, this disables the automatic inclusion of libnx, allowing you to use your own fork instead
     *
     * @note This is useful if you use the horizoniaLib in places where the official libnx doesn't work.
     */
    #define HORIZON_NO_LIBNX

    /**
     * @def HORIZON_BREAKPOINT
     * @brief Pauses the execution and waits for button input
     */
    #define HORIZON_BREAKPOINT()

    /**
     * @def HORIZON_DEBUGPOINT
     * @brief Pauses the execution, displays a message and waits for button input
     * @param msg The message to print
     */
    #define HORIZON_DEBUGPOINT(msg)
#endif
#ifdef HORIZON_DEBUG
    #include <unistd.h>
    #define TRACE(fmt,...) printf("%s: " fmt "\n", __PRETTY_FUNCTION__, ## __VA_ARGS__)

    static void initNxLink() {
        if (R_FAILED(socketInitializeDefault()))
            return;

        horizon::priv::nxlinkSocket = nxlinkStdio();

        if (horizon::priv::nxlinkSocket >= 0)
            TRACE("printf output now goes to nxlink server");
        else
            socketExit();
    }

    static void deinitNxLink() {
        if (horizon::priv::nxlinkSocket >= 0) {
            close(horizon::priv::nxlinkSocket);
            socketExit();
            horizon::priv::nxlinkSocket = -1;
        }
    }

    extern "C" void userAppInit() {
        initNxLink();
    }

    extern "C" void userAppExit() {
        deinitNxLink();
    }
#else
    #define TRACE(fmt,...) ((void)0)
    #define HORIZON_BREAKPOINT()
    #define HORIZON_DEBUGPOINT()
#endif
