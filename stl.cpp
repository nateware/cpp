/*
 * stl.cpp - stl
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> mystring;

    mystring.push_back("10");
    mystring.push_back("20");
    mystring.push_back("30");

    printf("Loop by index\n");
    for (int i=0; i < mystring.size(); i++)
        printf("mystring[%d]=%s\n", i, mystring[i]);

    
    printf("Iterator\n");
    for (vector<string>::iterator ci = mystring.begin(); ci != mystring.end(); ci++)
        printf("next element: %s\n", *ci);

    

}
