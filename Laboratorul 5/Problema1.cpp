#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Trie{
    struct Node{
        Node* children[26];
        int count;
        int Finalcount;

        Node(){
            for(int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
            count = 0;
            Finalcount = 0;
        }
    };
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    ~Trie(){
        clear(root);
    }
    void insert(const string& s){
        Node* curr = root;
        for(char c : s){
            int letter = c - 'a';
            if(!curr->children[letter]){
                curr->children[letter] = new Node();
            }
            curr = curr->children[letter];
            curr->count++;
        }
        curr->Finalcount++;
    }
    int longest_prefix(const string& s){
        int ans = 0;
        Node* curr = root;
        for(char c : s){
            int letter = c - 'a';
            Node* next = curr->children[letter];
            if(next->count == 1){
                return ans;
            }
            curr = next;
            ans++;
        }
        return ans;
    }
    void erase(const string& s){
        Node* curr = root;
        vector<Node*> path;
        path.push_back(root);
        for(char c : s){
            int letter = c - 'a';
            curr = curr->children[letter];
            path.push_back(curr);
        }
        curr->Finalcount--;
        for(int i = path.size() - 1; i > 0; i--){
            Node* child = path[i];
            Node* parent = path[i - 1];
            char letter = s[i - 1] - 'a';
            child->count--;
            if(child->count == 0){
                delete child;
                parent->children[letter] = nullptr;
            }
        }
    }
};
int main(){
    return 0;
}