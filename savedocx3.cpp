#include <iostream>
#include <Python.h>
// using namespace std;

# now editing file3
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
    PyRun_SimpleString( "from docx import Document" );
    PyRun_SimpleString("sys.path.append('./')");
    // PyRun_SimpleString("sys.path.append('../')");	// demo_test.py的路径，这里与c_call_python放在同一个目录下

    
    PyObject *moduleName = PyUnicode_FromString("savedocx");  //载入名为demo_test.py的文件
    PyObject *pModule = PyImport_Import(moduleName);
    if (!pModule) {		//如果不存在改文件，则结束
        printf("can't find python file");
        Py_Finalize();
        return -1;
    }
    
    std::string titlename;
    std::string texts;
    std::string filename;
    std::cout << "please input title:" ;
    std::cin >> titlename;
    std::cout << "please input text:" ;
    std::cin >> texts;
    std::cout << "please input filename(end with \".docx\"):" ;
    std::cin >> filename;
    if (titlename.length()<2){
        titlename = "关于下发《XXXX》的通知";
    }
    if (!filename.find(".doc")){
        filename += ".docx";
    }

    PyObject* title = Py_BuildValue("s", titlename);
    PyObject* text = Py_BuildValue("s", texts);
    PyObject* dest = Py_BuildValue("s", filename);
    PyObject* pArgs = PyTuple_New(3);
    PyTuple_SetItem(pArgs, 0, title); //0：表示序号。第一个参数。i：表示传入的参数类型是int类型。
    PyTuple_SetItem(pArgs, 1, text); //1：也表示序号。第二个参数。
    PyTuple_SetItem(pArgs, 2, dest); //2：也表示序号。第三个参数。

    std::cout << "Getting addParagraph...\n";
    PyObject *pAddText = PyObject_GetAttrString(pModule, "addText");  //获取函数
    if (!pAddText)
    {
        printf("can't find function [pAddText]");
        Py_Finalize();
        return -1;
    }

    std::cout << "Running addParagraph...\n";
    PyObject_CallObject(pAddText, pArgs);  //无返回类型
    std::cout << "\nEnd AddParagraph!\n";

    // end
    Py_Finalize();

    system("pause");
    return 0;
}

