//
//  main.cpp
//  Majority Element
//
//  Created by 唧唧歪歪 on 15/5/18.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        map<int,int> mm;
        int i=0;
        while(i<nums.size())
        {
            if(mm.find(nums[i])!=mm.end())
            {
                mm[nums[i]]++;
            }
            else
            {
                mm[nums[i]]=1;
            }
            i++;
        }
        i=0;
        int size=(int)nums.size()/2;
        while(i<nums.size()&&mm[nums[i]]<=size)
        {
            i++;
        }
        return nums[i];
    }
};
int main()
{
    int size;
    cout<<"请输入数组大小:"<<endl;
    cin>>size;
    int i=1;//表示临时变量;
    vector<int> v;
    int temp;
    while(i<=size)
    {
        cin>>temp;
        v.push_back(temp);
        i++;
    }
    Solution ss;
    cout<<ss.majorityElement(v)<<endl;
}
