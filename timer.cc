#include "timer.h"

Timer::Timer()
{
    start();
}

void Timer::start()
{
    _just_started = true;
    _start = Time::now();
}

void Timer::clear()
{
    _rounds.clear();
}

void Timer::round(const std::string &name)
{
    Time t;

    if (_just_started) {
        t = Time::now() - _start;
        _just_started = false;
    } else {
        t = Time::now() - _rounds.back().second;
    }

    _rounds.push_back(std::make_pair(name, t));
}

std::ostream & Timer::print(std::ostream & out) const
{
    int i = 0;
    for (auto it = _rounds.begin(); it != _rounds.end(); ++it, ++i)
        out << it->first << ": " << it->second << std::endl;
    return out;
}
