/*
 * math.cpp
 */

#include <iostream>

class CMath {
    int m_num;

public:
    CMath(int x) : m_num(x){}

    void PrintHex() {
        printf("%d is %0x\n", m_num, m_num);
    }
};

int main()
{
    CMath *num = new CMath(42);
    num->PrintHex();

    return 0;
}
