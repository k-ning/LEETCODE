//
//  main.cpp
//  ZigZag Conversion
//
//  Created by 唧唧歪歪 on 15/5/4.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
    string convert(string s,int numRows)
    {
        int i,j;//表示临时变量；
        string temp;//表示临时string变量；
        if(numRows==1||s.length()==1||s.length()/numRows<1)
        {
            return s;
        }
        for(i=1;i<=numRows;i++)
        {
            temp+=s[i-1];
            j=i-1;
            while(j<s.length())
            {
                //表示不是最后一行；
                if(i!=numRows)
                {
                    j+=(numRows-i)*2;
                    //表示从下往上需要加的项目；
                    if(j<s.length())
                    {
                        temp+=s[j];
                    }
                    else
                    {
                        break;
                    }
                }
                
                //表示不是第一行；
                //表示从上往下需要加的项目；
                if(i!=1)
                {
                    j+=(i-1)*2;
                    if(j<s.length())
                    {
                        temp+=s[j];
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return temp;
    }
};

int main()
{
    string str;
    cout<<"请输入字符串str:"<<endl;
    cin>>str;
    cout<<"请输入ZigZag的行数:"<<endl;
    int row;
    cin>>row;
    Solution ss;
    cout<<"经过ZigZag变换后的字符串为:"<<ss.convert(str,row)<<endl;
}
