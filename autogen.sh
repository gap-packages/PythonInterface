#!/bin/sh -ex
#
# PythonInterface: calling python code  from GAP. Yes. I went there.
#
# This file is part of the build system of a GAP kernel extension.
# Requires GNU autoconf, GNU automake and GNU libtool.
#
autoreconf -vif `dirname "$0"`
