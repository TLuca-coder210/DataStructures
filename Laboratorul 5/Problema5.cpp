#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
struct Node{
    char letter;
    int index, prev_index, final_word;
    vector<int> best;
    int children[26];
    Node() {
        for(int i = 0; i < 26; i++){
            children[i] = 0;
        }
        final_word = -1;
        prev_index = -1;
        letter = 'R';
        index = 0;
    }
};
vector<Node> Trie;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> freq(500005, 0);
    int n, k;
    cin >> n >> k;
    Trie.push_back(Node());
    int curr_node = 0, match_depth = 0;
    string curr_word = "";
    for(int i = 0; i < n; i++){
        int number;
        cin >> number;
        if(number == 1){
            char c;
            cin >> c;
            curr_word.push_back(c);
            if(match_depth == curr_word.size() - 1 and Trie[curr_node].children[c - 'a'] != 0){
                match_depth++;
                int new_index = Trie[curr_node].children[c - 'a'];
                curr_node = Trie[new_index].index;
                for(int j = 0; j < min(k, int(Trie[curr_node].best.size())); j++){
                    if(j > 0){
                        cout << " ";
                    }
                    cout << Trie[curr_node].best[j];
                }
                cout << '\n';
            }
            else{
                cout << -1 << '\n';
            }
        }
        else{
            if(number == 2){
                curr_node = 0;
                curr_word = "";
                match_depth = 0;
            }
            if(number == 3){
                if(!curr_word.empty()){
                    curr_word.pop_back();
                    if(curr_word.size() < match_depth){
                        curr_node = Trie[curr_node].prev_index;
                        match_depth--;
                    }
                }
            }
            if(number == 4){
                int temp_node = 0;
                for (int j = 0; j < curr_word.size(); j++) {
                    int char_idx = curr_word[j] - 'a';
                    if (Trie[temp_node].children[char_idx] == 0) {
                        Node new_node;
                        new_node.prev_index = temp_node;
                        new_node.index = Trie.size();
                        new_node.letter = curr_word[j];
                        Trie.push_back(new_node);
                        Trie[temp_node].children[char_idx] = Trie.size() - 1;
                    }
                    temp_node = Trie[temp_node].children[char_idx];
                }
                curr_node = temp_node; 
                match_depth = curr_word.size();
                if (Trie[temp_node].final_word == -1) {
                    Trie[temp_node].final_word = i; 
                }
                int current_word_id = Trie[temp_node].final_word;
                freq[current_word_id]++;

                temp_node = 0;
                auto update_best = [&](int node_idx) {
                    vector<int>& top = Trie[node_idx].best;
                    bool found = false;
                    for (int v = 0; v < top.size(); v++) {
                        if (top[v] == current_word_id) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        top.push_back(current_word_id);
                    }
                    for (int v = top.size() - 1; v > 0; v--) {
                        int id_dreapta = top[v];
                        int id_stanga = top[v - 1];
                        
                        if (freq[id_dreapta] > freq[id_stanga] || 
                        (freq[id_dreapta] == freq[id_stanga] && id_dreapta < id_stanga)) {
                            swap(top[v], top[v - 1]);
                        } else {
                            break;
                        }
                    }
                    if (top.size() > k) {
                        top.pop_back();
                    }
                };
                update_best(0);                
                for (int j = 0; j < curr_word.size(); j++) {
                    temp_node = Trie[temp_node].children[curr_word[j] - 'a'];
                    update_best(temp_node);
                }
            }
        }
    }
    return 0;
}