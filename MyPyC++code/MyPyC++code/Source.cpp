#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include "Charprint.h"
#include <fstream>
#include < sstream>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonFile");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonFile");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonFile");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}
void menu() {// I VERIFIED that any input that isn't 1, 2, or3 will result in an error message an conitnue to an iteration of the loop again. 
	int unsigned i;
	int option, number, total;
	ifstream myfile;
	string line, product;
	Charprint character;

	
	myfile.open("storelist.txt");
	if (!myfile.is_open()) {
		cout << "we messed up coach";
	}
	myfile.close();
	while (true) {
		cout << "Please Selet an option by pressing 1, 2, or 3. If you wish to quit, please press 4" << endl;
		cout << "1: List of all produce purchased today." << endl;
		cout << "2: The number of times each produce was purchased." << endl;
		cout << "3: List out a frequency rate of each produce sold." << endl;
		cout << "4: Exit the program" << endl;
		cin >> option;

		if (option == 1) {
			callIntFunc("readList", "storelist.txt");
			continue;

		}
		if (option == 2) {
			callIntFunc("findItem", "storelist.txt");
			continue;
		}

		else if (option == 3) {
			callIntFunc("createFile", "storelist.txt");
			myfile.open("frequency.txt");
			if (!myfile) {
				cout << "Can't open";
			}
			while (getline(myfile, line)) {
				istringstream ss(line);
				ss >> product >> total;
				cout << product;
				character.PRINTCHAR(total, '*');
				cout << endl;
	}
}
		else if (option == 4) {
			break;
		}
		else {
			cout << "Invalid response." << endl;
			continue;
		}
	}
} 


int main()
{
	
	menu();

	





}