SUBDIRS = cacti

bin_PROGRAMS = mcpat

mcpat_CPPFLAGS = -I$(abs_top_srcdir)/cacti

AM_CXXFLAGS = -m32 -pthread -Wno-unknown-pragmas -DNTHREADS=$(NTHREADS)
export AM_CXXFLAGS

mcpat_SOURCES =
mcpat_SOURCES += arch_const.h
mcpat_SOURCES += array.cc
mcpat_SOURCES += array.h
mcpat_SOURCES += basic_components.cc
mcpat_SOURCES += basic_components.h
mcpat_SOURCES += core.cc
mcpat_SOURCES += core.h
mcpat_SOURCES += globalvar.h
mcpat_SOURCES += interconnect.cc
mcpat_SOURCES += interconnect.h
mcpat_SOURCES += iocontrollers.cc
mcpat_SOURCES += iocontrollers.h
mcpat_SOURCES += logic.cc
mcpat_SOURCES += logic.h
mcpat_SOURCES += main.cc
mcpat_SOURCES += memoryctrl.cc
mcpat_SOURCES += memoryctrl.h
mcpat_SOURCES += noc.cc
mcpat_SOURCES += noc.h
mcpat_SOURCES += processor.cc
mcpat_SOURCES += processor.h
mcpat_SOURCES += sharedcache.cc
mcpat_SOURCES += sharedcache.h
mcpat_SOURCES += streamlistener.cc
mcpat_SOURCES += streamlistener.h
mcpat_SOURCES += technology_xeon_core.cc
mcpat_SOURCES += version.h
mcpat_SOURCES += XML_Parse.cc
mcpat_SOURCES += XML_Parse.h
mcpat_SOURCES += xmlParser.cc
mcpat_SOURCES += xmlParser.h

mcpat_LDADD = cacti/libcacti.a -lrt

EXTRA_DIST =
EXTRA_DIST += Alpha21364.xml
EXTRA_DIST += Niagara1_sharing_DC.xml
EXTRA_DIST += Niagara1_sharing_SBT.xml
EXTRA_DIST += Niagara1_sharing_ST.xml
EXTRA_DIST += Niagara1_sharing.xml
EXTRA_DIST += Niagara1.xml
EXTRA_DIST += Niagara2.xml
EXTRA_DIST += Penryn.xml
EXTRA_DIST += Xeon.xml
EXTRA_DIST += README
EXTRA_DIST += makefile.old
EXTRA_DIST += mcpat.mk
EXTRA_DIST += mcpatXeonCore.mk
EXTRA_DIST += results/Alpha21364
EXTRA_DIST += results/Alpha21364_90nm
EXTRA_DIST += results/Penryn
EXTRA_DIST += results/T1
EXTRA_DIST += results/T1_DC_64
EXTRA_DIST += results/T1_SBT_64
EXTRA_DIST += results/T1_ST_64
EXTRA_DIST += results/T2
EXTRA_DIST += results/Xeon_core
EXTRA_DIST += results/Xeon_uncore
