/**
 * @author Sascha Friedmann <friedman@informatik.uka.de>
 *
 * A wrapper around timespec of <ctime>
*/
#ifndef MYTIME_H_
#define MYTIME_H_

#include <ctime>
#include <ostream>

class Time {
    public:
        Time() : t({0}) {}
        Time(const timespec & t) : t(t) {}

        static Time now();

        // lhs - rhs
        static Time diff(const Time & lhs, const Time & rhs);
        static std::ostream & print(std::ostream & out, const Time & t);

        timespec t;

        friend Time operator-(const Time&, const Time&);
        friend std::ostream & operator<<(std::ostream&, const Time&);
};

inline Time operator-(const Time & lhs, const Time & rhs)
{
    return Time::diff(lhs, rhs);
}

inline std::ostream & operator<<(std::ostream & out, const Time & t)
{
    return Time::print(out, t);
}

#endif /* MYTIME_H_ */
