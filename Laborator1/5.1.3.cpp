class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int first_index = matrix.size() - 1, second_index = 0;
        while(first_index >= 0 and second_index < matrix[0].size()){
            if(matrix[first_index][second_index] == target){
                return true;
            }
            else if(matrix[first_index][second_index] < target){
                second_index++;
            }
            else{
                first_index--;
            }
        }
        return false;
    }
};
