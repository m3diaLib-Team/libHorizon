/**
 * @file time.hpp
 * @brief Defines the Time class
 */
#ifndef TIME_HPP
#define TIME_HPP

#pragma once
#include <atomic>

namespace horizon {
    /**
     * @brief The time class, used for representing time
     */
    class Time {
    public:
        /**
         * @brief Represents different time components
         */
        enum class Component {
            Hours,        ///< Hours
            Minutes,      ///< Minutes
            Seconds,      ///< Seconds
            Milliseconds, ///< Milliseconds
        };

        /**
         * @brief Initializes the time
         */
        Time();

        /**
         * @brief Initializes the time with a given amount of milliseconds
         * @param milliseconds The time in milliseconds
         */
        Time(unsigned long long int milliseconds);

        /**
         * @brief Initializes the time given another Time-object
         * @param time The time-object
         *
         * This method is equivalent of a copy-constructor
         */
        Time(Time& time);

        /**
         * @brief Sets the time with a given amount of milliseconds
         * @param milliseconds The time in milliseconds
         */
        void setTime(unsigned long long int milliseconds);

        /**
         * @brief Sets the time given another Time-object
         * @param time The time-object
         */
        void setTime(Time& time);

        /**
         * @brief Adds milliseconds to time
         * @param milliseconds The milliseconds
         */
        void addTime(unsigned long long int milliseconds);

        /**
         * @brief Adds to the time
         * @param time The time to add
         */
        void addTime(Time& rhs);

        /**
         * @brief Substracts milliseconds from the time
         * @param milliseconds The milliseconds
         */
        void substractTime(unsigned long long int milliseconds);

        /**
         * @brief Substracts from the time
         * @param time The time to substract
         */
        void substractTime(Time& rhs);

        /**
         * @brief Returns the time converted to hours
         * @return The time converted to hours
         */
        long double getAsHours();

        /**
         * @brief Returns the time converted to minutes
         * @return The time converted to minutes
         */
        long double getAsMinutes();

        /**
         * @brief Returns the time converted to seconds
         * @return The time converted to seconds
         */
        long double getAsSeconds();

        /**
         * @brief Returns the time converted to milliseconds
         * @return The time converted to milliseconds
         */
        long double getAsMilliseconds();

        /**
         * @brief Returns the current unix timestamp in milliseconds
         * @return The timestamp
         */
        static unsigned long int getTimestamp();

        /**
         * @brief Converts a given time component to another one
         * @param  from The time-component to convert from
         * @param  to   The time-component to convert to
         * @param  time The time to convert
         * @return      The converted time
         *
         * Example to convert 5 hours to milliseconds:\n
         * `unsigned long long int ns = Time::convert(Time::Component::Hours, Time::Component::Milliseconds, 5);`
         */
        static long double convert(Time::Component from, Time::Component to, unsigned long long int time);

        /**
         * @brief Overloads the assignment operator to set the milliseconds
         */
        Time& operator=(unsigned long long int rhs);

        /**
         * @brief Overloads the assignment operator to set it with another time object
         */
        Time& operator=(Time& rhs);

        /**
         * @brief Overloads the equal-to operator with milliseconds
         */
        bool operator==(const unsigned long long int milliseconds);

        /**
         * @brief Overloads the equal-to operator
         */
        bool operator==(Time &rhs);

        /**
         * @brief Overloads the less-than operator with milliseconds
         */
        bool operator<(const unsigned long long int milliseconds);

        /**
         * @brief Overloads the less-than operator
         */
        bool operator<(Time &rhs);

        /**
         * @brief Overloads the less-or-equal operator with milliseconds
         */
        bool operator<=(const unsigned long long int milliseconds);

        /**
         * @brief Overloads the less-or-equal operator
         */
        bool operator<=(Time &rhs);

        /**
         * @brief Overloads the greater-than operator with milliseconds
         */
        bool operator>(const unsigned long long int milliseconds);

        /**
         * @brief Overloads the greater-than operator
         */
        bool operator>(Time &rhs);

        /**
         * @brief Overloads the greater-or-equal operator with milliseconds
         */
        bool operator>=(const unsigned long long int milliseconds);

        /**
         * @brief Overloads the greater-or-equal operator
         */
        bool operator>=(Time &rhs);

        /**
         * @brief Overloads the addition-assignment operator to add milliseconds
         */
        Time operator+=(unsigned long long int rhs);

        /**
         * @brief Overloads the addition-assignment operator to add another time object
         */
        Time operator+=(Time &rhs);

        /**
         * @brief Overloads the addition operator to add milliseconds
         */
        Time operator+(unsigned long long int rhs);

        /**
         * @brief Overloads the addition operator to add another time object
         */
        Time operator+(Time &rhs);

        /**
         * @brief Overloads the substraction-assignment operator to substract milliseconds
         */
        Time operator-=(unsigned long long int rhs);

        /**
         * @brief Overloads the substraction-assignment operator to substract another time object
         */
        Time operator-=(Time &rhs);

        /**
         * @brief Overloads the substraction operator to substract milliseconds
         */
        Time operator-(unsigned long long int rhs);

        /**
         * @brief Overloads the substraction operator to substract another time object
         */
        Time operator-(Time &rhs);

    private:
        /* data */
        std::atomic<unsigned long long int> m_milliseconds;
    };
} /* horizon */


#endif /* end of include guard: TIME_HPP */
