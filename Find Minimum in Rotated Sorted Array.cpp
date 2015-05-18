//
//  main.cpp
//  Find Minimum in Rotated Sorted Array
//
//  Created by 唧唧歪歪 on 15/5/18.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int low,high;//表示两个临时指针;
        int mid;//表示临时变量;
        
        low=0;
        high=(int)nums.size()-1;
        mid=(low+high)/2;
        //排除异常情况;
        if(nums[low]<=nums[high])
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
            else
            {
                high=mid;
                mid=(high+low)/2;
            }
        }
        return nums[high];
    }
};

int main()
{
    vector<int> v={0};
    Solution ss;
    cout<<ss.findMin(v)<<endl;
}
