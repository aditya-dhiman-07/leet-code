class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) return head;

        int n = 1;
        ListNode* ptr = head;
        // goto end and count for number of elements
        while (ptr->next) {
            ptr = ptr->next;
            n++;
        }

        k = k % n;
        if (k == 0) return head;

        // connect end to head and go n-k steps i.e the steps required to get to the prev node of new head
        ptr->next = head;
        int x = n - k;
        while (x--) {
            ptr = ptr->next;
        }
        // assign new head as ptr->next and make its next nullptr and return head
        ListNode* temp = ptr->next;
        ptr->next = nullptr;
        head = temp;

        return head;
    }
};