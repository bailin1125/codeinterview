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

//股票的最大利润，这个比较简单
int max_profit(int *number,int length)
{
    //我们遍历一次，记住i之前的最小值，及时更新最大利润
    if(number==NULL || length<2)
        return 0;
    int minval=number[0];
    int max_fit=number[1]-minval;
    for(int i=2;i<length;i++)
    {
        if(number[i]<minval)
            minval=number[i];
        int cur=number[i]-minval;
        if(cur>max_fit)
            max_fit=cur;
    }
    return max_fit;
}
