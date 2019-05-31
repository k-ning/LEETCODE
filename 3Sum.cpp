#include <iostream>
using namespace std;

/* The first version of threeSums which exceeds the limited time. */
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> temp;

        if (nums.size() < 3) {
                return result;
        }
        sort(nums.begin(), nums.end());

        for (int i = 0;i < nums.size() - 2;i++) {
                for (int j = i + 1; j < nums.size() - 1;j++) {
                        for (int k = j + 1; k < nums.size();k++) {
                                if (nums[i] + nums[j] + nums[k] == 0) {
                                        vector<int> tmp;
                                        tmp.push_back(nums[i]);
                                        tmp.push_back(nums[j]);
                                        tmp.push_back(nums[k]);
                                        temp.insert(tmp);
                                }
                        }
                }
        }
        for(auto t:temp) {
                result.push_back(t);
        }
        return result;
}

/* The second version of threeSum. */
vector<vector<int>> threeSum_2(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) {
                return result;
        }
        sort (nums.begin(), nums.end());
        for (int i = 0;i < nums.size() - 2;i++) {
                if (i > 0 && nums[i] == nums[i-1])
                        continue;
                while (j < k) {
                        int sum = nums[i] + nums[j] + nums[k];

                        if(sum < 0) {
                                j++;
                        } else if(sum > 0) {
                                k--;
                        } else {
                                result.push_back({nums[i], nums[j], nums[k]});
                                j++;
                                while (nums[j] == nums[j-1] && j < k) j++;
                                k--;
                                while (nums[k] == nums[k+1] && j < k) k--;
                        }
                }
        }
        return result;
}
