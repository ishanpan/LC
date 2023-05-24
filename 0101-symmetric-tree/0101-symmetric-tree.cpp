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
    
    bool checkLR(TreeNode* root1, TreeNode* root2){
        
        if(root1==NULL && root2==NULL){
            return true;
        }
        if(root1==NULL || root2==NULL || root1->val!=root2->val){
            return false;
        }
        
        bool ch1 = true;
        ch1 = checkLR(root1->left,root2->right);
        bool ch2 = true;
        ch2 = checkLR(root1->right,root2->left);        
        return (ch1 && ch2);

    }
    
    
    bool isSymmetric(TreeNode* root) {
        
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        queue<TreeNode*>q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
          
            TreeNode* q1 = q.front();
            q.pop();
            TreeNode* q2;
            if(q.size()>0){
                q2 = q.front(); 
                q.pop();
            }
            if(q1==NULL && q2==NULL){
                continue;
            }
            if(q1==NULL || q2==NULL || q1->val!=q2->val )
            {
                return false;
            }
            
                q.push(q1->left);
                q.push(q2->right);
            
             
                q.push(q1->right);
                q.push(q2->left);
            
        }
        
        return true;
        
        
        
    }
};