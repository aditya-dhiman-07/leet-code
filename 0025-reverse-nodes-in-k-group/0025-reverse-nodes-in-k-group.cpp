class Solution {
private:
    ListNode* reverseList(ListNode* head, int left, int right) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* tail = curr;
        ListNode* p = nullptr;

        for (int i = 0; i < right - left + 1; i++) {
            ListNode* nxt = curr->next;
            curr->next = p;
            p = curr;
            curr = nxt;
        }

        prev->next = p;
        tail->next = curr;

        return dummy.next;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode* ptr = head;

        while (ptr) {
            n++;
            ptr = ptr->next;
        }

        int x = n / k;

        for (int i = 0; i < x; i++) {
            int left = i * k + 1;
            int right = left + k - 1;
            head = reverseList(head, left, right);
        }

        return head;
    }
};