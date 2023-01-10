/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool issame = true;
    void chk(TreeNode* p, TreeNode* q){
        if(p!=NULL && q==NULL || p==NULL && q!=NULL  ){
            issame = false;
            return;
        }
        if(p!=NULL && q!=NULL && p->val!=q->val){
            issame = false;
             return;
        }
        if(p!=NULL && q!=NULL){
            chk(p->left, q->left);
            chk(p->right, q->right);
        }
        
        
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        chk(p,q);
        return issame;
        
    }
};