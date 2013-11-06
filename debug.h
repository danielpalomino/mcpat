/**
 * @author Sascha friedmann <friedman@informatik.uka.de>
 *
 * This header defines the REPORT macro. The REPORT macro allows easy
 * enabling/disabling of debugging output.
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#include <cstdio>

// How many spaces are used for indentation per level in NREPORT.
#ifndef REPORT_INDENT
#define REPORT_INDENT 2
#endif /* REPORT_INDENT */

// Convert a boolean expression to "yes" or "no" strings.
#define REPORT_YESNO(expr) ((expr)?"yes":"no")

#define __REPORT(fmt, ...) do { \
    std::fprintf(stderr, fmt, ## __VA_ARGS__); \
} while (0)

#define REPORT(fmt, ...) do { \
    NREPORT(0, fmt, ## __VA_ARGS__); \
} while (0)

#define NREPORT(level, fmt, ...) do { \
    const unsigned __report_level = (level)*REPORT_INDENT; \
    if (__report_enabled) \
        __REPORT("%s:%.4u:%*.*s" fmt "\n", __FILE__, __LINE__, __report_level, __report_level, "", ## __VA_ARGS__); \
} while (0)

#endif /* DEBUG_H_ */
