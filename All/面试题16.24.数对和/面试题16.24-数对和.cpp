class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<vector<int>> ans;

        for(auto& i : nums){
            if(mp.count(target-i) && mp[target-i] != 0){
                ans.push_back({target-i, i});
                mp[target-i]--;
            } else if(mp.count(i)){
                mp[i]++;
            } else mp[i] = 1;
        }

        return ans;
    }
};