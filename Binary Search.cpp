//
//  main.cpp
//  Binary Search
//
//  Created by 唧唧歪歪 on 15/4/29.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include<iostream>
#include<vector>
using namespace std;

//二分搜索查找中间值；
int Binary_Search(vector<int> v,int value)
{
        int i;//表示临时变量；
        int low=0;
        int high=(int)v.size()-1;
        int mid=(low+high)/2;
    
        for(i=low;i<=high;i++)
        {
                if(v[mid]>value)
                {
                        high=mid;
                        mid=(low+high)/2;
                }
                else if(v[mid]<value)
                {
                        low=mid;
                        mid=(low+high)/2;
                }
                else if(v[mid]==value)
                {
                        return mid;
                }
        }
        return mid;
}

int main()
{
        int size;
        cout<<"请输入数组的大小:"<<endl;
        cin>>size;
        int i;
        int temp;
        cout<<"请输入"<<size<<"个数据:"<<endl;
        vector<int> v;//表示临时数据数组；
        for(i=0;i<size;i++)
        {
                cin>>temp;
                v.push_back(temp);
        }
        cout<<"请输入需要查找的数据"<<endl;
    
        int N;
        cin>>N;
        cout<<N<<"是第"<<Binary_Search(v,N)+1<<"个位置!"<<endl;
}
