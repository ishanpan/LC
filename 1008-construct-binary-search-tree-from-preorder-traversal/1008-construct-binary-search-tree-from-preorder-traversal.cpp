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
    
    TreeNode* bst(vector<int>& preorder){
    
        if(preorder.size()==0){
            return NULL;
        }
        
        TreeNode* temp  = new TreeNode;
        temp->val = preorder[0];
        vector<int>left;
        vector<int>right;
        for(int i=1;i<preorder.size();i++){
            if(preorder[i]<preorder[0]){
                left.push_back(preorder[i]);
            }
            else{
                right.push_back(preorder[i]);
            }
            
        }
        
        
        
        temp->left = bst(left);
        temp->right = bst(right);
        
        return temp;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bst(preorder);
    }
};