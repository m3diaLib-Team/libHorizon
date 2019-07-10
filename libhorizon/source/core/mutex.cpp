#include "horizon/libnx.hpp"
#include "horizon/core/mutex.hpp"

namespace horizon {
    Mutex::Mutex() {
        rmutexInit(&m_mutex);
    }

    Mutex::~Mutex() {
        rmutexUnlock(&m_mutex);
    }

    void Mutex::lock() {
        rmutexLock(&m_mutex);
    }

    void Mutex::unlock() {
        rmutexUnlock(&m_mutex);
    }
} /* horizon */
