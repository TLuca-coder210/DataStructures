#include<iostream>
#include <fstream>
#include<vector>
#include<stack>
using namespace std;
struct element{
    long long value, index;
};
struct all{
    long long left, right;
};
int main(){
    ifstream fin("strabunica.in");
    long long n;
    fin >> n;
    vector<element> arr(n);
    for(int i = 0; i < n; i++){
        fin >> arr[i].value;
        arr[i].index = i + 1;
    }
    stack<element> st;
    vector<all> positions(n);
    st.push(arr[0]);
    positions[0].left = -1;
    for(int i = 1; i < n; i++){
        bool ok = false;
        while(!st.empty() and ok == false){
            if(arr[i].value > st.top().value){
                positions[i].left = st.top().index;
                st.push(arr[i]);
                ok = true;
            }
            else{
                st.pop();
            }
        }
        if(!ok){
            st.push(arr[i]);
            positions[i].left = -1;
        }
    }
    while(!st.empty()){
        st.pop();
    }
    st.push(arr[n - 1]);
    positions[n - 1].right = n;
    for(int i = n - 2; i >= 0; i--){
        bool ok = false;
        while(!st.empty() and ok == false){
            if(arr[i].value > st.top().value){
                positions[i].right = st.top().index;
                st.push(arr[i]);
                ok = true;
            }
            else{
                st.pop();
            }
        }
        if(!ok){
            positions[i].right = n;
            st.push(arr[i]);
        }
    }
    long long maxi = -1;
    for(int i = 0; i < n; i++){
        maxi = max(maxi, arr[i].value * (positions[i].right - positions[i].left - 1));
    }
    ofstream fout("strabunica.out");
    fout << maxi << '\n';
    return 0;
}