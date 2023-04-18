#include <string>
#include <iostream>
#include <stack.h>

using namespace std;

string codestr[24] = {"System","Version","Code","Data",     //关键字表
                          "<",">","</","<!","!>",
                          "@@","#","//","::","=",
                          ".","/@","%","$",":",
                           "*","'","-",",",":="};

Stack::Stack()  //初始化栈
{
    i = 0;
    data = new string[100];
}


int Stack::push(string m)   // 入栈操作
{
    if (i < 100)
    {
        data[i++] = m;
        return 1;
    }
    else
    {
        return -1;
    }
}


int Stack::pop()       // 出栈操作
{
    if (i > 0)
    {
        i--;
        return 1;
    }
    else
    {
        return -1;
    }
}


string Stack::getTop()      // 获取栈顶元素
{
    if (i > 0)
    {
        return data[i - 1];
    }
    else
    {
        return ""; // 表示栈为空
    }
}

Stack::~Stack()
{
    delete[] data;
}

int Stack::topNumber()      // 返回当前栈中元素个数
{
    return i;
}

void Stack::outStack()      // 输出栈中所有元素
{
    for (int j = 0; j <i; j++)
    {
        cout << data[j];
    }
}
void Stack::pushReverse(string m)   // 将字符串m反向入栈
{

    int len = m.length();
    if (m == "System")  // 如果关键字是System，则按顺序压入
    {
        push("System");
        return;
    }
    else if (m == "Version")
    {
        push("Version");
        return;
    }
    else if (m == "Code")
    {
        push("Code");
        return;
    }
    else if (m == "Data")
    {
        push("Data");
        return;
    }
    for (int i = len - 1; i >= 0; )
    {
        string c;
        c=m[i];
        i--;
        if (i >= 0)
        {
            string d = m[i] + c;
            for (int j = 0; j < 24; j++)
            {
                if (d == codestr[j])
                {
                    c = d;
                    i--;
                    break;
                }
            }
        }
        push(c);
    }
}
