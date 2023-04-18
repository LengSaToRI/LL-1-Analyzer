#include <iostream>
#include <string>
#include <cifa.h>
using namespace std;

string codestring[24] = {"System","Version","Code","Data",
                          "<",">","</","<!","!>",
                          "@@","#","//","::","=",
                          ".","/@","%","$",":",
                           "*","'","-",",",":="};

char ch;
int flag=0;

WordType get_w();
void GetChar();
void GetBC();
bool IsLetter(char c);
bool IsDigit(char c);
void Retract();
int Reserve(string str);
string Concat(string str);

WordType get_w()    //词法分析
{
    string strToken = "";
    string temp = "";
    int code;
    WordType wordtmp;
    GetChar();
    GetBC();
    if (IsLetter(ch))
    {
        while (IsLetter(ch) || IsDigit(ch))
        {
            strToken = Concat(strToken);
            GetChar();
        }
        Retract();
        code = Reserve(strToken);
        if (code!=0)
        {
            wordtmp.code = code;
            wordtmp.pro = strToken;
        }
        else
        {
            wordtmp.code = 100;
            wordtmp.pro = strToken;
        }
    }

    else if (IsDigit(ch))
    {
        int count = 0;
        while (IsDigit(ch) && count <=1 )
        {
            strToken = Concat(strToken);
            GetChar();
            if (ch == '.' && count <1 )
            {
                count += 1;
                temp = strToken;
                strToken = Concat(strToken);
                GetChar();
                if (!IsDigit(ch))
                {
                    strToken = temp;
                    ch = '.';
                }
            }
        }
        Retract();
        wordtmp.code = 100;
        wordtmp.pro = strToken;
    }

    else if (ch == '<')
    {
        strToken = Concat(strToken);
        GetChar();
        if (ch == '/' || ch == '!') {
            strToken = Concat(strToken);
            code = Reserve(strToken);
            wordtmp.code = code;
            wordtmp.pro = strToken;
        }
        else
        {
            Retract();
            code = Reserve(strToken);
            wordtmp.code = code;
            wordtmp.pro = strToken;
        }
    }

    else if (ch == ':')
    {
        strToken = Concat(strToken);
        GetChar();
        if (ch == ':' || ch =='=')
        {
            strToken = Concat(strToken);
            code = Reserve(strToken);
            wordtmp.code = code;
            wordtmp.pro = strToken;
        }
        else {
            Retract();
            code = Reserve(strToken);
            wordtmp.code = code;
            wordtmp.pro = strToken;
        }
    }

    else if (ch == '!')
    {
        strToken = Concat(strToken);
        GetChar();
        if (ch == '>')
        {
            strToken = Concat(strToken);
            code = Reserve(strToken);
            wordtmp.code = code;
            wordtmp.pro = strToken;
        }
        else
        {
            Retract();
            code = Reserve(strToken);
            wordtmp.code = code;
            wordtmp.pro = strToken;
        }
    }

    else if (ch == '/') {
        strToken = Concat(strToken);
        GetChar();
        if (ch == '/'|| ch == '@') {
            strToken = Concat(strToken);
            code = Reserve(strToken);
            wordtmp.code = code;
            wordtmp.pro = strToken;
        }
        else
        {
            Retract();
            code = Reserve(strToken);
            wordtmp.code = code;
            wordtmp.pro = strToken;
        }
    }

    else if (ch == '@') {
        strToken = Concat(strToken);
        GetChar();
        if (ch == '@')
        {
            strToken = Concat(strToken);
            code = Reserve(strToken);
            wordtmp.code = code;
            wordtmp.pro = strToken;
        }
        else
        {
            Retract();
            code = Reserve(strToken);
            wordtmp.code = code;
            wordtmp.pro = strToken;
        }
    }

    else if (ch == '>')  { wordtmp.code = 6; wordtmp.pro = '>'; }
    else if (ch == '#')  { wordtmp.code = 11; wordtmp.pro = '#'; }
    else if (ch == '=')  { wordtmp.code = 14; wordtmp.pro = '='; }
    else if (ch == '%')  { wordtmp.code = 17; wordtmp.pro = '%'; }
    else if (ch == '$')  { wordtmp.code = 18; wordtmp.pro = '$'; }
    else if (ch == ':')  { wordtmp.code = 19; wordtmp.pro = ':'; }
    else if (ch == '*')  { wordtmp.code = 20; wordtmp.pro = '*'; }
    else if (ch == '\'') { wordtmp.code = 21; wordtmp.pro = '\''; }
    else if (ch == '-')  { wordtmp.code = 22; wordtmp.pro = '-'; }
    else if (ch == ',')  { wordtmp.code = 23; wordtmp.pro = ','; }
    else                 { wordtmp.code = 100; wordtmp.pro = ch; }
    return wordtmp;
}

void GetChar()  //读字符
{
    if (flag == 0)
        ch = getchar();
    else
        flag = 0;
}

void GetBC()    //空格回车
{
    if (ch == ' ' || ch == '\n' || ch == '\t')
    {
        ch = getchar();
    }
}

bool IsLetter(char c)   //判断自定义字符
{
    if (c >= 'a' && c <= 'z')
    {
        return true;
    }
    if (c >= 'A' && c <= 'Z')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsDigit(char c)    //判断数字
{
    if (c >= '0' && c <= '9')
    {
        return true;
    }
    else
    {
        return false;
    }
}

string Concat(string str){  //连接字母
    string c;
    c.push_back(ch);
    str += c;
    return str;
}

void Retract() {    //回溯标记
    flag = 1;
}

int Reserve(string str) {   //查表
    for (int i = 0; i < 24; i++)
    {
        if (!str.compare(codestring[i]))
            return i+1;
    }
    return 0;
}

