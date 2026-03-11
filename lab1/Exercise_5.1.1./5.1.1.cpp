#include<iostream>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n), sum(n, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i == 0){
            sum[i] = a[i];
        }
        else{
            sum[i] = sum[i - 1] + a[i];
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        if(l == 0){
            cout << sum[r] << '\n';
        }
        else{
            cout << sum[r] - sum[l - 1] << '\n';
        }
    }
    return 0;
}
