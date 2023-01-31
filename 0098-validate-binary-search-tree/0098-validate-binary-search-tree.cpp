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
    
    bool isV(TreeNode* root, long minV, long maxV){
        if(root==NULL){
            return true;
        }
        
        if(root->val<=minV || root->val>=maxV){
            return false;
        }
        
        bool left = isV(root->left,minV,root->val);
        bool right = isV(root->right,root->val,maxV);
        
        return (left&&right);
    
        
    }
    
    bool isValidBST(TreeNode* root) {
        return isV(root, LONG_MIN,LONG_MAX);
        
    }
};