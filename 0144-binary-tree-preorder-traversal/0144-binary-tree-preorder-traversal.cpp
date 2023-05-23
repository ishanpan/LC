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
    
    vector<int>ans;
    
    void pot(TreeNode* root){
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        pot(root->left);
        pot(root->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            ans.push_back(s.top()->val);
            if(s.size()>0 && s.top()->left){
                s.push(s.top()->left);
            }
            else{
                while(s.size()>0 && s.top()->right==NULL){
                    s.pop();
                }
                if(s.size()>0 && s.top()->right){
                    auto temp = s.top();
                    s.pop();
                    s.push(temp->right);
                }
                
            }

        }
        return ans;
        
        
    }
};