#include <iostream>
using namespace std;

// Method One:
// Sort() method first and if two elements are equal, then
// they must adjacent in the sorted array.
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
		} else if (nums[current] == nums[next]) {
			temp.push_back(nums[current]);
			current = next + 1;
		}
		next = current + 1;

	}
	return temp;
}

// Method Two:
// Abstract this issue from finding the duplicate items
// in the array into the module of hash searching method.
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

