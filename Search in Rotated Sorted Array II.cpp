#include <iostream>
using namespace std;

bool search(vector<int>& nums, int target) {
	int first = 0;
	int last = nums.size() - 1;
        
	while (first <= last) {
		int middle = (first + last)/2;

		/* If the middle element equals to the target, then return true. */
		if (target == nums[middle])
			return true;

		/* Locate the middle element. */
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
				/* Skip the duplicate item in the array. */
				first++;
		}
	}
	return false;
}

int main() {
	return 0;
}
