#include <iostream>
using namespace std;

bool search(vector<int>& nums, int target) {
	int first = 0;
	int last = nums.size() - 1;
        
	while (first <= last) {
		int middle = (first + last)/2;
            
		if (target == nums[middle])
			return true;
            
		if (nums[middle] > nums[first]) {
			if (target >= nums[first] && target < nums[middle])
				last = middle;
			else
				first = middle + 1;
		} else if (nums[middle] < nums[first]) {
			if (target > nums[middle] && target <= nums[last])
				first = middle + 1;
			else
				last = middle;
			} else if (nums[middle] == nums[first]) {
				first++;
		}
	}
	return false;
}

int main() {
	return 0;
}
