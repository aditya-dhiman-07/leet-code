/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) return head;
        int n = 0;
        ListNode* ptr = head;
        ListNode* ptr_end = nullptr;

        while(ptr){
            n++;
            if(ptr->next == nullptr){
                ptr_end = ptr;
            }
            ptr = ptr->next;
        }
        ptr = head;
        k = k%n;
        if (k==0) return head;
        int x = n-k-1;
        while(ptr&&x){
            ptr = ptr->next;
            x--;
        }
        ListNode* temp = ptr->next;
        ptr_end->next = head;
        ptr->next = nullptr;
        head = temp;

        return head;
        
    }
};