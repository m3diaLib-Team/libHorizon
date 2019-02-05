/**
 * @file m3dia.hpp
 * @brief The master header which includes all other files from the library
 */
#pragma once

// m3Dia includes

#ifdef _DOXYGEN_
    /**
     * @def M3D_DEBUG
     * @brief If set, this enables NxLink and the M3D_DEBUGPOINT and M3D_BREAKPOINT macros
     */
    #define M3D_DEBUG

     /**
     * @def M3D_NO_LIBNX
     * @brief If set, this disables the automatic inclusion of libnx, allowing you to use your own fork instead
     *
     * @note This is useful if you use the m3diaLib in places where the official libnx doesn't work.
     */
    #define M3D_NO_LIBNX

    /**
     * @def M3D_BREAKPOINT
     * @brief Pauses the execution and waits for button input
     */
    #define M3D_BREAKPOINT()

    /**
     * @def M3D_DEBUGPOINT
     * @brief Pauses the execution, displays a message and waits for button input
     * @param msg The message to print
     */
    #define M3D_DEBUGPOINT(msg)
#endif
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
