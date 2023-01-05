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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sizeL = 0;
        
        ListNode* temp = head;
        while(temp!=NULL){
            temp = temp->next;
            sizeL++;
        }
        
        if(sizeL==1){
            return NULL;
        }
        
        int till = sizeL-n-1;
        
        temp = head;
        
        if(till==-1){
            return head->next;
        }
        
        
        while(till>0){
            temp=temp->next;
            till--;
        }
        
        ListNode* te = temp->next;
        
        if(te->next!=NULL){
            temp->next = te->next;
            
        }
        else{
            temp->next = NULL;
        }
        
        delete te;
        
        return head;
        

    }
};