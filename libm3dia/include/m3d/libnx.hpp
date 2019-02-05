/**
 * @file libnx.hpp
 * @brief Includes libnx if M3D_NO_LIBNX isn't defined
 */
/**
 * @def M3D_NO_LIBNX
 * @brief Disables the automatic inclusion of libnx, allowing you to use your own fork instead
 *
 * This is useful if you use the m3diaLib in places where the official libnx doesn't work.
 */
#ifndef M3D_NO_LIBNX
    #include <switch.h>
#endif
