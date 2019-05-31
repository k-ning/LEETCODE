#include <iostream>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
        int temp_sum, temp_distance;
        int curr_diff = INT_MAX;
        int min_sum = 0;
        
        if (nums.size() < 3) {
                return min_sum;
        }
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; i++) {
                int j = i + 1;
                int k = nums.size() - 1;
            
                while (j < k) {
                        temp_distance = nums[i] + nums[j] + nums[k] - target;
                
                        if (temp_distance < 0) {
                                j++;
                        } else if (temp_distance > 0) {
                                k--;
                        } else {
                                return target;
                        }
                
                        if (abs(temp_distance) < curr_diff) {
                                curr_diff = abs(temp_distance);
                                min_sum = temp_distance + target;
                        }
                }
        }
        return min_sum;
}
