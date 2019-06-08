//
//  main.cpp
//  Find Minimum in Rotated Sorted Array II
//
//  Created by 唧唧歪歪 on 15/5/18.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    //查找当前数组中的最小数字;
    int findMin(vector<int>& nums)
    {
        int low,high;//表示两个临时指针;
        int mid;//表示临时变量;
        
        low=0;
        high=(int)nums.size()-1;
        mid=(low+high)/2;
        //排除异常情况;
        if(nums[low]<nums[high])
        {
            return nums[low];
        }
        //利用二分法查找旋转数组中最小的数字;
        while(high!=(low+1))
        {
            if(nums[mid]>nums[low])
            {
                low=mid;
                mid=(high+low)/2;
            }
            else if(nums[mid]<nums[low])
            {
                high=mid;
                mid=(high+low)/2;
            }
            else
            {
                if(nums[low]==nums[high])
                {
                    return min(nums);
                }
                else
                {
                    low=mid;
                    mid=(high+low)/2;
                }
            }
        }
        return nums[high];
    }
    //查找数组中的最小值;
    int min(vector<int>& nums)
    {
        int i=0;
        int min=99999;
        while(i<nums.size())
        {
            if(min>nums[i])
            {
                min=nums[i];
            }
            i++;
        }
        return min;
    }
};

int main()
{
    vector<int> v={3,3,1};
    Solution ss;
    cout<<ss.findMin(v)<<endl;
}
