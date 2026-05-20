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
private:
    long long mini = LONG_MIN;
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        if(!isValidBST(root->left)){
            return false;
        }
        if(root->val<= mini){
            return false;
        }
        mini = root->val;
        return isValidBST(root->right);
    }
};