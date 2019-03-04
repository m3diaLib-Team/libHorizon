#include <chrono>
#include "horizon/core/time.hpp"

namespace horizon {
    Time::Time() :
            m_milliseconds(0) { /* do nothing */ }

    Time::Time(unsigned long long int milliseconds) :
            m_milliseconds(milliseconds) { /* do nothing */ }

    Time::Time(Time& time) {
        setTime(time);
    }

    void Time::setTime(unsigned long long int milliseconds) {
        m_milliseconds = milliseconds;
    }

    void Time::setTime(Time& time) {
        m_milliseconds = time.getAsMilliseconds();
    }

    void Time::addTime(unsigned long long int milliseconds) {
        m_milliseconds += milliseconds;
    }

    void Time::addTime(Time& rhs) {
        m_milliseconds += rhs.getAsMilliseconds();
    }

    void Time::substractTime(unsigned long long int milliseconds) {
        m_milliseconds -= milliseconds;
    }

    void Time::substractTime(Time& rhs) {
        m_milliseconds -= rhs.getAsMilliseconds();
    }

    long double Time::getAsHours() {
        return (long double) m_milliseconds / 60.f / 60.f / 1000.f;
    }

    long double Time::getAsMinutes() {
        return (long double) m_milliseconds / 60.f / 1000.f;
    }

    long double Time::getAsSeconds() {
        return (long double) m_milliseconds / 1000.f;
    }

    long double Time::getAsMilliseconds() {
        return (long double) m_milliseconds;
    }

    unsigned long int Time::getTimestamp() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
        ).count();
    }

    long double Time::convert(Time::Component from, Time::Component to, unsigned long long int time) {
        long double milliseconds = 0;

        switch (from) {
            case Time::Component::Hours:
                milliseconds = (long double) time * 60.f * 60.f * 1000.f;
                break;
            case Time::Component::Minutes:
                milliseconds = (long double) time * 60.f * 1000.f;
                break;
            case Time::Component::Seconds:
                milliseconds = (long double) time * 1000.f;
                break;
            case Time::Component::Milliseconds:
                milliseconds = (long double) time;
                break;
        }

        switch (to) {
            case Time::Component::Hours:
                return milliseconds / 1000.f / 60.f / 60.f;
            case Time::Component::Minutes:
                return milliseconds / 1000.f / 60.f;
            case Time::Component::Seconds:
                return milliseconds / 1000.f;
            case Time::Component::Milliseconds:
                return milliseconds;
        }

        return 0;
    }

    Time& Time::operator=(unsigned long long int rhs) {
        m_milliseconds = rhs;
        return *this;
    }

    Time& Time::operator=(Time& rhs) {
        m_milliseconds = rhs.getAsMilliseconds();
        return *this;
    }

    bool Time::operator==(const unsigned long long int milliseconds) {
        return m_milliseconds == milliseconds;
    }

    bool Time::operator==(Time &rhs) {
        return m_milliseconds == rhs.getAsMilliseconds();
    }

    bool Time::operator<(const unsigned long long int milliseconds) {
        return m_milliseconds < milliseconds;
    }

    bool Time::operator<(Time &rhs) {
        return m_milliseconds < rhs.getAsMilliseconds();
    }

    bool Time::operator<=(const unsigned long long int milliseconds) {
        return m_milliseconds <= milliseconds;
    }

    bool Time::operator<=(Time &rhs) {
        return m_milliseconds <= rhs.getAsMilliseconds();
    }

    bool Time::operator>(const unsigned long long int milliseconds) {
        return m_milliseconds > milliseconds;
    }

    bool Time::operator>(Time &rhs) {
        return m_milliseconds > rhs.getAsMilliseconds();
    }

    bool Time::operator>=(const unsigned long long int milliseconds) {
        return m_milliseconds >= milliseconds;
    }

    bool Time::operator>=(Time &rhs) {
        return m_milliseconds >= rhs.getAsMilliseconds();
    }

    Time Time::operator+=(unsigned long long int rhs) {
        addTime(rhs);
        return *this;
    }

    Time Time::operator+=(Time &rhs) {
        addTime(rhs);
        return *this;
    }

    Time Time::operator+(unsigned long long int rhs) {
        addTime(rhs);
        return *this;
    }

    Time Time::operator+(Time &rhs) {
        addTime(rhs);
        return *this;
    }

    Time Time::operator-=(unsigned long long int rhs) {
        substractTime(rhs);
        return *this;
    }

    Time Time::operator-=(Time &rhs) {
        substractTime(rhs);
        return *this;
    }

    Time Time::operator-(unsigned long long int rhs) {
        substractTime(rhs);
        return *this;
    }

    Time Time::operator-(Time &rhs) {
        substractTime(rhs);
        return *this;
    }
} /* horizon */
