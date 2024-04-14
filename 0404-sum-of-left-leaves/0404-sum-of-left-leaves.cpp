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
    int sumOfLeaves(TreeNode* root,int sum,int isLeft){
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right==NULL && isLeft== true){
            return  sum+root->val;
        }
        
        int left = sumOfLeaves(root->left,sum,true);
        int right = sumOfLeaves(root->right,sum,false);
        return left+right;
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root->left==NULL && root->right ==NULL){
            return 0;
        }
        int ans = sumOfLeaves(root,0,true);
        return ans;
    }
};