#
# PythonInterface: calling python code  from GAP. Yes. I went there.
#
# This file is part of the build system of a GAP kernel extension.
# Requires automake.
#
ACLOCAL_AMFLAGS = -I cnf/m4

BINARCHDIR = bin/$(GAPARCH)
GAPINSTALLLIB = $(BINARCHDIR)/PythonInterface.so

lib_LTLIBRARIES = PythonInterface.la

PythonInterface_la_SOURCES = src/PythonInterface.c
PythonInterface_la_CPPFLAGS = $(GAP_CPPFLAGS) -DCONFIG_H
PythonInterface_la_LDFLAGS = -module -avoid-version
if SYS_IS_CYGWIN
PythonInterface_la_LDFLAGS += -no-undefined -version-info 0:0:0 
PythonInterface_la_LDFLAGS += -Wl,$(GAPROOT)/bin/$(GAPARCH)/gap.dll
endif

all-local: $(GAPINSTALLLIB)

$(GAPINSTALLLIB): PythonInterface.la
	$(mkdir_p) $(BINARCHDIR)
if SYS_IS_CYGWIN
	cp .libs/PythonInterface.dll $(GAPINSTALLLIB)
else
	cp .libs/PythonInterface.so $(GAPINSTALLLIB)
endif

clean-local:
	rm -f $(GAPINSTALLLIB)

distclean-local:
	rm -rf bin/*

doc:
	($(GAPROOT)/bin/gap.sh -A makedoc.g)
