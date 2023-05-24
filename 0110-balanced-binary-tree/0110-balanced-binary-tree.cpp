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
    
    int height(TreeNode* root ,int &val){
        if(root==NULL){
            return 0;
        }
        
        int left = 1+height(root->left,val);
        int right = 1+height(root->right,val);
        val = max(val,abs(left-right));    
        return max(left,right);
    }
    
    
    bool isBalanced(TreeNode* root) {
        int val = 0;
        int h = height(root,val);
        if(val>1){
            return false;
        }
        return true;
        
    }
};