#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> count(26, 0);
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }
    vector<bool> must_stay(26, false);
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 != 0) {
            must_stay[i] = true;
        }
    }
    string stack = "";
    vector<bool> in_stack(26, false);
    for (int i = 0; i < n; i++) {
        int idx = s[i] - 'a';
        count[idx]--;
        if (must_stay[idx] == false) {
            continue;
        }
        if (in_stack[idx] == true) {
            continue;
        }
        while (stack.empty() == false && s[i] < stack.back() && count[stack.back() - 'a'] > 0) {
            in_stack[stack.back() - 'a'] = false;
            stack.pop_back();
        }
        stack.push_back(s[i]);
        in_stack[idx] = true;
    }
    cout << stack << '\n';
    return 0;
}