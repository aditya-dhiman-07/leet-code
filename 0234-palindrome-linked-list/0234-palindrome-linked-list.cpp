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
    bool isPalindrome(ListNode* head) {
        stack<int> stk;
        ListNode* ptr = head;
        while(ptr){
            stk.push(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        int flag = true;
        while(ptr){
            int k = stk.top();
            stk.pop();
            if(k != ptr->val) flag = false;
            ptr = ptr->next;
        }
        return flag;                                                                         
    }
};