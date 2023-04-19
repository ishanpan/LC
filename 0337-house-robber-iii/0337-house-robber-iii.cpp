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
    unordered_map<TreeNode*,int>m;
    int knap(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        if(m.find(root)!=m.end()){
            return m[root];
        }
        int ans = 0;
        
        if(root->left!=NULL){
            ans+= knap(root->left->left) + knap(root->left->right);
        } 
        
        if(root->right!=NULL){
            ans+=knap(root->right->left) + knap(root->right->right);
        }
        
        int notTaken = knap(root->left) + knap(root->right);
                
        return m[root] = max((ans+root->val),notTaken);

    }
    
    int rob(TreeNode* root) {
        
        return knap(root);
    }
};


