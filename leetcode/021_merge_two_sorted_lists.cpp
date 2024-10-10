#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode():
        val(0), next(nullptr) {}
    ListNode(int x):
        val(x), next(nullptr) {}
    ListNode(int x, ListNode *y):
        val(x), next(y) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *merged, *curr1, *curr2;
        
        while(curr1->next && curr2->next) {
            if (curr1->val >= curr2->val) {
                merged = new ListNode(curr2->val);
                curr2 = curr2->next;
            } else {
                merged = new ListNode(curr1->val);
                curr1 = curr1->next;
            }
        }

        return list1;
    }
};


int main() {
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(4);

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);

    ListNode *ret = Solution().mergeTwoLists(head1, head2);
    while (ret->next) {
        std::cout << ret->val << " ";
        ret = ret->next;
    }
    std::cout << ret->val;

    return 0;
}
