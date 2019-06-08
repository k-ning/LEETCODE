//
//  main.cpp
//  自底向上动态规划算法
//
//  Created by 唧唧歪歪 on 15/4/27.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
//自底向上动态规划求解切割钢条；
int Bottom_Up_Cut_Rod(vector<int> p,int n)
{
    vector<int> r;
    int i,j;
    for(i=0;i<=n;i++)
    {
        r.push_back(-99999);
    }
    r[0]=0;
    
    int q;
    int temp;//临时变量；
    for(j=1;j<=n;j++)
    {
        q=-99999;
        for(i=1;i<=j;i++)
        {
            temp=p[i]+r[j-i];
            if(q<temp)
            {
                q=temp;
            }
        }
        r[j]=q;
    }
    return r[n];
}
//主函数；
int main()
{
    vector<int> p;
    p.push_back(0);
    int size;
    cout<<"请输入数组的大小:"<<endl;
    cin>>size;
    int i;
    int temp;
    cout<<"请输入"<<temp<<"个数据:"<<endl;
    for(i=0;i<size;i++)
    {
        cin>>temp;
        p.push_back(temp);
    }
    int n;
    cout<<"请输入要计算的钢条长度:"<<endl;
    cin>>n;
    while(1)
    {
        cout<<"最大利益为:"<<Bottom_Up_Cut_Rod(p,n)<<endl;
        cout<<endl;
        cout<<"请输入要计算的钢条长度:"<<endl;
        cin>>n;
    }
}
