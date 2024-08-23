#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int k = 1;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[i - 1]) {
            nums[k++] = nums[i];
        }
    }
    return k;
}

void printArray(const vector<int>& nums, int k) {
    for (int i = 0; i < k; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(1);
    nums1.push_back(2);
    
    int k1 = removeDuplicates(nums1);
    cout << "Output: " << k1 << ", nums = ";
    printArray(nums1, k1);
    
    vector<int> nums2;
    nums2.push_back(0);
    nums2.push_back(0);
    nums2.push_back(1);
    nums2.push_back(1);
    nums2.push_back(1);
    nums2.push_back(2);
    nums2.push_back(2);
    nums2.push_back(3);
    nums2.push_back(3);
    nums2.push_back(4);
    
    int k2 = removeDuplicates(nums2);
    cout << "Output: " << k2 << ", nums = ";
    printArray(nums2, k2);
	system("pause");
    return 0;
}
