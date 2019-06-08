//
//  main.cpp
//  最长回文子串(DB)
//
//  Created by 唧唧歪歪 on 15/5/4.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int i,j;//表示临时变量；
        
        int vv[1000][1000]={-1};
        int length=(int)s.length();
        /*
        //数组初始化；
        vector<vector<int>> v(length);
        vector<int> temp(length);
        for(i=0;i<length;i++)
        {
            v[i]=temp;
        }
        */
        //初始化数组的所有元素；
        for(i=0;i<length;i++)
        {
            for(j=0;j<length;j++)
            {
                vv[i][j]=-1;
                
                if(j<=i)
                {
                    vv[i][j]=1;
                }
            }
        }
        
        //字符表初始化；
        for(i=0;i<length-1;i++)
        {
            //设置所有长度为2的字符串是否属于回文子串；
            if(s[i]==s[i+1])
            {
                vv[i][i+1]=1;
            }
            else
            {
                vv[i][i+1]=0;
            }
        }
        
        for(i=length-3;i>=0;i--)
        {
            for(j=i+2;j<length;j++)
            {
                if(s[i]==s[j])
                {
                    vv[i][j]=vv[i+1][j-1];
                }
                else
                {
                    vv[i][j]=0;
                }
            }
        }
        int maxI=0,maxJ=0;//分别表示最大的x与y坐标；
        int max=0;//表示最大的length长度；
        for(i=0;i<length;i++)
        {
            for(j=i;j<length;j++)
            {
                if(vv[i][j]==1&&(j-i+1)>max)
                {
                    max=j-i+1;
                    maxI=i;
                    maxJ=j;
                }
            }
        }
        string ss;
        for(i=maxI;i<=maxJ;i++)
        {
            ss+=s[i];
        }
        return ss;
    }
};

int main()
{
    string str;
    cout<<"请输入字符串str"<<endl;
    cin>>str;
    Solution ss;
    cout<<"最长回文子串为:"<<ss.longestPalindrome(str)<<endl;
}
