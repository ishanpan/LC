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

    int maxA = INT_MIN;
    int d(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int left = 1+d(root->left);
        int right = 1+d(root->right);

        maxA = max(maxA, left+right-2);
        return max(left,right);

    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        auto dl = d(root);

        return maxA;
        
    }
};