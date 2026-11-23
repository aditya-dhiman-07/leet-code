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
            while(slow != fast){
                fast = fast->next;
                slow = slow->next;
                if(slow==fast) break;
            }
            return slow;
        }
        else return nullptr;
    }
};