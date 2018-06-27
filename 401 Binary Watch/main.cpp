#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        static vector<vector<string>> watch = [] {
            vector<vector<string>> t(11);
            for (unsigned h = 0; h <= 11; h++) {
                int hc = __builtin_popcount(h);
                for (unsigned m = 0; m <= 59; m++) {
                    int mc = __builtin_popcount(m);
                    char tmp[128];
                    auto n = sprintf(tmp, "%d:%02d", h, m);
                    auto s = string(tmp, n);
                    t.at(hc + mc).push_back(std::move(s));
                }
            }
            return t;
        } ();

        if (num >= watch.size()) {
            return vector<string>();
        }
        return watch[num];
    }
};

int main() {
    Solution s;

    auto result = s.readBinaryWatch(1);
    for (auto& item : result) {
        cout << item << " ";
    }


    return 0;
}