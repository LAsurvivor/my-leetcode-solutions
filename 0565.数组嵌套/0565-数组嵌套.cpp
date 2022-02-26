class Solution {
public:
    int arrayNesting(vector<int>& nums) {
    //     int max_ = 0;
    //     for(int i = 0; i < nums.size(); i++){
    //         unordered_set<int> st;
    //         int j = i;
    //         int cnt = 0;
    //         while(!st.count(nums[j])){
    //             st.emplace(nums[j]);
    //             j = nums[j];
    //             cnt++;
    //         }
    //         max_ = max(max_, cnt);
    //         if(max_ == nums.size()) return max_;
    //     }
    //     return max_;
    // }

        int max_ = 0;
        int base = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == base) continue;
            int cnt = 0, j = nums[i];
            while(nums[j] != base){
                cnt++;
                int tmp = nums[j];
                nums[j] = base;
                j = tmp;
            }
            max_ = max(max_, cnt);
        }
        return max_;
    }
};