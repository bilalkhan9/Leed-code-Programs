#include <iostream>
#include <vector>
#include <map>  

using namespace std;


vector<int> twoSum(const vector<int>& nums, int target) {
    map<int, int> numToIndex;  
    vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        
        map<int, int>::iterator it = numToIndex.find(complement);
        if (it != numToIndex.end()) {
            result.push_back(it->second);  
            result.push_back(i);           
            return result;
        }
        numToIndex[nums[i]] = i;
    }

    return result;  
}

int main() {
    
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);

    int target = 9;  
    vector<int> indices = twoSum(nums, target);


    for (size_t i = 0; i < indices.size(); ++i) {
        cout << indices[i] << " ";
    }
    cout << endl;
	system("pause");
    return 0;
}
