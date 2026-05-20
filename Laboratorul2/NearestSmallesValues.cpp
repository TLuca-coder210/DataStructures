#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct element{
    long long value, index;
};
int main(){
    long long n;
    cin >> n;
    vector<element> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].value;
        arr[i].index = i + 1;
    }
    stack<element> st;
    st.push(arr[0]);
    cout << 0 << " ";
    for(int i = 1; i < n; i++){
        bool ok = false;
        while(!st.empty() and ok == false){
            if(arr[i].value > st.top().value){
                cout << st.top().index << " ";
                st.push(arr[i]);
                ok = true;
            }
            else{
                st.pop();
            }
        }
        if(!ok){
            st.push(arr[i]);
            cout << 0 << " ";
        }
    }
    return 0;
}