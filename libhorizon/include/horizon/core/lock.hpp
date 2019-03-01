/**
 * @file lock.hpp
 * @brief Defines the Lock class
 */
#ifndef LOCK_H
#define LOCK_H

#pragma once

namespace horizon {
    class Mutex;

    /**
     * @brief The Lock class used to lock mutexes
     */
    class Lock {
    public:
        /**
         * @brief Creates the lock
         * @param t_mutex The mutex to lock
         */
        Lock(Mutex& t_mutex);

        /**
         * @brief Destructs the lock
         * @note This automatically unlocks it's mutex
         */
        ~Lock();

    private:
        /* data */
        Mutex m_mutex;
    };
} /* horizon */


#endif /* end of include guard: LOCK_H */
