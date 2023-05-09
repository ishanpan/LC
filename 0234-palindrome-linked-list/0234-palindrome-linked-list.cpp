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
     ListNode* reverse(ListNode* head){
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forw = NULL;
        
        while(curr != NULL){
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* temprev = reverse(slow);
        
        ListNode* temp = head;
        while(temp!=NULL && temprev!=NULL){
            if(temp->val!=temprev->val){
                return false;
            }
            temp=temp->next;
            temprev=temprev->next;
        }
        
        return true;
    }
};