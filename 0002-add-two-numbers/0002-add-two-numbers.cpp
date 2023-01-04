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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
        ListNode* new_node = new ListNode();
        
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int carry = 0;
        ListNode* head = NULL;
        ListNode* curr = NULL;
        while(t1!=NULL && t2!=NULL){
            ListNode* new_node = new ListNode();
            if(head==NULL){
                head = new_node;
                curr=head;
            }
            else{
                curr->next = new_node;
                curr = curr->next;
            }
            
            
            int s=t1->val+t2->val;
            if(s+carry>9){
                new_node->val = (s+carry)%10;
                carry=1;
            }
            else{
                new_node->val = (s+carry);
                carry = 0;
            }
            t1 = t1->next;
            t2 = t2->next;
            
        }
        ListNode* t3 = NULL;
        if(t1!=NULL){
            t3 = t1;
        }
        else{
            t3 = t2;
        }
        while(t3!=NULL){
            ListNode* new_node = new ListNode();
            if(head==NULL){
                head = new_node;
                curr=head;
            }
            else{
                curr->next = new_node;
                curr = curr->next;
            }
            
            
            int s=t3->val;
            if(s+carry>9){
                new_node->val = (s+carry)%10;
                carry=1;
            }
            else{
                new_node->val = (s+carry);
                carry = 0;
            }
            t3=t3->next;
            
        }
        
        if(carry==1){
            ListNode* new_node = new ListNode();
            curr->next = new_node;
            new_node->val = 1;
        }

        
        return head;

        
        
    }
};