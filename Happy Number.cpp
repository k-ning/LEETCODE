//
//  main.cpp
//  Happy Number
//
//  Created by 唧唧歪歪 on 15/5/18.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include <iostream>
#include <map>
#include <stack>
using namespace std;
class Solution
{
public:
    //判断当前的n是否为开心数;
    bool isHappy(int n)
    {
        int temp=n;
        map<int,int> m;//表示存放结果的数据结构;
        stack<int> ss=singleDigit(temp);//转换为数组；
        int square=squareDigit(ss);//转换为平方和;
        
        while(square!=1&&m.find(square)==m.end())
        {
            m[temp]=square;
            
            temp=square;
            ss=singleDigit(temp);
            square=squareDigit(ss);
        }
        if(square==1)
        {
            return true;
        }
        else
            return false;
    }
    //将整数转换为数字，并将所有各位数字压入栈中;
    stack<int> singleDigit(int n)
    {
        stack<int> ss;
        int temp=n;
        //排除整数为0的情况;
        if(temp==0)
        {
           ss.push(temp);
        }
        //其余所有情况;
        while(temp!=0)
        {
            ss.push(temp%10);
            temp=temp/10;
        }
        return ss;
    }
    //求解两个数据的平方和;
    int squareDigit(stack<int> & s)
    {
        int sum=0;
        int temp=0;
        while(s.empty()!=true)
        {
            temp=s.top();
            sum+=temp*temp;
            s.pop();
        }
        return sum;
    }
};
int main()
{
    Solution ss;
    bool sit=ss.isHappy(100);
    if(sit==true)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
}
