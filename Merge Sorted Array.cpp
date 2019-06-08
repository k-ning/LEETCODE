//
//  main.cpp
//  Merge Sorted Array
//
//  Created by 唧唧歪歪 on 15/5/9.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
                if (n == 0) {
                        return;
                }
                int i = m - 1;
                int j = n - 1;
                int k = m + n - 1;
                
                /* 原址排序. */
                while (i >= 0 && j >= 0) {

                        nums1[k--] = nums1[i] >= nums2[j] ? nums1[i--] : nums2[j--];
                        /* can be replaced. */
                        /*
                        if (nums1[i] > nums2[j]) {
                                nums1[k--] = nums1[i--];
                        } else if (nums1[i] < nums2[j]) {
                                nums1[k--] = nums2[j--];
                        } else if (nums1[i] == nums2[j]) {
                                nums1[k--] = nums1[i--];
                                nums1[k--] = nums2[j--];
                        }
                        */
                }
                /* can be omitted. */
                /*
                while (i != -1) {
                        nums1[k--] = nums1[i--];
                }
                */
                while (j != -1) {
                        nums1[k--] = nums2[j--];
                }
        }
};

int main() {

}
