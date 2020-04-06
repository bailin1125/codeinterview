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
//我们再用一下非递归的做法，使用两个数组来保存中间数值
void print_probality(int number)
{
    if(number<1)
        return;
    int **pro=new int*[2];
    for(int i=0;i<2;i++)
    {
        pro[i]=new int[max_value*number+1];
        for(int j=0;j<max_value*number+1;j++)
            pro[i][j]=0;
    }
    int flag=0;//用来标记当前处理的是什么数组
    //然后给当前的赋初值
    for(int i=1;i<=max_value;i++)
    {
        pro[flag][i]=1;
    }
    //然后从第二个骰子开始放
    for(int k=2;k<=number;k++)
    {
        for(int i=0;i<k;i++)
            pro[1-flag][i]=0;
        for(int i=k;i<max_value*k;i++)
        {
            pro[1-flag][i]=0;
            for(int j=1;j<=i && j<=max_value;j++)
            {
                pro[1-flag][i]+=pro[flag][i-j];
            }
        }
        flag=1-flag;
    }
    delete[]pro[0];
    delete []pro[1];
    delete[]pro;
}
