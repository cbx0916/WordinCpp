#include <iostream>
#include <Python.h>
// #include "Python.h"

int main()
{
    std::cout << "Init...";
    // init
    Py_Initialize();

    // if init
    if (!Py_IsInitialized())
    {
        std::cout << "Python Init Failed!";
        return 0;
    }

    
    PyRun_SimpleString(R"(print("C++ call python"))");
    std::cout << "ok";
    // end
    Py_Finalize();
    
    getchar();
    return 0;
}
