//
//  main.cpp
//  判断是否为回文串
//
//  Created by 唧唧歪歪 on 15/4/30.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include<iostream>
#include<string>
using namespace std;
int Reverse(string str)
{
    char * ch=new char [str.length()];
    int i;
    for(i=(int)str.length();i>0;i--)
    {
        ch[str.length()-i]=str[i-1];
    }
    string reverse=ch;
    if(str==reverse)
    {
        delete ch;
        return true;
    }
    else
    {
        delete ch;
        return false;
    }
}

int main()
{
    string str;
    cout<<"请输入一个字符串:"<<endl;
    cin>>str;
    if(Reverse(str)==true)
    {
        cout<<str<<"是回文子串!"<<endl;
    }
    else
    {
        cout<<str<<"不是回文子串!"<<endl;
    }
}
