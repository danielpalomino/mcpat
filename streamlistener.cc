#include "streamlistener.h"
#include "XML_Parse.h"

#include <exception>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <string>
#include <memory>

StreamListener::StreamListener(std::istream &in, Processor &proc, int verbosity)
 : in(in), proc(proc), verbosity(verbosity)
{
    if (!in)
        throw std::runtime_error(std::string("StreamListener: invalid input stream"));
    in.unsetf(std::ios_base::skipws);
}

const std::string StreamListener::endtag("</component>");

void StreamListener::energyCalculationLoop()
{
    while (readXmlRequest()) {
        // Processor::computeEnergy stores a reference to the xml object,
        // therefore, it must stay alive until both computeEnergy and
        // displayEnergy are called.
        std::auto_ptr<ParseXML> xml(new ParseXML);
        xml->parse(filebuf);

        computeEnergy(xml.get());
        displayEnergy();
    }
}

void StreamListener::computeEnergy(ParseXML *xml)
{
    proc.computeEnergy(xml, true);	// thermal design power
    proc.computeEnergy(xml, false);	// runtime dynamic
}

void StreamListener::displayEnergy()
{
    proc.collectEnergy();
    proc.displayEnergy(2, verbosity);
}

bool StreamListener::readXmlRequest()
{
    filebuf.clear();

    std::string line;

    while (in && line != endtag) {
        std::getline(in, line);
        filebuf += line;
    }

    return line == endtag;
}
