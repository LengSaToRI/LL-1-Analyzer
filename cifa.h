#ifndef CIFA_H
#define CIFA_H
#include <string>
using namespace std;

struct WordType
{
    int code;   //元素的编号
    string pro; //元素的值
};


WordType get_w();
#endif // CIFA_H
