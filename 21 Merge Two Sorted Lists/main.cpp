#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto result = new ListNode(0);
        auto cur = &result->next;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                *cur = l1;
                l1 = l1->next;
            } else {
                *cur = l2;
                l2 = l2->next;
            }
            cur = &(*cur)->next;
        }

        if (l1) {
            *cur = l1;
        }

        if (l2) {
            *cur = l2;
        }

        return result->next;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}