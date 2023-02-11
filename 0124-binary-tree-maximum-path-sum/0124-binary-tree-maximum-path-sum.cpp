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
    
    int maxS = INT_MIN;
    
    int maxSum(TreeNode* root){
     
        if(!root){
            return 0;
        }
        
        int l = max(0,maxSum(root->left));
        int r = max(0,maxSum(root->right));
        
        int total = l+r+root->val;
        
        maxS = max(maxS, total);
        
        return max(l,r)+root->val;

    }
    
    
    int maxPathSum(TreeNode* root) {
        
        maxSum(root);
        return maxS;
        
    }
};