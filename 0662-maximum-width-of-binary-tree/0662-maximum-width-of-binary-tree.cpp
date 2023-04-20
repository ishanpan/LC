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
    int widthOfBinaryTree(TreeNode* root) {
       if(root==NULL){
           return 0;
       }
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        long long maxAns = 0;
        while(!q.empty()){
            int n = q.size();
            long long lastelem = q.back().second;
            long long firstelem = q.front().second;
            maxAns = max(maxAns, (lastelem-firstelem+1));
            for(int i=0;i<n;i++){
                auto temp = q.front();
                q.pop();
                TreeNode* elem = temp.first;
                int idx = temp.second - firstelem;
                if(elem->left){
                    q.push({elem->left, (long long) idx*2+1});
                }
                if(elem->right){
                    q.push({elem->right,(long long) idx*2+2});
                }
            }
            
        }
        
        return maxAns;
        
        
    }
};