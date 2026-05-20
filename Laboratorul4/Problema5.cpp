#include<iostream>
#include<vector>
using namespace std;
struct HeapNode{
    int key;
    vector<HeapNode*> children;
    HeapNode(int val){
        key = val;
    }
};
class Heap{
private:
    HeapNode* root = nullptr;
public:
    void insert(int value){
        if(root == nullptr){
            root = new HeapNode(value);
            return;
        }
        if(root->key < value){
            HeapNode* new_child = new HeapNode(value);
            root->children.push_back(new_child);
        }
        else{
            HeapNode* new_root = new HeapNode(value);
            new_root->children.push_back(root);
            root = new_root;
        }
    }
    int top(){
        return root->key;
    }
    void pop(){
        if(root == nullptr){
            return;
        }
        vector<HeapNode*> children = root->children;
        delete root;
        if(children.empty()){
            root = nullptr;
            return;
        }
        int index = children.size() - 1;
        HeapNode* new_root = children[index];
        for(int i = index - 1; index >= 0; i--){
            HeapNode* node = children[i];
            if(new_root->key < node->key){
                new_root->children.push_back(node);
            }
            else{
                node->children.push_back(new_root);
                new_root = node;
            }
        }
        root = new_root;
    }
};
int main(){
    return 0;
}