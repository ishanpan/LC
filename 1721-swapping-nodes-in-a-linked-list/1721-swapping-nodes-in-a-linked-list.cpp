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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* diff = NULL;
        int s = k-1;
        while(s--){
            fast = fast->next;
            
        }
        
        diff = fast;
        
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        
        int temp = diff->val;
        
        diff->val = slow->val;
        slow->val = temp;
        return head;
        
        
        
        
        
        
    }
};