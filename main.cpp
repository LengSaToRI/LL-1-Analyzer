#include <iostream>
#include <string>
#include <cstdlib>
#include "cifa.h"
#include <stack.h>
#include <table.h>

using namespace std;


void process()  //�ķ�����
{
    int stepNum=1;
    string topStr;
    Stack stack;
    WordType word;
    Table table;
    cout<<"������Դ������&����:";
    word=get_w();

    cout<<"����\t\t����ջ\t\t\t��ǰ����\t\t����"<<endl;
    stack.push("&");
    stack.push("S");
    while(1)                //ƥ��
    {
        topStr=stack.getTop();
        if(topStr=="&"&&word.pro=="&")      //�ж��ս��
        {
            cout<<stepNum++<<"\t\t";
            stack.outStack();
            cout<<"\t\t\t"<<word.pro<<"\t\t\t"<<"�����ɹ�"<<endl;
            break;
        }
        else if(topStr=="i"&&(word.code==100))  //�жϱ�ʶ��
        {
            cout<<stepNum++<<"\t\t";
            stack.outStack();
            cout<<"\t\t\t"<<word.pro<<"\t\t\t"<<"ƥ���ʶ��"<<endl;
            stack.pop();
            word=get_w();
        }
        else if(topStr==word.pro)   //�ж��ս��
        {
            cout<<stepNum++<<"\t\t";
            stack.outStack();
            cout<<"\t\t\t"<<word.pro<<"\t\t\t"<<"ƥ���ս��"<<endl;
            stack.pop();
            word=get_w();
        }
        else if(table.getRowNumber(topStr)!=-1)     //�жϷ��ս��
        {
            cout<<stepNum++<<"\t\t";
            stack.outStack();
            int lineNum=table.getLineNumber(word.code);
            string a=table.getCell(topStr,lineNum);     //���
            cout<<"\t\t\t"<<word.pro<<"\t\t\t"<<topStr<<"->"<<a<<endl;
            stack.pop();    //��ջ
            if(a!="")
            {
                stack.pushReverse(a);   //����ʷ�����ջ
            }
        }
        else
        {
            cout<<"����ʧ��!";
            return;
        }
    }
}
int main()
{
    char choose;
    do
    {
        system("cls");
        cout<<"*************************"<<endl;
        cout<<"      LL(1)������       "<<endl;
        cout<<"*************************"<<endl;
        process();
        cout<<endl<<endl<<"�����µ��﷨������y�������ַ��˳���";
        cin.clear();
        cin.sync();
        cin >> choose;
    }while (choose=='y');
    return 0;
}
