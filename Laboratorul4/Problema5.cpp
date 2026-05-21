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
        vector<HeapNode*> pairs;
        for(int i = 0; i < children.size(); i += 2){
            if(i + 1 < children.size()){
                if(children[i]->key < children[i + 1]->key){
                    children[i]->children.push_back(children[i + 1]);
                    pairs.push_back(children[i]);
                }
                else{
                    children[i + 1]->children.push_back(children[i]);
                    pairs.push_back(children[i + 1]);
                }
            }
            else{
                pairs.push_back(children[i);
            }
        }
        int index = pairs.size() - 1;
        HeapNode* new_root = pairs[index];
        for(int i = index - 1; i >= 0; i--){
            HeapNode* node = pairs[i];
            if(new_root->key < node->key){
                node->children.push_back(new_root);
                new_root = node;
            }
            else{
                new_root->children.push_back(node);
            }
        }
        root = new_root;
    }
};
int main(){
    return 0;
}
