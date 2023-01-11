/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
         ListNode* temp = head;
        vector <ListNode*> a;
        while(temp!=NULL){
            
            for(int i =0;i<a.size();i++){
                if(temp==a[i]){
                    return temp;
                }
            }
            a.push_back(temp);
            temp = temp->next;
            
        }
        return NULL;
        
        
    }
};