//题目：n个骰子扔在地上，所有骰子朝上一面的点数之和为s，输入n，打印出s所有可能出现的概率

//首先我们考虑递归的做法
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#pragma warning(disable : 4996)
#define TOTAL 166
using namespace std;
//扑克牌堆里取五张牌，判断是不是顺子，大小王可以看成任意数值
int Com(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}
bool is_continues(int* number,int length)
{
    //简单的做法是排序后看缺的大小够不够0来补
    if(length<1 || number==nullptr)
        return false;
    qsort(number,length,sizeof(int),Com);
    int zeronum=0;
    int cutnum=0;
    for(int i=0;i<length;i++)
    {
        if(number[i]==0)
            zeronum++;
    }
    //使用两个指针检查gap的个数
    int left=0;
    int right=left+1;    
    while(right<length)
    {
        if(number[left]==number[right])
            return false;
        cutnum+=number[left]-number[right]-1;
        left=right;
        right++;
    }
    return zeronum>=cutnum;
}
