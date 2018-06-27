#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct athlete {
    unsigned _id;
    int _score;
    mutable string _rank;

    athlete(unsigned id, int score) : _id(id), _score(score) {}

    bool operator <(const athlete &x)const {
        return _score < x._score;
    }

    friend inline std::ostream &operator<<(std::ostream &os, const athlete &x) {
        os << "id[" << x._id << "] score[" << x._score << "] rank[" << x._rank << "]";
        return os;
    }
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        set<athlete> s;
        for (unsigned i = 0; i < nums.size(); i++) {
            s.emplace(i, nums[i]);
        }
        unsigned r = 1;
        for (auto it = s.rbegin(); it != s.rend(); it++, r++) {
            switch (r) {
                case 1:
                    it->_rank = "Gold Medal";
                    break;
                case 2:
                    it->_rank = "Silver Medal";
                    break;
                case 3:
                    it->_rank = "Bronze Medal";
                    break;
                default:
                    it->_rank = to_string(r);
            }
        }

        vector<string> result;
        for (unsigned i = 0; i < nums.size(); i++) {
            result.push_back(s.find(athlete(i, nums[i]))->_rank);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 4, 3, 2, 1};
    auto result= s.findRelativeRanks(nums);

    for (auto& item : result) {
        cout << item;
    }

    return 0;
}