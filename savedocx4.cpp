#include <iostream>
#include <Python.h>
using namespace std;


int main()
{
    // init
    cout << "Init...\n";
    Py_Initialize();

    // whether init
    if (!Py_IsInitialized())
    {
        cout << "Python Init Failed!\n";
        return 0;
    }

    PyRun_SimpleString( "import sys" );
    PyRun_SimpleString( "import os" );
    PyRun_SimpleString( "from docx import Document" );
    PyRun_SimpleString( "from docx.enum.text import WD_ALIGN_PARAGRAPH" );
    PyRun_SimpleString( "from docx.shared import Pt" );
    PyRun_SimpleString( "from docx.shared import RGBColor" );
    PyRun_SimpleString( "from docx.oxml.ns import qn" );
    PyRun_SimpleString( "from docx.shared import Inches" );
    PyRun_SimpleString( "sys.path.append('./')");
    // PyRun_SimpleString("sys.path.append('../')");	// demo_test.py的路径，这里与c_call_python放在同一个目录下

    
    PyObject *moduleName = PyUnicode_FromString("savedocx");  //载入名为demo_test.py的文件
    PyObject *pModule = PyImport_Import(moduleName);
    if (!pModule) {		//如果不存在改文件，则结束
        printf("Can't find python file");
        Py_Finalize();
        return -1;
    }
    

    char titlename[] = "关于下发《XXXX》的通知";
    char texts[] = "正文部分";
    char filename[] = "test4.docx";
    // 判断文档命名与后缀规范
    // if (titlename.length()<2){
    //     titlename = "关于下发《XXXX》的通知";
    // }
    // if (!filename.find(".doc")){
    //     filename += ".docx";
    // }

    PyObject* title = Py_BuildValue("s", titlename);
    PyObject* text = Py_BuildValue("s", texts);
    PyObject* dest = Py_BuildValue("s", filename);
    cout << "\nTitle:" << titlename << "\n" << "Texts:" << texts << "\n" << "FileName:" <<filename << endl;

    PyObject* pArgs = PyTuple_New(3);
    PyTuple_SetItem(pArgs, 0, title); //0：表示序号。第一个参数。i：表示传入的参数类型是int类型。
    PyTuple_SetItem(pArgs, 1, text); //1：也表示序号。第二个参数。
    PyTuple_SetItem(pArgs, 2, dest); //2：也表示序号。第三个参数。

    cout << "\nGetting addText...\n";
    PyObject *pAddText = PyObject_GetAttrString(pModule, "addText");  //获取函数
    if (!pAddText)
    {
        printf("Can't find function [pAddText]");
        Py_Finalize();
        return -1;
    }

    cout << "\nRunning addText...\n";
    PyObject_CallObject(pAddText, pArgs);  //无返回类型
    cout << "\nEnd addText!\n";

    // end
    Py_Finalize();

    system("pause");
    return 0;
}

