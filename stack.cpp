#include <string>
#include <iostream>
#include <stack.h>

using namespace std;

string codestr[24] = {"System","Version","Code","Data",     //�ؼ��ֱ�
                          "<",">","</","<!","!>",
                          "@@","#","//","::","=",
                          ".","/@","%","$",":",
                           "*","'","-",",",":="};

Stack::Stack()  //��ʼ��ջ
{
    i = 0;
    data = new string[100];
}


int Stack::push(string m)   // ��ջ����
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


int Stack::pop()       // ��ջ����
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


string Stack::getTop()      // ��ȡջ��Ԫ��
{
    if (i > 0)
    {
        return data[i - 1];
    }
    else
    {
        return ""; // ��ʾջΪ��
    }
}

Stack::~Stack()
{
    delete[] data;
}

int Stack::topNumber()      // ���ص�ǰջ��Ԫ�ظ���
{
    return i;
}

void Stack::outStack()      // ���ջ������Ԫ��
{
    for (int j = 0; j <i; j++)
    {
        cout << data[j];
    }
}
void Stack::pushReverse(string m)   // ���ַ���m������ջ
{

    int len = m.length();
    if (m == "System")  // ����ؼ�����System����˳��ѹ��
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
