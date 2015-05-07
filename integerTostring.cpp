//
//  main.cpp
//  integer
//
//  Created by 唧唧歪歪 on 15/5/7.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include<iostream>
#include<string>
using namespace std;
//将整数转化为字符串类型；
string Convert(int t)
{
    string temp;
    
    int tt=t;
    int divider;
    int remainder;
    int type;
    
    if(t<0)
    {
        type=-1;
    }
    else
    {
        type=1;
    }
    
    tt=abs(t);
    if(tt==0)
    {
        temp="0";
        return temp;
    }
    
    while(tt!=0)
    {
        divider=tt/10;
        remainder=tt%10;
        tt=tt/10;
        
        switch (remainder)
        {
            case 0:
            {
                temp+="0";
            };break;
            case 1:
            {
                temp+="1";
            };break;
            case 2:
            {
                temp+="2";
            };break;
            case 3:
            {
                temp+="3";
            };break;
            case 4:
            {
                temp+="4";
            };break;
            case 5:
            {
                temp+="5";
            };break;
            case 6:
            {
                temp+="6";
            };break;
            case 7:
            {
                temp+="7";
            };break;
            case 8:
            {
                temp+="8";
            };break;
            case 9:
            {
                temp+="9";
            };break;
        }
    }
    string str;
    if(type==1)
    {
        char * ch=new char [temp.length()];
        int i;//表示临时变量；
        
        for(i=0;i<temp.length();i++)
        {
            ch[i]=temp[temp.length()-i-1];
        }
        str=ch;
    }
    else
    {
        char * ch=new char [temp.length()+1];
        int i;//表示临时变量；
        
        ch[0]='-';
        for(i=0;i<temp.length()+1;i++)
        {
            ch[i+1]=temp[temp.length()-i-1];
        }
        str=ch;
    }
    
    return str;
}

int main()
{
    int t;
    while(cin>>t)
    {
        cout<<"经过转换的字符串为:"<<Convert(t)<<endl;
    }
}
