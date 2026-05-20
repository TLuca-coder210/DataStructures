#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int cap_A, cap_B, distance;
    string instructions;
};
int main(){
    int A, B, C;
    cin >> A >> B >> C;
    queue<Node> q;
    q.push({0, 0, 0, ""});
    vector<vector<int>> visited(A + 1, vector<int> (B + 1, false));
    visited[0][0] = true;
    bool ok = false;
    while(!q.empty() and ok == false){
        Node element = q.front();
        q.pop();
        if(element.cap_A == C or element.cap_B == C){
            cout << element.distance << '\n';
            for(int i = 0; i < element.instructions.size(); i++){
                if(i % 2 == 0){
                    cout << element.instructions[i] << " ";
                }
                else{
                    cout << element.instructions[i] << '\n';
                }
            }
            ok = true;
        }
        else{
            if(element.cap_A == A){
                if(element.cap_B == B){
                    if(!visited[A][0]){
                        q.push({element.cap_A, 0, element.distance + 1, element.instructions + "B" + "C"});
                        visited[A][0] = true;
                    }
                    if(!visited[0][B]){
                        q.push({0, element.cap_B, element.distance + 1, element.instructions + "A" + "C"});
                        visited[0][B] = true;
                    }
                }
                else{
                    if(!visited[A][0]){
                        q.push({element.cap_A, 0, element.distance + 1, element.instructions + "B" + "C"});
                        visited[A][0] = true;
                    }
                    if(!visited[A][B]){
                        q.push({element.cap_A, B, element.distance + 1, element.instructions + "R" + "B"});
                        visited[A][B] = true;
                    }
                    if(!visited[0][element.cap_B]){
                        q.push({0, element.cap_B, element.distance + 1, element.instructions + "A" + "C"});
                        visited[0][element.cap_B] = 0;
                    }
                    //putem turna A in B
                    int new_cap_A = max(0, A - (B - element.cap_B)), new_cap_B = min(B, element.cap_B + element.cap_A);
                    if(!visited[new_cap_A][new_cap_B]){
                        q.push({new_cap_A, new_cap_B, element.distance + 1, element.instructions + "A" + "B"});
                        visited[new_cap_A][new_cap_B] = true;
                    }
                }
            }
            else{
                if(element.cap_B == B){
                    if(!visited[0][B]){
                        q.push({0, B, element.distance + 1, element.instructions + "A" + "C"});
                        visited[0][B] = true;
                    }
                    if(!visited[A][B]){
                        q.push({element.cap_A, B, element.distance + 1, element.instructions + "R" + "A"});
                        visited[A][B] = true;
                    }
                    if(!visited[element.cap_A][0]){
                        q.push({element.cap_A, 0, element.distance + 1, element.instructions + "B" + "C"});
                        visited[element.cap_A][0] = 0;
                    }
                    int A_new = min(A, element.cap_A + element.cap_B), B_new = max(0, element.cap_B - (A - element.cap_A));
                    if(!visited[A_new][B_new]){
                        q.push({A_new, B_new, element.distance + 1, element.instructions + "B" + "A"});
                        visited[A_new][B_new] = true;
                    }
                }
                else{
                    if(!visited[0][element.cap_B]){
                        q.push({0, element.cap_B, element.distance + 1, element.instructions + "A" + "C"});
                        visited[0][element.cap_B] = true;
                    }
                    if(!visited[element.cap_A][0]){
                        q.push({element.cap_A, 0, element.distance + 1, element.instructions + "B" + "C"});
                        visited[element.cap_A][0] = true;
                    }
                    if(!visited[A][element.cap_B]){
                        q.push({A, element.cap_B, element.distance + 1, element.instructions + "R" + "A"});
                        visited[A][element.cap_B] = true;
                    }
                    if(!visited[element.cap_A][B]){
                        q.push({element.cap_A, B, element.distance + 1, element.instructions + "R" + "B"});
                        visited[element.cap_A][B] = true;
                    }
                    //turnam A in B 
                    int new_A = max(0, element.cap_A - (B - element.cap_B)), new_B = min(B, element.cap_B + element.cap_A);
                    if(!visited[new_A][new_B]){
                        q.push({new_A, new_B, element.distance + 1, element.instructions + "A" + "B"});
                        visited[new_A][new_B] = true;
                    }
                    int A_new = min(A, element.cap_A + element.cap_B), B_new = max(0, element.cap_B - (A - element.cap_A));
                    if(!visited[A_new][B_new]){
                        q.push({A_new, B_new, element.distance + 1, element.instructions + "B" + "A"});
                        visited[A_new][B_new] = true;
                    }
                } 
            }
        }
    }
    return 0;
}