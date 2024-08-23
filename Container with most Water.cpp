#include <iostream>
#include <vector>
#include <algorithm> 

int maxArea(const std::vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int max_area = 0;

    while (left < right) {
  
        int width = right - left;
        int min_height = std::min(height[left], height[right]);
        int current_area = width * min_height;

  
        max_area = std::max(max_area, current_area);

  
        if (height[left] < height[right]) {
            ++left;
        } else {
            --right;
        }
    }

    return max_area;
}

int main() {
  
    std::vector<int> height;
    height.push_back(1);
    height.push_back(8);
    height.push_back(6);
    height.push_back(2);
    height.push_back(5);
    height.push_back(4);
    height.push_back(8);
    height.push_back(3);
    height.push_back(7);

  
    int result = maxArea(height);

  
    std::cout << "Input height: [";
    for (size_t i = 0; i < height.size(); ++i) {
        std::cout << height[i];
        if (i < height.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
    std::cout << "Maximum water area: " << result << std::endl;
	system("pause");
    return 0;
}
