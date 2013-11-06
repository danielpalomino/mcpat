/**
 * @author Sascha friedmann <friedman@informatik.uka.de>
 *
 * The StreamListener class reads from an input stream and continuously
 * (re-)computes the energy consumption. It is written to the standard output
 * stream.
 */
#ifndef STREAMLISTENER_H_
#define STREAMLISTENER_H_


#include <iosfwd>
#include <string>
#include "processor.h"

class StreamListener
{
public:
    StreamListener(std::istream &in, Processor &proc, int verbosity = 2);
    void energyCalculationLoop();

private:

    /**
     * Reads a XML component spec from `in' into `filebuf'. Returns true if
     * successful, else false (typically if EOF was reached).
     */
    bool readXmlRequest();

    /**
     * Recomputes energy for the statistics of the latest request.
     */
    void computeEnergy(ParseXML *xml);

    /**
     * Displays the computed data.
     */
    void displayEnergy();


    /* Class attributes */
    std::istream &in;
    Processor &proc;
    std::string filebuf;
    int verbosity;

    /**
     * End marker of a (valid) XML component spec.
     */
    static const std::string endtag;
};

#endif /* STREAMLISTENER_H_ */
