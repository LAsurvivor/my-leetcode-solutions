class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int r = nums.size() - 1, l = 0;
        while(l < r){
            int mid = ((r - l) >> 1) + l;
            if(nums[mid] == nums[mid^1]){
                l = mid + 1;
            } else r = mid;
        }
        return nums[l];
    }
};