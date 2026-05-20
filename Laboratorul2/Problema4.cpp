#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<bool>> knows(n, vector<bool>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                knows[i][j] = false;
            }
            else{
                int number;
                cin >> number;
                if(number % 2 == 0){
                    knows[i][j] = true;
                }
                else{
                    knows[i][j] = false;
                }
            }
        }
    }
    int curr = 0;
    for(int i = 1; i < n; i++){
        if(knows[curr][i]){
            curr = i;
        }
    }
    bool ok = true;
    for(int i = 0; i < n; i++){
        if(knows[curr][i]){
            ok = false;
        }
    }
    if(ok == true){
        cout << curr << "is a celebrity" << '\n';
    }
    else{
        cout << "No one is a celebrity" << '\n';
    }
    return 0;
}