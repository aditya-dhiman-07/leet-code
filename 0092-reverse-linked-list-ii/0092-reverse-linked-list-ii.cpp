class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        for(int i = 1; i < left; i++)
            prev = prev->next;

        ListNode* curr = prev->next;
        ListNode* tail = curr;
        ListNode* p = nullptr;

        for(int i = 0; i <= right-left; i++) {
            ListNode* nxt = curr->next;
            curr->next = p;
            p = curr;
            curr = nxt;
        }

        prev->next = p;
        tail->next = curr;

        return dummy.next;
    }
};