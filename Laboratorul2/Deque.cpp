#include<iostream>
#include<fstream>
#include<deque>
#include<vector>
using namespace std;
struct Node{
    int value, index;
};
int main(){
    ifstream fin("deque.in");
    ofstream fout("deque.out");
    int n, k;
    long long sum = 0;
    fin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        fin >> arr[i];
    }
    deque<Node> dq;
    dq.push_back({arr[0], 0});
    for(int i = 1; i < k; i++){
        bool ok = false;
        while(!dq.empty() and ok == false){
            if(arr[i] < dq.back().value){
                dq.pop_back();
            }
            else{
                dq.push_back({arr[i], i});
                ok = true;
            }
        }
        if(dq.empty()){
            dq.push_back({arr[i], i});
        }
    }
    sum += dq.front().value;
    for(int i = k; i < n; i++){
        bool ok = false;
        if(dq.front().index == i - k){
            dq.pop_front();
        }
        while(!dq.empty() and ok == false){
            if(arr[i] < dq.back().value){
                dq.pop_back();
            }
            else{
                dq.push_back({arr[i], i});
                ok = true;
            }
        }
        if(dq.empty()){
            dq.push_back({arr[i], i});
        }
        sum += dq.front().value;
    }
    fout << sum;
    return 0;
}