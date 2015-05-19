//
//  main.cpp
//  Excel Sheet Column Title
//
//  Created by 唧唧歪歪 on 15/5/18.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include<iostream>
#include<map>
#include<stack>
#include<string>
using  namespace std;
class Solution
{
public:
    string convertToTitle(int n)
    {
        map<int,char> mm;
        int i=0;
        while(i<26)
        {
            mm[i+1]='A'+i;
            i++;
        }
        int temp=n;
        string ss;
        if(temp<=26)
        {
            ss=mm[temp];
            return ss;
        }
        stack<int> s;//表示栈的数据结构;
        
        bool ischange=false;
        int tt;
        while((temp/26)!=0)
        {
            tt=temp%26;
            
            if(tt==0&&ischange==false)
            {
                s.push(26);
                temp=temp/26;
                ischange=true;
            }
            else if((tt==1||tt==0)&&ischange==true)
            {
                s.push(26);
                temp=temp/26;
                ischange=true;
            }
            else if(ischange==true)
            {
                s.push(tt-1);
                temp=temp/26;
                ischange=false;
            }
            else
            {
                s.push(tt);
                temp=temp/26;
            }
        }
        if(temp%26!=0)
        {
            if(ischange==true&&temp%26!=1)
            {
                s.push(temp%26-1);
            }
            else if(ischange==false)
            {
                s.push(temp%26);
            }
        }
        while(s.empty()!=true)
        {
            temp=s.top();
            if(temp!=0)
            {
                ss+=mm[temp];
            }
            s.pop();
        }
        return ss;
    }
};
int main()
{
    Solution ss;
    cout<<ss.convertToTitle(702)<<endl;
}
