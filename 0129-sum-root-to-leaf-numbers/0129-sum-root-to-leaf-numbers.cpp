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
    int rootToLeafPathSum(TreeNode* root,int currentSum,int globalSum){
        if(root == NULL){
            return 0;
        }
        if(root->left==NULL && root->right ==NULL){
            currentSum=currentSum*10 + root->val;
            globalSum+= currentSum;
            currentSum=currentSum/10;
            return globalSum;
        }
        currentSum= currentSum*10 + root->val;
        int left = rootToLeafPathSum(root->left,currentSum,globalSum);  
        int right = rootToLeafPathSum(root->right,currentSum,globalSum);
        currentSum/=10;
        return left+right;
    }
    int sumNumbers(TreeNode* root) {
        int sum = rootToLeafPathSum(root,0,0);
        return sum;
    }
};