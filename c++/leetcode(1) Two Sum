class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> number;
        int size = nums.size();
        for(int i = 0; i <= size - 2; ++i){
            for(j = i+1; j <= size - 1; ++j){
                if(nums[i]+nums[j] == target)
                {
                    number.push_back(i);
                    number.push_back(j);
                }
            }
        }
        return number;
    }
};