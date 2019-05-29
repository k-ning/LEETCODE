//
//  main.cpp
//  Median of Two Sorted Arrays
//
//  Created by 唧唧歪歪 on 15/4/29.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    //查找两个已经排序好数组的中间值；
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int i;//表示临时变量；
        int l1,l2;//表示两个数组的指针；
        l1=0;
        l2=0;
        vector<int> nums3;//表示临时变量；
        int size=(int)nums1.size()+(int)nums2.size();
        
        /* Sort two arrays according to the size. */
        for(i=0;i<size;i++)
        {
            //条件；
                if((l1 < nums1.size())&&(l2 < nums2.size()))
                {
                        if(nums1[l1] > nums2[l2])
                        {
                                nums3.push_back(nums2[l2]);
                                l2++;
                        }
                        else if(nums1[l1] <= nums2[l2])
                        {
                                nums3.push_back(nums1[l1]);
                                l1++;
                        }
                }
        }
        while(l2 < nums2.size())
        {
                nums3.push_back(nums2[l2++]);
        }
        while(l1 < nums1.size())
        {
                nums3.push_back(nums1[l1++]);
        }
        /*
        cout<<"合并完成的数组为:"<<endl;
        for(i=0;i<(int)nums3.size();i++)
        {
            cout<<nums3[i]<<" ";
        }
        cout<<endl;
        */
        int mid = nums3.size()/2;
        if (nums3.size()%2 == 0) {
                return (double)((nums3[mid]+nums3[mid-1])/2.00);
        } else {
                return (double)nums3[mid];
        }
    }
};

//主函数；
int main()
{
        vector<int> nums1,nums2;//表示两个数组；
        int size1,size2;//表示两个数组的大小；
        cout<<"请输入两个数组的大小:"<<endl;
        cin>>size1>>size2;
        cout<<"请输入第一个数组的"<<size1<<"个数据:"<<endl;
        int i;
        int temp;
        for(i=0;i<size1;i++)
        {
                cin>>temp;
                nums1.push_back(temp);
        }
        cout<<"请输入第二个数组的"<<size2<<"个数据:"<<endl;
        for(i=0;i<size2;i++)
        {
                cin>>temp;
                nums2.push_back(temp);
        }
        Solution ss;
        cout<<"两个数组的中值为:"<<ss.findMedianSortedArrays(nums1,nums2)<<endl;
}
