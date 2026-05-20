class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> prefix_sums(m, vector<int>(n, 0));
    for(int j = 0; j < n; j++){
        for(int i = 0; i < m; i++){
            if(i == 0){
                if(matrix[i][j] == '1'){
                    prefix_sums[i][j] = 1;
                }
            }
            else{
                if(matrix[i][j] == '1'){
                    prefix_sums[i][j] = prefix_sums[i - 1][j] + 1;
                }
            }
        }
    }
    int maxi = 0;
    for(int idx = 0; idx < m; idx++){
        vector<int> previous(n, -1);
        vector<int> next(n, n);
        stack<int> s;
        s.push(0);
        for(int i = 1; i < n; i++){
            bool ok = false;
            while(!s.empty() && !ok){
                if(prefix_sums[idx][i] > prefix_sums[idx][s.top()]){
                    previous[i] = s.top();
                    ok = true;
                }
                else{
                    s.pop();
                }
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        s.push(n - 1);
        for(int i = n - 2; i >= 0; i--){
            bool ok = false;
            while(!s.empty() && !ok){
                if(prefix_sums[idx][i] > prefix_sums[idx][s.top()]){
                    next[i] = s.top();
                    ok = true;
                }
                else{
                    s.pop();
                }
            }
            s.push(i);
        }
        for(int i = 0; i < n; i++){
            int distance = next[i] - previous[i] - 1;
            int area = prefix_sums[idx][i] * distance;
            if(area > maxi){
                maxi = area;
            }
        }
    }
    return maxi;
    }
};