#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(const vector<int>& nums, int target) {
        vector<int> result(2, -1);
        result[0] = findLeftIndex(nums, target);
        result[1] = findRightIndex(nums, target);
        return result;
    }

private:
    int findLeftIndex(const vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (left < nums.size() && nums[left] == target) {
            return left;
        }
        return -1;
    }

    int findRightIndex(const vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (right >= 0 && nums[right] == target) {
            return right;
        }
        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> nums1;
    nums1.push_back(5);
    nums1.push_back(7);
    nums1.push_back(7);
    nums1.push_back(8);
    nums1.push_back(8);
    nums1.push_back(10);
    int target1 = 8;
    vector<int> result1 = sol.searchRange(nums1, target1);
    cout << "Input: nums = [5,7,7,8,8,10], target = 8" << endl;
    cout << "Output: [" << result1[0] << "," << result1[1] << "]" << endl;

    vector<int> nums2;
    nums2.push_back(5);
    nums2.push_back(7);
    nums2.push_back(7);
    nums2.push_back(8);
    nums2.push_back(8);
    nums2.push_back(10);
    int target2 = 6;
    vector<int> result2 = sol.searchRange(nums2, target2);
    cout << "Input: nums = [5,7,7,8,8,10], target = 6" << endl;
    cout << "Output: [" << result2[0] << "," << result2[1] << "]" << endl;

    vector<int> nums3;
    int target3 = 0;
    vector<int> result3 = sol.searchRange(nums3, target3);
    cout << "Input: nums = [], target = 0" << endl;
    cout << "Output: [" << result3[0] << "," << result3[1] << "]" << endl;
	system("pause");
    return 0;
}
