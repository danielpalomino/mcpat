#include "mytime.h"

Time Time::now()
{
    timespec t;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t);
    return Time(t);
}

Time Time::diff(const Time & lhs, const Time & rhs)
{
    timespec temp;

    if ((lhs.t.tv_nsec - rhs.t.tv_nsec) < 0) {
        temp.tv_sec = lhs.t.tv_sec - rhs.t.tv_sec - 1;
        temp.tv_nsec = 1000000000 + lhs.t.tv_nsec - rhs.t.tv_nsec;
    } else {
        temp.tv_sec = lhs.t.tv_sec - rhs.t.tv_sec;
        temp.tv_nsec = lhs.t.tv_nsec - rhs.t.tv_nsec;
    }
    return Time(temp);
}

std::ostream & Time::print(std::ostream & out, const Time & _t)
{
    timespec t = _t.t;

    if (t.tv_sec) {
        out << t.tv_sec  << "." << (t.tv_nsec/1000000) << " s";
    } else if (t.tv_nsec > 1000000) {
        long ms = t.tv_nsec / 1000000;
        t.tv_nsec -= ms*1000000;
        out << ms << "." << (t.tv_nsec/1000) << " ms";
    } else if (t.tv_nsec > 1000) {
        long us = t.tv_nsec / 1000;
        t.tv_nsec -= us*1000;
        out << us << "." << (t.tv_nsec/1000) << " us";
    } else {
        out << t.tv_nsec << "ns";
    }
}
