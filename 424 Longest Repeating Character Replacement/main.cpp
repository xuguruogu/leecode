#include <iostream>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnt[26] = {};
        int start = 0, end = 0, max_cnt = 0;

        for (end = 0; end < s.size(); end++) {
            max_cnt = std::max(max_cnt, ++cnt[s.at(end) - 'A']);
            if (end - start + 1 - max_cnt > k) {
                cnt[s.at(start++) - 'A']--;
            }
        }

        return std::min(max_cnt+k, static_cast<int>(s.size()));
    }
};

int main() {
    Solution s;
    std::cout << s.characterReplacement("AABABBA", 1) << std::endl;
    return 0;
}