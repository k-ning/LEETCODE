//
//  main.cpp
//  Excel Sheet Column Number
//
//  Created by 唧唧歪歪 on 15/5/18.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include<iostream>
#include<map>
#include<cmath>
using namespace std;
class Solution
{
public:
    int titleToNumber(string s)
    {
        map<char,int> mm;
        int i=1;
        char ch='A';
        while(i<=26)
        {
            mm[ch+i-1]=i;
            i++;
        }
        
        int size=(int)s.length();
        i=size-1;
        int t=0;
        int sum=0;
        while(i>=0)
        {
            sum=sum+mm[s[i]]*pow(26,t);
            t++;
            i--;
        }
        return sum;
    }
};
int main()
{
    Solution ss;
    cout<<ss.titleToNumber("")<<endl;
}
