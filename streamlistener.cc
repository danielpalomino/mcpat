#include "streamlistener.h"
#include "XML_Parse.h"
#include "timer.h"

#include <exception>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <string>
#include <memory>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
    std::auto_ptr<ParseXML> xml(new ParseXML);
    while (readXmlRequest()) {        
        Timer::global().start();
        // Processor::computeEnergy stores a reference to the xml object,
        // therefore, it must stay alive until both computeEnergy and
        // displayEnergy are called.
        
        xml->parse(filebuf);
        processRequest(xml.get());
        Timer::global().round("request");
        xml.reset(new ParseXML);
    }
}

void StreamListener::processRequest(ParseXML *xml)
{
    // Unfortunately the code in McPAT is not written in a way where it can do
    // multiple energy statistic calculation for a computed platform (for
    // example, see the computeEnergy() function in noc.cc, where it stores
    // results in some attributes used earlier in the function).
    //
    // To overcome this limitation we call computeEnergy() in a background
    // process, i.e., we use the fork() semantics as a way of checkpointing
    // McPAT's state.

    pid_t child_pid = fork();
    if (0 == child_pid) {        
        computeEnergy(xml);
        displayEnergy();
        exit(0);
    } else {
        if (child_pid != waitpid(child_pid, NULL, 0)) {
            std::cerr << __FILE__ << ":" << __LINE__
                      << " waitpid() returned something unexpected: "
                      << child_pid << std::endl;
        }
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
    // Make sure that parts of a McPat report don't stay in the buffer, until
    // the output of the next report fill it up.
    std::cout.flush();
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
