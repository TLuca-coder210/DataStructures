class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long left = 0, right = 1e7 + 1;
        while(left != right){
            long long mid = left + (right - left) / 2 + 1, total = 0;
            for(int i = 0; i < candies.size(); i++){
                total += candies[i] / mid;
            }
            if(total >= k){
                left = mid;
            }
            else{
                right = mid - 1;
            }
        }
        return left;
    }
};
