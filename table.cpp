#include <string>
#include <table.h>
using namespace std;

Table::Table()      //词法分析表
{
    row_num=10;
    line_num=14;

    rowName[0]="S";
    rowName[1]="A";
    rowName[2]="F";
    rowName[3]="G";
    rowName[4]="P";
    rowName[5]="B";
    rowName[6]="E";
    rowName[7]="C";
    rowName[8]="D";
    rowName[9]="H";

    lineName[0]=8;
    lineName[1]=9;
    lineName[2]=14;
    lineName[3]=1;
    lineName[4]=2;
    lineName[5]=3;
    lineName[6]=4;
    lineName[7]=100;
    lineName[8]=5;
    lineName[9]=6;
    lineName[10]=7;
    lineName[11]=13;
    lineName[12]=10;
    lineName[13]=11;



    for (int i=0;i<10;i++)
        for(int j=0;j<14;j++)
            tableData[i][j]="";

    tableData[0][0]="ABCDE";

    tableData[1][0]="<!F!>";

    tableData[2][1]="";

    tableData[2][3]="G=PF";
    tableData[2][4]="G=PF";
    tableData[2][5]="G=PF";
    tableData[2][6]="G=PF";

    tableData[3][3]="System";
    tableData[3][4]="Version";
    tableData[3][5]="Code";
    tableData[3][6]="Data";

    tableData[4][7]="i";

    tableData[5][8]="<P::P>";

    tableData[6][10]="</P::P>";

    tableData[7][12]="@@H";

    tableData[8][10]="";
    tableData[8][13]="#HD";


    tableData[9][7]="PH";
    tableData[9][10]="";
    tableData[9][13]="";
}

string Table::getCell(string rowN, int lineN)       //获取表中元素
{
    int row_idx = getRowNumber(rowN);
    return tableData[row_idx][lineN];
}

int Table::getRowNumber(string rowN)        //获取行下标
{
    for (int i = 0; i < row_num; i++)
    {
        if (rowName[i] == rowN)
        {
            return i;
        }
    }

    return -1;
}

int Table::getLineNumber(int lineN)     //获取列下标
{
    for (int i = 0; i < line_num; i++)
    {
        if (lineName[i] == lineN)
        {
            return i;
        }
    }

    return -1;
}
