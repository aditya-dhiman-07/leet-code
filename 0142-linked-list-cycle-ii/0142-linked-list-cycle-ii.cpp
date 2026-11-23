/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode *cycleNode(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast&&fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) return slow;
        }
        return nullptr;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* ptr = cycleNode(head);
        if(ptr!=nullptr){

            ListNode* slow = head;
            ListNode* fast = ptr;
            while(slow != ptr){
                while(fast!=slow){
                    fast = fast->next;
                    if (fast == ptr) break;
                }
                if(fast == slow) return slow;
                slow = slow->next;
                fast = ptr;
            }
            return slow;
        }
        else return nullptr;
    }
};