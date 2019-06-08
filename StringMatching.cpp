//
//  main.cpp
//  字符串匹配
//
//  Created by 唧唧歪歪 on 15/4/22.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

//字符串匹配；
int stringMatch(string str1,string str2,int pos)
{
    int i,j;//表示临时变量；
    i=pos;
    j=0;
    while(i<str1.length()&&j<str2.length())
    {
        if(str1[i]==str2[j])
        {
            i++;
            j++;
        }
        else
        {
            i=i-j+2;
            j=1;
        }
    }
    if(j!=str2.length())
    {
        return -1;
    }
    else
    {
        return i-(int)str2.length()+1;
    }
}
int main()
{
    string str1;
    string str2;
    cout<<"请输入字符串str1:"<<endl;
    cin>>str1;
    cout<<"请输入字符串str2:"<<endl;
    cin>>str2;
    int pos=stringMatch(str1,str2,0);
    if(pos!=-1)
    {
        cout<<pos<<endl;
    }
    else
    {
        cout<<"查找失败!"<<endl;
    }
}
