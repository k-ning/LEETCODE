#include <iostream>
using namespace std;

int singleNumber(vector<int>& nums) {
        
        if (nums.size() == 1)
                return nums[0];
        
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int j = 1;
        
        while (i < nums.size() - 1 && j < nums.size()) {
                if (nums[i] == nums[j]) {
                        i = j + 1;
                        j = i + 1;
                } else {
                        return nums[i];
                }
        }
        return nums[i];
}
