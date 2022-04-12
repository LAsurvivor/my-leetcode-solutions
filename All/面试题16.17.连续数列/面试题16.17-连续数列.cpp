class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxVal = nums[0], minVal = nums[0];
        int minIdx = 0;

        for(int i = 1; i < nums.size(); i++){
            nums[i] += nums[i-1];
            if (nums[minIdx] < 0 && nums[i] - nums[minIdx] > maxVal){
                maxVal = nums[i] - nums[minIdx];
            } else if (nums[minIdx] >= 0 && nums[i] > maxVal){
                maxVal = nums[i];
            }
            if(nums[i] < minVal) {
                minVal = nums[i];
                minIdx = i;
            } 
        }
        return maxVal;
    }
};