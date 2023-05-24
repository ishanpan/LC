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
    

    
    int minDepth(TreeNode* root) {
        
        if(root==NULL){
            return 0;   
        }        
        queue<TreeNode*>q;
        q.push(root);
        int levels = 0;
        
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode* t = q.front();
                q.pop();
                if(t->left==NULL && t->right==NULL){
                    return levels+1;
                }
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }

            }
           levels++;
            
        }
        
        return levels;
        
    }
};