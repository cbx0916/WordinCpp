#include <iostream>
#include <Python.h>

int main()
{
    // init
    std::cout << "Init...\n";
    Py_Initialize();

    // whether init
    if (!Py_IsInitialized())
    {
        std::cout << "Python Init Failed!\n";
        return 0;
    }

    PyRun_SimpleString( "import sys" );
    PyRun_SimpleString( "import os" );
    PyRun_SimpleString( "sys.path.append('..')" );
    PyRun_SimpleString( "path1 = os.path.abspath('.')" );
    PyRun_SimpleString( "path2 = os.path.abspath('..')" );
    PyRun_SimpleString( "path3 = os.path.abspath('../..')" );
    PyRun_SimpleString( "print('path1=',path1)" );
    PyRun_SimpleString( "print('path2=',path2)" );
    PyRun_SimpleString( "print('path3=',path3)" );

    PyRun_SimpleString( "import pytesr" );
    PyRun_SimpleString( "hi = pytesr.hi" );
    PyRun_SimpleString( "hi()" );


    std::cout << "\nend!";
    // end
    Py_Finalize();
    
    getchar();
    return 0;
}
