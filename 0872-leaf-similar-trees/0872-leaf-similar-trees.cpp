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
    vector<int> v1,v2;
    void leafList(TreeNode* root,vector<int> &v){
        if(root == NULL){
            return;
        }
        leafList(root->left,v);
        leafList(root->right,v);
        if(root->left == NULL && root->right == NULL){
            v.push_back(root->val);
        }
        
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        leafList(root1,v1);
        leafList(root2,v2);
        if(v1.size() != v2.size()){
            return false;
        }
        return v1==v2;
    }
};