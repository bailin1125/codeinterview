//题目：n个骰子扔在地上，所有骰子朝上一面的点数之和为s，输入n，打印出s所有可能出现的概率

//首先我们考虑递归的做法
#include <list>
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#pragma warning(disable : 4996)
#define TOTAL 166
using namespace std;

//典型的约瑟夫环问题
int last_number(int n,int m)
{
    if(n<1||m<1)
        return -1;
    list<int> lt;
    for(int i=0;i<n;i++)
    {
        lt.push_back(i);
    }
    list<int>::iterator it=lt.begin();
    while(lt.size()>1)
    {
        for(int i=1;i<m;i++)
        {
            it++;
            if(it==lt.begin())
                it=lt.end();
        }
        //然后开始准备删除了
        list<int>::iterator next=++it;
        if(next==lt.end())
            next=lt.begin();
        it--;
        lt.erase(it);
        it=next;
    }
    return (*it);
}
