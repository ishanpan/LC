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
    
    
   
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        
        stack<TreeNode*>s;
        vector<int>ans;
        s.push(root);
        while(!s.empty()){
            if(s.size()>0 && s.top()->left){
                s.push(s.top()->left);
            }
            else{
                while(s.size()>0 && s.top()->right==NULL){
                    ans.push_back(s.top()->val);
                    s.pop();
                }
                if(s.size()>0 && s.top()->right){
                    auto temp = s.top();
                    s.push(temp->right);
                    temp->right=NULL;
                    
                }
            }
        }
        return ans;
        
    }
};