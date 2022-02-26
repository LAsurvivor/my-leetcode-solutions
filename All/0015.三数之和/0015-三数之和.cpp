class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};

        int left, right;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;


        for(int i = 0; i < nums.size() - 2; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            right = nums.size() - 1;
            
            for(left = i + 1; left < nums.size() - 1; left++){
                if(left > i + 1 && nums[left] == nums[left - 1]) continue;

                while(nums[i] + nums[left] + nums[right] > 0 && right > left){
                    right--;
                }

                if(right <= left) break;

                if(nums[i] + nums[left] + nums[right] == 0)
                    res.push_back({nums[i], nums[left], nums[right]});
            }
        }

        return res;
    }
};