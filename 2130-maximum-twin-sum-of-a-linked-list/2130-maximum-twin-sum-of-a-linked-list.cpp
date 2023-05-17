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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = slow;
        ListNode* prev = NULL;
        while(temp!=NULL){
            ListNode* n = temp->next;
            temp->next = prev;
            prev = temp;
            temp = n;
        }
        ListNode* start = head;
        int maxAns = INT_MIN;
        while(prev!=NULL){
            maxAns = max(maxAns, (start->val+prev->val));
            start = start->next;
            prev = prev->next;
        }
        
        return maxAns;
    }
};