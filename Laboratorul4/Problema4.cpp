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
private:
    void traverse(TreeNode* root, string& s){
        if(root == nullptr){
            return;
        }
        s += to_string(root->val) + " ";
        traverse(root->left, s);
        traverse(root->right, s);
    }
    TreeNode* insert(vector<int>&nums, int index,  long long mini, long long maxi){
        if(index >= nums.size()){
            return nullptr;
        }
        int value = nums[index];
        if(value < mini or value > maxi){
            return nullptr;
        }
        index++;
        TreeNode* root = new TreeNode(value);
        root->left = insert(nums, index, mini, value);
        root->right = insert(nums, index, value, maxi);
        return root;
    }
public:
    string serialize(TreeNode* root) {
        string s = "";
        traverse(root, s);
        return s;
    }
    TreeNode* deserialize(string data) {
        vector<int> numbers;
        string s = "";
        for(char c : data){
            if(c == ' '){
                numbers.push_back(stoi(s));
                s = "";
            }
            else{
                s += c;
            }
        }
        return insert(numbers, 0, LONG_MIN, LONG_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;