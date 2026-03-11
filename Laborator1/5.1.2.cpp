class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int first_index = 0, second_index = numbers.size() - 1;
        while(numbers[first_index] + numbers[second_index] != target){
            if(numbers[first_index] + numbers[second_index] < target){
                first_index++;
            }
            else{
                second_index--;
            }
        }
        return {first_index + 1, second_index + 1};
    }
};
