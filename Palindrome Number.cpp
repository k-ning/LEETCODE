//
//  main.cpp
//  Palindrome Number
//
//  Created by 唧唧歪歪 on 15/5/8.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include<iostream>

using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        int t=x;
        int remainder=0;
        int divider=0;
        int base=0;
        int i=0;
        if(x<0)
        {
            return false;
        }
        
        while (t!=0)
        {
            i++;
            remainder=t%10;
            divider=t/10;
            t=t/10;
            
            base=base*10+remainder;
            if(i==10&&base>214748364&&remainder>7)
            {
                return false;
            }
        }
        if(base==x)
            return true;
        else
            return false;
    }
};

int main()
{
    int t;
    cout<<"请输入一个整数:"<<endl;
    while (cin>>t)
    {
        Solution ss;
        if(ss.isPalindrome(t)==true)
        {
            cout<<t<<"是一个回文数!"<<endl;
        }
        else
            cout<<t<<"不是一个回文数!"<<endl;
        cout<<"请输入一个整数:"<<endl;
    }
}
