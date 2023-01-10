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
    queue<int>st;
    
    void fa(TreeNode* root){
        if(root==NULL){
            return;
        }
        
        st.push(root->val);
        fa(root->left);
        fa(root->right);
    }
    
    
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        fa(root);
        TreeNode* temp = root;
        st.pop();
        while(!st.empty()){
            
            temp->left = NULL;
            TreeNode* te = new TreeNode;
            te->val = st.front();
            st.pop();
            temp->right = te;
            temp = temp->right;
        }
        
    }
};