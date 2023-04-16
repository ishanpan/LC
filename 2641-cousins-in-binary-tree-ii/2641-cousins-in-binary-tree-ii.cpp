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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==NULL){
            return root;
        }
        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root,NULL});
        while(!q.empty()){
            int n=q.size();
            queue<pair<TreeNode*,TreeNode*>>qt;
            unordered_map<TreeNode*,int>m;
            int total = 0;
            for(int i=0;i<n;i++){
                auto temp = q.front().first;
                auto parent = q.front().second;
                if(m.find(parent)==m.end()){
                    m[parent] = temp->val;
                }
                else{
                    m[parent] += temp->val;
                }
                total += temp->val;
                qt.push(q.front());
                q.pop();
                if(temp->left){
                    q.push({temp->left,temp});
                }
                if(temp->right){
                    q.push({temp->right,temp});
                } 
            }
            for(int i=0;i<n;i++){
                auto temp = qt.front().first;
                auto parent = qt.front().second;
                qt.pop();
                temp->val = total-m[parent];
            }
            
            
        }
        return root;
        
    }
};