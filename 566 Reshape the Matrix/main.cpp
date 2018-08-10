#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {

        if (nums.empty()) {
            return nums;
        }

        if (nums.size() * nums.at(0).size() != r * c) {
            return nums;
        }

        vector<vector<int>> result;
        int cnt = 0;
        int total = r * c;

        for (auto& i : nums) {
            for (auto& j : i) {
                if (cnt % c == 0) {
                    result.emplace_back(vector<int>());
                }
                result.back().push_back(j);
                cnt++;
            }
        }

        return result;
    }
};

int main() {

    Solution s;
    vector<vector<int>> nums = { {1,2}, {3,4} };
    auto result = s.matrixReshape(nums, 4, 1);

    for (auto& item : result) {
        for (auto ele : item) {
            std::cout << ele;
        }
        std::cout << std::endl;
    }
    return 0;
}