#
# PythonInterface: calling python code  from GAP. Yes. I went there.
#
# This file runs package tests. It is also referenced in the package
# metadata in PackageInfo.g.
#
LoadPackage( "PythonInterface" );

TestDirectory(DirectoriesPackageLibrary( "PythonInterface", "tst" ),
  rec(exitGAP := true));

FORCE_QUIT_GAP(1); # if we ever get here, there was an error
