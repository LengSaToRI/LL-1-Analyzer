#include <iostream>
#include <string>
#include <cstdlib>
#include "cifa.h"
#include <stack.h>
#include <table.h>

using namespace std;


void process()  //文法分析
{
    int stepNum=1;
    string topStr;
    Stack stack;
    WordType word;
    Table table;
    cout<<"请输入源程序，以&结束:";
    word=get_w();

    cout<<"步骤\t\t符号栈\t\t\t当前单词\t\t动作"<<endl;
    stack.push("&");
    stack.push("S");
    while(1)                //匹配
    {
        topStr=stack.getTop();
        if(topStr=="&"&&word.pro=="&")      //判断终结符
        {
            cout<<stepNum++<<"\t\t";
            stack.outStack();
            cout<<"\t\t\t"<<word.pro<<"\t\t\t"<<"分析成功"<<endl;
            break;
        }
        else if(topStr=="i"&&(word.code==100))  //判断标识符
        {
            cout<<stepNum++<<"\t\t";
            stack.outStack();
            cout<<"\t\t\t"<<word.pro<<"\t\t\t"<<"匹配标识符"<<endl;
            stack.pop();
            word=get_w();
        }
        else if(topStr==word.pro)   //判断终结符
        {
            cout<<stepNum++<<"\t\t";
            stack.outStack();
            cout<<"\t\t\t"<<word.pro<<"\t\t\t"<<"匹配终结符"<<endl;
            stack.pop();
            word=get_w();
        }
        else if(table.getRowNumber(topStr)!=-1)     //判断非终结符
        {
            cout<<stepNum++<<"\t\t";
            stack.outStack();
            int lineNum=table.getLineNumber(word.code);
            string a=table.getCell(topStr,lineNum);     //查表
            cout<<"\t\t\t"<<word.pro<<"\t\t\t"<<topStr<<"->"<<a<<endl;
            stack.pop();    //出栈
            if(a!="")
            {
                stack.pushReverse(a);   //查表单词反向入栈
            }
        }
        else
        {
            cout<<"分析失败!";
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
        cout<<"      LL(1)分析器       "<<endl;
        cout<<"*************************"<<endl;
        process();
        cout<<endl<<endl<<"继续新的语法分析按y，其他字符退出：";
        cin.clear();
        cin.sync();
        cin >> choose;
    }while (choose=='y');
    return 0;
}
