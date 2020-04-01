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
int max_value=6;
void helper(int original,int cur,int sum,int* pro)
{
    if(cur==1)
    {
        pro[sum-original]++;
    }
    else
    {
        for(int i=1;i<max_value;i++)
        {
            helper(original,cur-1,i+sum,pro);
        }
    }
}
void getprobility(int number, int *probalities)
{
    for(int i=1;i<max_value;i++)
    {
        helper(number,number,i,probalities);
    }
}

void print_probality(int number)
{
    int max_sum=max_value*number;
    int *probalities=new int[max_sum-number+1];
    for (int i = 0; i < max_sum - number + 1;i++)
        probalities[i]=0;
    getprobility(number,probalities);
    int total=pow(max_value,number);

    for (int i = 0; i < max_sum - number + 1;i++)
    {
        double ratio=probalities[i]/total;
        cout<<"s is:"<<i+max_value<<", probaility is:"<<ratio<<endl;
        
    }
    delete[] probalities;
}
