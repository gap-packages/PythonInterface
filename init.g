#
# PythonInterface: calling python code  from GAP. Yes. I went there.
#
# Reading the declaration part of the package.
#
_PATH_SO:=Filename(DirectoriesPackagePrograms("PythonInterface"), "PythonInterface.so");
if _PATH_SO <> fail then
    LoadDynamicModule(_PATH_SO);
fi;
Unbind(_PATH_SO);

ReadPackage( "PythonInterface", "gap/PythonInterface.gd");
