#include<bits/stdc++.h>
using namespace std;
ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");
const int nmax = 50010;
const int inf = (1 << 30);
vector<bool> inside_pq(nmax);
vector<int> dist(nmax);
struct compare{
    bool operator()(int x, int y){
        return dist[x] > dist[y];
   }
};
int main(){
    int n, m;
    fin >> n >> m;
    vector<pair<int, int>> adj[nmax];
    priority_queue<int, vector<int>, compare> pq;
    for(int i = 1; i <= m; i++){
        int x, y, z;
        fin >> x >> y >> z;
        adj[x].push_back({y, z});
    }
    for(int i = 1; i <= n; i++){
        dist[i] = inf;
    }
    dist[1] = 0;
    pq.push(1);
    inside_pq[1] = true;
    while(!pq.empty()){
        int p = pq.top();
        pq.pop();
        inside_pq[p] = false;
        for(auto it : adj[p]){
            int neighbour = it.first;
            int cost = it.second;
            if(dist[p] + cost < dist[neighbour]){
                dist[neighbour] = dist[p] + cost;
                if(inside_pq[neighbour] == false){
                    pq.push(neighbour);
                    inside_pq[neighbour] = true;
                }
            }
        }
    }
    for(int i = 2; i <= n; i++){
        if(dist[i] != inf){
            fout << dist[i] << " ";
        }
        else{
            fout << 0 << " ";
        }
    }
    return 0;
}