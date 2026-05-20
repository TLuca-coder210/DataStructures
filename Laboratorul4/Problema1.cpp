#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class BinarySearchTree{
private:
    struct Node{
        int key;
        int left = -1, right = -1;
        Node(int value){
            this->key = value;
            this->left = -1;
            this->right = -1;
        }
    };
    vector<Node> tree;
    int root = -1;
    int BuildBalanced(const vector<int> &v, int start, int end){
        if(start > end){
            return -1;
        }
        int mid = start + (end - start) / 2;
        int current_idx = tree.size();
        tree.push_back(Node(v[mid]));
        int left_child = BuildBalanced(v, start, mid - 1);
        int right_child = BuildBalanced(v, mid + 1, end);
        tree[current_idx].left = left_child;
        tree[current_idx].right = right_child;
        return current_idx;
    }
public:
    void construct(vector<int> v){
        if(v.empty()){
            return;
        }
        sort(v.begin(), v.end());
        root = BuildBalanced(v, 0, v.size() - 1);
    }
    bool exists(int value){
        int curr = root;
        while(curr != -1){
            if(tree[curr].key == value){
                return true;
            }
            if(tree[curr].key < value){
                curr = tree[curr].left;
            }
            else{
                curr = tree[curr].right;
            }
        }
        return false;
    }
    void insert(int value){
        if(root = -1){
            root = tree.size();
            tree.push_back(Node(value));
            return;
        }
        int curr = root;
        while(curr != -1){
            if(tree[curr].key == value){
                return;
            }
            if(value < tree[curr].key){
                if(tree[curr].left == -1){
                    tree[curr].left = tree.size();
                    tree.push_back(Node(value));
                    return;
                }
                else{
                    curr = tree[curr].left;
                }
            }
            else{
                if(tree[curr].right == -1){
                    tree[curr].right = tree.size();
                    tree.push_back(Node(value));
                    return;
                }
                else{
                    curr = tree[curr].right;
                }
            }
        }
    }
    void erase(int value){
        if(root == -1){
            return;
        }
        int curr = root, last = -1;
        while(curr != -1 and tree[curr].key != value){
            last = curr;
            if(value < tree[curr].key){
                curr = tree[curr].left;
            }
            else{
                curr = tree[curr].right;
            }
        }
        if(curr == -1){
            return;
        }
        if(tree[curr].right == -1 and tree[curr].left == -1){
            if(last == -1){
                root = -1;
            }
            else if(tree[last].left == curr){
                tree[last].left = -1;
            }
            else{
                tree[last].right = -1;
            }
        }
        else if(tree[curr].left == -1 or tree[curr].right == -1){
            int child = (tree[curr].left != -1) ? tree[curr].left : tree[curr].right;
            if(last == -1){
                root = child;
            }
            else if(tree[last].left == curr){
                tree[last].left = child;
            }
            else{
                tree[last].right = child;
            }
        }
        else{
            int next = tree[curr].right, last = curr;
            while(tree[next].left != -1){
                last = next;
                next = tree[next].left;
            }
            if(last == curr){
                tree[last].right = -1;
            }
            else{
                if(next == tree[last].left){
                    tree[last].left = -1;
                }
                else{
                    tree[last].right = -1;
                }
            }
            tree[curr].key = tree[next].key;
        }
    }
    int succesor(int value){
        int curr = root;
        int next = tree[curr].right;
        while(tree[next].left != -1){
            next = tree[next].left;
        }
        return tree[next].key;
    }
    int predecessor(int value){
        int curr = root;
        int next = tree[curr].left;
        while(tree[next].right != -1){
            next = tree[next].right;
        }
        return tree[next].key;
    }
};
int main(){
    
    return 0;
}