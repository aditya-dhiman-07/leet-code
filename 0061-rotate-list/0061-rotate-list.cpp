class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) return head;

        int n = 1;
        ListNode* ptr = head;

        // Stop directly on the last node so we don't need ptr_end
        while (ptr->next) {
            ptr = ptr->next;
            n++;
        }

        k = k % n;
        if (k == 0) return head;

        // Make it a circular list, then walk (n - k) steps to land on the new tail
        ptr->next = head;
        int x = n - k;
        while (x--) {
            ptr = ptr->next;
        }

        ListNode* temp = ptr->next;
        ptr->next = nullptr;
        head = temp;

        return head;
    }
};