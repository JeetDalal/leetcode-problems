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
    void solve(TreeNode* root, int val ,int depth){
       if(root==NULL) return;
        if(depth == 2){
            TreeNode* leftNode = new TreeNode(val);
            leftNode->left = root->left;
            root->left = leftNode;
            TreeNode* rightNode = new TreeNode(val);
            rightNode->right = root->right;
            root->right = rightNode;
            return;
        }
        solve(root->left,val,depth-1);
        solve(root->right,val,depth-1);
        return;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode *head = new TreeNode(val);
            head->left = root;
            root = head;
        }else{
            solve(root,val,depth);
        }
        return root;
    }
};