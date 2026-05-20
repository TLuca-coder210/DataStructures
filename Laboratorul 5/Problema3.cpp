#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

ifstream fin("xormax.in");
ofstream fout("xormax.out");

struct Node {
    char value;
    int left;
    int right;
    int final;
    int prefix_index;
};

string change_to_bitwise(int number) {
    string return_string = "";
    for (int i = 0; i <= 21; i++) {
        if ((number >> i) & 1) return_string += '1';
        else return_string += '0';
    }
    return return_string;
}

void createTrie(const string& chain, int p_idx, vector<Node>& return_vector) {
    int parent_index = 0;
    for (int j = 21; j >= 0; j--) {
        if (chain[j] == '0') {
            if (return_vector[parent_index].left == -1) {
                return_vector.push_back({'0', -1, -1, 0, -1});
                return_vector[parent_index].left = return_vector.size() - 1;
            }
            parent_index = return_vector[parent_index].left;
        } else {
            if (return_vector[parent_index].right == -1) {
                return_vector.push_back({'1', -1, -1, 0, -1});
                return_vector[parent_index].right = return_vector.size() - 1;
            }
            parent_index = return_vector[parent_index].right;
        }
    }
    return_vector[parent_index].final++;
    return_vector[parent_index].prefix_index = p_idx;
}

int findBestPartnerIndex(const string& chain, vector<Node>& return_vector) {
    int parent_index = 0;
    for (int j = 21; j >= 0; j--) {
        if (chain[j] == '1') {
            if (return_vector[parent_index].left != -1)
                parent_index = return_vector[parent_index].left;
            else
                parent_index = return_vector[parent_index].right;
        } else {
            if (return_vector[parent_index].right != -1)
                parent_index = return_vector[parent_index].right;
            else
                parent_index = return_vector[parent_index].left;
        }
    }
    return return_vector[parent_index].prefix_index;
}

int main() {
    int n;
    if (!(fin >> n)) return 0;
    vector<int> v(n);
    vector<int> p(n + 1, 0);
    for (int i = 0; i < n; i++) {
        fin >> v[i];
        p[i + 1] = p[i] ^ v[i];
    }

    vector<Node> return_vector;
    return_vector.push_back({'R', -1, -1, 0, -1});

    vector<string> chains;
    for (int i = 0; i <= n; i++) {
        chains.push_back(change_to_bitwise(p[i]));
    }

    createTrie(chains[0], 0, return_vector);

    int max_overall = -1, start_ans = -1, end_ans = -1;

    for (int i = 1; i <= n; i++) {
        int best_p_idx = findBestPartnerIndex(chains[i], return_vector);
        int current_xor = p[i] ^ p[best_p_idx];
        
        if (current_xor > max_overall) {
            max_overall = current_xor;
            start_ans = best_p_idx + 1;
            end_ans = i;
        }
        createTrie(chains[i], i, return_vector);
    }

    fout << max_overall << " " << start_ans << " " << end_ans << endl;

    return 0;
}