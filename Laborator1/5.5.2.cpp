#include<iostream>
using namespace std;
void findDuplicate(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        if(v[i] > 0){
            int slow = v[i], fast = v[v[i]];
            while(slow != fast){
                slow = v[slow];
                fast = v[v[fast]];
            }
            slow = i;
            while(slow != fast){
                slow = abs(v[slow]);
                fast = abs(v[fast]);
            }
            cout << slow << '\n';
            int curr = i;
            while(v[curr] > 0){
                int next = v[curr];
                v[curr] = -v[curr];
                curr = next;
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for(int i = 0; i <= n; i++){
        cin >> v[i];
    }
    findDuplicate(v);
    return 0;
}
