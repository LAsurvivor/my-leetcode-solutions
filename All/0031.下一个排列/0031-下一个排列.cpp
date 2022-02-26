class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;
        if(nums.size() == 2 && nums[0] > nums[1]){
            sort(nums.begin(), nums.end());
            return;
        }

        for(vector<int>::iterator it = nums.end() - 1; it != nums.begin(); it--){
            if(*(it-1) >= *(it)) continue;
            sort(it, nums.end());
            int temp;
            for(vector<int>::iterator it2 = it; it2 != nums.end(); it2++){
                if(*it2 > *(it-1)){
                    temp = *it2;
                    *it2 = *(it-1);
                    *(it-1) = temp;
                    return;
                }
            }
        }

        sort(nums.begin(), nums.end());
    }
};