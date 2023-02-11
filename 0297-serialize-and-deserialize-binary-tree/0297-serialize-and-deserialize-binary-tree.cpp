/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "#";
        }
        
        string s = to_string(root->val)+","+serialize(root->left) +","+serialize(root->right);
        
        return s;
        
        
        
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        return myd(data);
        
    }
    
    int helper (string &d){
        int pos = d.find(',');
        int val = stoi(d.substr(0,pos));
        d = d.substr(pos+1);
        return val;
    }
    TreeNode* myd(string &d){
        if(d[0]=='#'){
            if(d.size()>1){
                d = d.substr(2);
            }
            return NULL;
        }
        else{
            TreeNode* te = new TreeNode(helper(d));
            
            te->left = myd(d);
            te->right = myd(d);
            return te;
        }

        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));