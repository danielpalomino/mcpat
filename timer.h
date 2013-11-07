/**
 * @author Sascha Friedmann <friedman@informatik.uka.de>
 *
 * This class provides a simple Timer that can be started, stopped and queried
 * for round trip times.
 */
#ifndef TIMER_H_
#define TIMER_H_

#include <ostream>
#include <string>
#include <vector>

#include "mytime.h"

class Timer {
    public:
        typedef std::vector<std::pair<std::string, Time> > RoundsVector;
        // implies start()
        Timer();

        // (re-) start the timer
        void start();

        // synonym for round()
        void stop() {
            round();
        }

        // record a time (difference to previous round)
        void round(const std::string &name = std::string("round"));

        // clear recorded rounds
        void clear();

        // Return the start time
        const Time & startTime() const {
            return _start;
        }

        // Return all recorded rounds.
        const RoundsVector & rounds() const {
            return _rounds;
        }

        // Print a list of all recorded rounds to the given output stream.
        std::ostream & print(std::ostream &out) const;

        // Return a reference to the global timer
        static Timer & global() {
            static Timer timer;
            return timer;
        }

    private:
        bool _just_started;
        Time _start;
        RoundsVector _rounds;
};

inline std::ostream & operator<<(std::ostream & out, const Timer & timer)
{
    return timer.print(out);
}

#endif /* TIMER_H_ */
