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

// Method Two.
// A great method which uses the original array to sort.
// Using the hash searching method.
vector<int> findDuplicates(vector<int>& nums) {
	int num = 0;
	vector<int> temp;

	if (nums.size() == 0) {
		return temp;
	}
	
	for (int i = 0; i < nums.size(); i++) {
		num = abs(nums[i]);

		if (nums[num - 1] < 0) {
			temp.push_back(num);
		} else if (nums[num - 1] > 0) {
			nums[num - 1] *= -1;
		}
	}
	return temp;
}

