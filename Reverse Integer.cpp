//
//  main.cpp
//  Reverse Integer
//
//  Created by 唧唧歪歪 on 15/5/4.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        vector<int> tt;//表示当前数组临时变量；
        int type=0;//表示当前整形的类型；
        if(x>0)
        {
            type=1;
        }
        else
        {
            type=-1;
        }
        int temp=abs(x);//取绝对值；
        int divider=0;//表示除数；
        int remainder=0;//表示余数；
        
        if(temp==0)
        {
            return 0;
        }
        while(temp!=0)
        {
            divider=temp/10;
            remainder=temp%10;
            
            tt.push_back(remainder);
            temp=temp/10;
        }
        int i;
        temp=0;
        int size=(int)tt.size();
        
        if(size==10)
        {
            if(tt[0]>=3)
            {
                return 0;
            }
        }
        long double dd=0;
        int m=1;
        for(i=size-1;i>=0;i--)
        {
            dd+=m*tt[i];
            m=m*10;
            
            if(dd>2147483647)
            {
                return 0;
            }
        }
        
        if(type<0)
        {
            return (-1)*dd;
        }
        return dd;
    }
};
int main()
{
    cout<<"请输入一个整数:"<<endl;
    int t;
    Solution ss;
    
    while(cin>>t)
    {
        cout<<"数字转化为字符串为:"<<ss.reverse(t)<<endl;
    }
}
