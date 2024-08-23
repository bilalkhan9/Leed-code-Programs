#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int write_index = 0;
    for (int read_index = 0; read_index < nums.size(); ++read_index) {
        if (nums[read_index] != val) {
            nums[write_index++] = nums[read_index];
        }
    }
    return write_index;
}

void printArray(const vector<int>& nums, int k) {
    for (int i = 0; i < k; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums1;
    nums1.push_back(3);
    nums1.push_back(2);
    nums1.push_back(2);
    nums1.push_back(3);
    int val1 = 3;
    
    int k1 = removeElement(nums1, val1);
    cout << "Output: " << k1 << ", nums = ";
    printArray(nums1, k1);
    
    vector<int> nums2;
    nums2.push_back(0);
    nums2.push_back(1);
    nums2.push_back(2);
    nums2.push_back(2);
    nums2.push_back(3);
    nums2.push_back(0);
    nums2.push_back(4);
    nums2.push_back(2);
    int val2 = 2;
    
    int k2 = removeElement(nums2, val2);
    cout << "Output: " << k2 << ", nums = ";
    printArray(nums2, k2);
	system("pause");
    return 0;
}
