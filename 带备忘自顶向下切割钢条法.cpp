//
//  main.cpp
//  带备忘自顶向下切割钢条法
//
//  Created by 唧唧歪歪 on 15/4/27.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//
#include<iostream>
#include<vector>
using namespace std;
int Memorized_Cut_Rod_Aux(vector<int> p,vector<int> &v,int n);
int Memorized_Cut_Rod(vector<int> p,int n);

//带备忘的自顶向下动态规划；
int Memorized_Cut_Rod(vector<int> p,int n)
{
    vector<int> v;
    int i;
    for(i=0;i<=n;i++)
    {
        v.push_back(-99999);
    }
    return Memorized_Cut_Rod_Aux(p,v,n);
}

//带备忘的自顶向下动态规划；
int Memorized_Cut_Rod_Aux(vector<int> p,vector<int> &v,int n)
{
    if(v[n]>=0)
    {
        return v[n];
    }
    if(n==0)
    {
        return 0;
    }
    int q=-99999;
    int temp=0;
    int i;//表示临时变量；
    for(i=1;i<=n;i++)
    {
        temp=p[i]+Memorized_Cut_Rod_Aux(p,v,n-i);
        
        if(q<=temp)
        {
            q=temp;
        }
    }
    v[n]=q;
    return q;
}

int main()
{
    vector<int> p;
    p.push_back(0);
    int size;
    cout<<"请输入数组的大小:"<<endl;
    cin>>size;
    int i;//表示临时变量；
    int temp;
    cout<<"请输入"<<size<<"个数据:"<<endl;
    for(i=0;i<size;i++)
    {
        cin>>temp;
        p.push_back(temp);
    }
    int n;
    cout<<"请输入求解的n值:"<<endl;
    cin>>n;
    while(n)
    {
        cout<<"最大收益为:"<<Memorized_Cut_Rod(p,n)<<endl;
        cout<<"请输入求解的n值:"<<endl;
        cin>>n;
    }
}
