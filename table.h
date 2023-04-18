#ifndef TABLE_H
#define TABLE_H
#include <string>
using namespace std;
class Table
{
    int row_num,line_num;
    string rowName[10];
    int lineName[14];
    string tableData[10][14];
public:
    Table();
    string getCell(string rowN,int lineN);
    int getRowNumber(string rowN);
    int getLineNumber(int lineN);
};

#endif // TABLE_H
