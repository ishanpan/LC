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
    
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p!=NULL && q==NULL || p==NULL && q!=NULL  ){
            return false;
        }
        if(p!=NULL && q!=NULL && p->val!=q->val){
            return false;
        }
        bool s1=true;
        bool s2=true;
        if(p!=NULL && q!=NULL){
             s1 = isSameTree(p->left, q->left);
             s2 = isSameTree(p->right, q->right);
        }
        
        return (s1&&s2);
        
    }
};