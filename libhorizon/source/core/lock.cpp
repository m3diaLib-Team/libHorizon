#include "horizon/core/mutex.hpp"
#include "horizon/core/lock.hpp"

namespace horizon {
    Lock::Lock(Mutex& t_mutex) :
            m_mutex(t_mutex) {
        m_mutex.lock();
    }

    Lock::~Lock() {
        m_mutex.unlock();
    }
} /* horizon */
