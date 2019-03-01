/**
 * @file mutex.hpp
 * @brief Defines the Mutex class
 */
#ifndef MUTEX_H
#define MUTEX_H

#pragma once

#include <sys/lock.h>

namespace horizon {
    /**
     * @brief The mutex class
     */
    class Mutex {
    public:
        /**
         * @brief Creates the mutex
         */
        Mutex();

        /**
         * @brief Destructor
         *
         * This automatically unlocks the mutex
         */
        ~Mutex();

        /**
         * @brief Locks the mutex
         */
        void lock();

        /**
         * @brief Unlocks the mutex
         */
        void unlock();

    private:
        /* data */
        typedef _LOCK_RECURSIVE_T RMutex;
        RMutex m_mutex;
    };
} /* horizon */


#endif /* end of include guard: MUTEX_H */
