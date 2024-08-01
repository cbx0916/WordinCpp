#include <iostream>
#include <Python.h>

int main()
{
    // init
    std::cout << "Init...";
    Py_Initialize();

    // whether init
    if (!Py_IsInitialized())
    {
        std::cout << "Python Init Failed!";
        return 0;
    }

    // import sys
    PyRun_SimpleString("import sys");

    wchar_t *argv[2];
    argv[0] = L"arg1";
    argv[1] = L"arg2";
    PySys_SetArgv(2, argv);

    
    if (PyRun_SimpleString("exec('pytesr.py')") == NULL)
    {
        return -1;
    }
    // PyRun_SimpleString("exec('test.py')");

    std::cout << "ok";
    // end
    Py_Finalize();
    
    getchar();
    return 0;
}
