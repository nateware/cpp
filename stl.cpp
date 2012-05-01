/*
 * stl.cpp - stl
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// C++ inline function - compiler inserts the complete body of the function in every
// place that the function is called, rather than generating code to call the function
// http://stackoverflow.com/questions/29383/converting-bool-to-text-in-c
inline const char * const BoolToString(bool b)
{
  return b ? "true" : "false";
}

// C way
#define BOOL_STR(b) ((b)?"true":"false")

int main()
{
    vector<string> mystring;

    mystring.push_back("10");
    mystring.push_back("20");
    mystring.push_back("30");

    printf("Loop by index\n");
    for (int i=0; i < mystring.size(); i++)
        printf("mystring[%d]=%s\n", i, mystring[i].c_str());

    
    printf("Iterator\n");
    for (vector<string>::iterator iter = mystring.begin(); iter != mystring.end(); iter++)
        printf("next element: %s\n", (*iter).c_str()); // or iter->c_str()

    vector<bool> truthy;
    truthy.push_back(true);
    truthy.push_back(false);
    truthy.push_back(true);
    truthy.push_back(false);
    truthy.push_back(false);
    
    printf("Booleans (%d elements)\n", (int)truthy.size());
    for (vector<bool>::iterator iter = truthy.begin(); iter != truthy.end(); iter++)
        printf("next element: %s\n", BoolToString(*iter));

    printf("Booleans via macro (%d elements)\n", (int)truthy.size());
    for (vector<bool>::iterator iter = truthy.begin(); iter != truthy.end(); iter++)
        printf("next element: %s\n", BOOL_STR(*iter));

}

