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
    TreeNode* prev = nullptr;
    TreeNode* firstNode = nullptr;
    TreeNode* secondNode = nullptr;
    void traverse(TreeNode* root){
        if(root == nullptr){
            return;
        }
        traverse(root->left);
        if(prev != nullptr and root->val <= prev->val){
            if(firstNode == nullptr){
                firstNode = prev;
                secondNode = root;
            }
            else{
                secondNode = root;
            }
        }
        prev = root;
        traverse(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        traverse(root);
        if(firstNode != nullptr and secondNode != nullptr){
            swap(firstNode->val, secondNode->val);
        }
    }
};