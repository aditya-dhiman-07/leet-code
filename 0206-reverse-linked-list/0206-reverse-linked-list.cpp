
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* ptr = head;
        ListNode* prev = nullptr;

        while (ptr != nullptr) {
            ListNode* nxt = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = nxt;
        }

        return prev;
    }
};
