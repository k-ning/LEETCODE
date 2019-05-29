#include <iostream>
using namespace std;

/*
 * Testing Cases:
 *	[1]	1
 *	[]	-1
 *	[3, 1]	2
 */

int search(vector<int>& nums, int target) {
	int first = 0;
	int last = nums.size() - 1;

	while(first <= last) {
		int mid = (first + last)/2;

		if (target == nums[mid])
			return mid;

		if (nums[first] <= nums[mid]) {
			if (target >= nums[first] && target < nums[mid]) {
				last = mid;
			}
			else
				first = mid + 1;
		} else {
			if (target > nums[mid] && target <= nums[last]) {
				first = mid + 1;
			}
			else
				last = mid;
		}
	}
	return -1;
}
