/**
 * @file horizon.hpp
 * @brief The master header which includes all other files from the library
 */
#pragma once

// horizon includes

#ifdef _DOXYGEN_
    /**
     * @def HZN_DEBUG
     * @brief If set, this enables NxLink and the HZN_DEBUGPOINT and HZN_BREAKPOINT macros
     */
    #define HZN_DEBUG

     /**
     * @def HZN_NO_LIBNX
     * @brief If set, this disables the automatic inclusion of libnx, allowing you to use your own fork instead
     *
     * @note This is useful if you use the hzniaLib in places where the official libnx doesn't work.
     */
    #define HZN_NO_LIBNX

    /**
     * @def HZN_BREAKPOINT
     * @brief Pauses the execution and waits for button input
     */
    #define HZN_BREAKPOINT()

    /**
     * @def HZN_DEBUGPOINT
     * @brief Pauses the execution, displays a message and waits for button input
     * @param msg The message to print
     */
    #define HZN_DEBUGPOINT(msg)
#endif
#ifdef HZN_DEBUG
    #include <unistd.h>
    #define TRACE(fmt,...) printf("%s: " fmt "\n", __PRETTY_FUNCTION__, ## __VA_ARGS__)

    static void initNxLink() {
        if (R_FAILED(socketInitializeDefault()))
            return;

        hzn::priv::nxlinkSocket = nxlinkStdio();

        if (hzn::priv::nxlinkSocket >= 0)
            TRACE("printf output now goes to nxlink server");
        else
            socketExit();
    }

    static void deinitNxLink() {
        if (hzn::priv::nxlinkSocket >= 0) {
            close(hzn::priv::nxlinkSocket);
            socketExit();
            hzn::priv::nxlinkSocket = -1;
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
    #define HZN_BREAKPOINT()
    #define HZN_DEBUGPOINT()
#endif
