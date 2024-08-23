#include <iostream>
#include <vector>
using namespace std;

int search(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        // Determine which part is sorted
        if (nums[left] <= nums[mid]) { // Left part is sorted
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1; // Target is in the left sorted part
            } else {
                left = mid + 1; // Target is in the right part
            }
        } else { // Right part is sorted
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1; // Target is in the right sorted part
            } else {
                right = mid - 1; // Target is in the left part
            }
        }
    }

    return -1; // Target not found
}

int main() {
    // Initialize vectors using the constructor and push_back
    vector<int> nums1;
    nums1.push_back(4);
    nums1.push_back(5);
    nums1.push_back(6);
    nums1.push_back(7);
    nums1.push_back(0);
    nums1.push_back(1);
    nums1.push_back(2);

    vector<int> nums2;
    nums2.push_back(4);
    nums2.push_back(5);
    nums2.push_back(6);
    nums2.push_back(7);
    nums2.push_back(0);
    nums2.push_back(1);
    nums2.push_back(2);

    vector<int> nums3;
    nums3.push_back(1);

    int target1 = 0;
    int target2 = 3;
    int target3 = 0;

    cout << "Input: nums = [4, 5, 6, 7, 0, 1, 2], target = 0" << endl;
    cout << "Output: " << search(nums1, target1) << endl; // Output: 4

    cout << "Input: nums = [4, 5, 6, 7, 0, 1, 2], target = 3" << endl;
    cout << "Output: " << search(nums2, target2) << endl; // Output: -1

    cout << "Input: nums = [1], target = 0" << endl;
    cout << "Output: " << search(nums3, target3) << endl; // Output: -1
	system("pause");
    return 0;
}
