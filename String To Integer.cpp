//
//  main.cpp
//  String To Integer
//
//  Created by 唧唧歪歪 on 15/5/7.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        int signal=0;
        if (str=="")
        {
            return 0;
        }
        
        vector<char> ss;
        int i=0;
        while (str[i]==32&&i<str.length())
        {
            i++;
        }
        if(i==str.length())
        {
            return 0;
        }
        
        if (str[i]=='-')
        {
            signal=-1;
            i++;
        }
        else if(str[i]=='+')
        {
            signal=1;
            i++;
        }
        else
        {
            signal=1;
        }
        while (str[i]>='0'&&str[i]<='9')
        {
            ss.push_back(str[i]);
            i++;
        }
        
        if(ss.size()==0)
        {
            return 0;
        }
        if(ss.size()>10)
        {
            if(signal==1)
                return 2147483647;
            else
                return -2147483648;
        }
        int base=0;
        for (i=0;i<ss.size();i++)
        {
            if(base>(2147483647/10))
            {
                if(signal==1)
                {
                    return 2147483647;
                }
                else
                {
                    return -2147483648;
                }
            }
            if(base==(2147483647/10)&&signal==1&&ss[i]-'0'>7)
            {
                return 2147483647;
            }
            else if(base==(2147483647/10)&&signal==-1&&ss[i]-'0'>8)
            {
                return -2147483648;
            }
            base=base*10+(ss[i]-'0');
        }
        return base*signal;
    }
};
int main()
{
    string str="   -2147483648";
    Solution ss;
    cout<<"转化为整型:"<<ss.myAtoi(str)<<endl;
}
