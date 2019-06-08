//
//  main.cpp
//  Cut_Rod
//
//  Created by 唧唧歪歪 on 15/4/27.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


//利用朴素递归求解钢条切割的最大收益；
int CutRod(vector<int> p,int n)
{
    if(n==0)
    {
        return 0;
    }
    int q=-99999;//表示最大收益；
    int i;
    for(i=1;i<=n;i++)
    {
        int temp=p[i]+CutRod(p,n-i);
        if(q<temp)
        {
            q=temp;
        }
    }
    return q;
}

//主函数；
int main()
{
    vector<int> p;
    p.push_back(0);
    int size;
    cout<<"请输入数组的数量:"<<endl;
    cin>>size;
    cout<<"请输入"<<size<<"个数据:"<<endl;
    int i;//表示临时变量；
    int temp;
    for(i=0;i<size;i++)
    {
        cin>>temp;
        p.push_back(temp);
    }
    while(1)
    {
        cout<<"请输入需要计算的n的值:"<<endl;
        int n;
        cin>>n;
        cout<<"最大收益为:"<<CutRod(p,n)<<endl;
    }
}
