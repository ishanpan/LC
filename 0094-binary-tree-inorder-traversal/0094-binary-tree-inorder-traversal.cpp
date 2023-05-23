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
    void inorder(TreeNode* root, vector<int>&ans){
        
        if(root==NULL){
            return;
        }
        if(root->left!=NULL){
            inorder(root->left,ans);
        }
        ans.push_back(root->val);
        if(root->right!=NULL){
            inorder(root->right,ans);
        }
        
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            if(s.top()->left!=NULL){
                s.push(s.top()->left);
            }
            else{
                while(s.size()>0 && s.top()->right==NULL){
                    ans.push_back(s.top()->val);
                    s.pop();
                }
                
                if(s.size() >0 && s.top()->right!=NULL){
                    ans.push_back(s.top()->val);
                     auto ss = s.top();
                    s.pop();
                    s.push(ss->right);
                    
                }
            }
            
            
        }
        return ans;
        
    }
};