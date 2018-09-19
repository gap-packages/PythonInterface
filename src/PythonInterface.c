/*
 * PythonInterface: calling python code  from GAP. Yes. I went there.
 */

#include "src/compiled.h"          /* GAP headers */
#include <Python.h>

Obj FuncPyRun_SimpleString(Obj self, Obj command)
{
    Int res;
    if (IS_STRING_REP(command)) {
        return INTOBJ_INT(PyRun_SimpleString(CSTR_STRING(command)));
    }
    return Fail;
}


typedef Obj (* GVarFunc)(/*arguments*/);

// Table of functions to export
static StructGVarFunc GVarFuncs [] = {
    GVAR_FUNC(PyRun_SimpleString, 1, "command"),

	{ 0 } /* Finish with an empty entry */

};

/******************************************************************************
*F  InitKernel( <module> )  . . . . . . . . initialise kernel data structures
*/
static Int InitKernel( StructInitInfo *module )
{
    /* Initialize python */
    Py_Initialize();

    /* init filters and functions                                          */
    InitHdlrFuncsFromTable( GVarFuncs );

    /* return success                                                      */
    return 0;
}

/******************************************************************************
*F  InitLibrary( <module> ) . . . . . . .  initialise library data structures
*/
static Int InitLibrary( StructInitInfo *module )
{
    /* init filters and functions */
    InitGVarFuncsFromTable( GVarFuncs );

    /* return success                                                      */
    return 0;
}

/******************************************************************************
*F  InitInfopl()  . . . . . . . . . . . . . . . . . table of init functions
*/
static StructInitInfo module = {
    .type = MODULE_DYNAMIC,
    .name = "PythonInterface",
    .initKernel = InitKernel,
    .initLibrary = InitLibrary,
};

StructInitInfo *Init__Dynamic( void )
{
    return &module;
}
