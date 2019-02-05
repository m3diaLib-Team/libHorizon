/**
 * @file m3dia.hpp
 * @brief The master header which includes all other files from the library
 */
#pragma once

// m3Dia includes

/**
 * @def M3D_DEBUG
 * @brief Enables NxLink and the M3D_DEBUGPOINT and M3D_BREAKPOINT macros
 */

#ifdef M3D_DEBUG
    #include <unistd.h>
    #define TRACE(fmt,...) printf("%s: " fmt "\n", __PRETTY_FUNCTION__, ## __VA_ARGS__)

    static void initNxLink() {
        if (R_FAILED(socketInitializeDefault()))
            return;

        m3d::priv::nxlinkSocket = nxlinkStdio();

        if (m3d::priv::nxlinkSocket >= 0)
            TRACE("printf output now goes to nxlink server");
        else
            socketExit();
    }

    static void deinitNxLink() {
        if (m3d::priv::nxlinkSocket >= 0) {
            close(m3d::priv::nxlinkSocket);
            socketExit();
            m3d::priv::nxlinkSocket = -1;
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
    #define M3D_BREAKPOINT()
    #define M3D_DEBUGPOINT()
#endif
