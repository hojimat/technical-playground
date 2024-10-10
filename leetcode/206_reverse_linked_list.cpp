#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode():
        val(0), next(nullptr) {}
    ListNode(int x):
        val(x), next(nullptr) {}
    ListNode(int x, ListNode *next):
        val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // given (1,p2), (2, p3), (3, p4) (4, nullptr)
        // wanted (4,p3), (3, p2), (2, p1), (1, nullptr)
        // plan:
        // (1,p2) -> (1, nullptr) go to p2
        // (2,p3) -> (3, p2) go to p3
        // (3,p4) -> (4, p3) go to p4

        if (head->next == nullptr) {
            return head;
        }
        ListNode *curr, *prev;
        
        // Loop through the main array
        curr = head;
        prev = nullptr;
        while(curr->next != nullptr) {
            prev = new ListNode(curr->val, prev);
            curr = curr->next;
        }

        
        ListNode *rhead = new ListNode(curr->val, prev);

        return rhead;
    }


};


int main() {
    ListNode *headx;
    ListNode *head = new ListNode();
    headx = new ListNode();
    headx->next = new ListNode(1);
    headx->next->next = new ListNode(2);
    headx->next->next->next = new ListNode(3);
    headx->next->next->next->next = new ListNode(4);

    ListNode* reversed = Solution().reverseList(head);

    ListNode* curr = reversed;
    //curr = headx;
    while (curr->next) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    

    return 0;
}
