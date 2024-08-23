#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end()); 
    int closestSum = nums[0] + nums[1] + nums[2];  
    
    for (int i = 0; i < nums.size() - 2; ++i) {
        int left = i + 1; 
        int right = nums.size() - 1; 
        
        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];
            if (currentSum == target) {
                return currentSum;  
            }
            
    
            if (abs(currentSum - target) < abs(closestSum - target)) {
                closestSum = currentSum;
            }
            
    
            if (currentSum < target) {
                ++left;
            } else {
                --right;
            }
        }
    }
    
    return closestSum;
}

int main() {
    
    vector<int> nums1;
    nums1.push_back(-1);
    nums1.push_back(2);
    nums1.push_back(1);
    nums1.push_back(-4);
    int target1 = 1;
    cout << "Closest sum to target " << target1 << " is " << threeSumClosest(nums1, target1) << endl;

    vector<int> nums2;
    nums2.push_back(0);
    nums2.push_back(0);
    nums2.push_back(0);
    int target2 = 1;
    cout << "Closest sum to target " << target2 << " is " << threeSumClosest(nums2, target2) << endl;
	system("pause");
    return 0;
}
