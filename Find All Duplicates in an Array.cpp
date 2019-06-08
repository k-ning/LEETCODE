#include <iostream>
using namespace std;

// Method One.
vector<int> findDuplicates_1(vector<int>& nums) {
	vector<int> temp;
	int current = 0;
	int next = 1;
        
	if (nums.size() == 0)
		return temp;
        
	sort(nums.begin(), nums.end());
        
	while (current < nums.size() && next < nums.size()) {
		if (nums[current] != nums[next]) {
			current = next;
			next ++;
		} else if (nums[current] == nums[next]) {
			temp.push_back(nums[current]);
			current = next + 1;
			next = current + 1;
		}
	}
	return temp;
}

