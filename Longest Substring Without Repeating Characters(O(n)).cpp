//
//  main.cpp
//  Longest Substring Without Repeating Characters(O(n))
//
//  Created by 唧唧歪歪 on 15/4/29.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char,int> map;
        int i;
        int count=0;
        int maxlen=0;
        //count表示当前考虑的子串的长度；
        for(i=0;i<s.size();i++)
        {
            count++;
            if(map.count(s[i])!=0&&map[s[i]]>i-count)
            {
                count=i-map[s[i]];
            }
            map[s[i]]=i;
            if(maxlen<count)
            {
                maxlen=count;
            }
        }
        return maxlen;
    }
};
int main()
{
    Solution ss;
    cout<<"请输入字符串s"<<endl;
    string str;
    while(cin>>str)
    {
        cout<<"最长不重复字串为:"<<ss.lengthOfLongestSubstring(str)<<endl;
        cout<<"请输入字符串s"<<endl;
    }
}
