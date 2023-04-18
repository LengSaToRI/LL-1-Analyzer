#ifndef STACK_H
#define STACK_H
#include <string>
using namespace std;
class Stack
{
    int i;
    string *data;
public:
    Stack();
    int push(string m);
    int pop();
    string getTop();
    ~Stack();
    int topNumber();
    void outStack();
    void pushReverse(string m);
};

#endif // STACK_H
