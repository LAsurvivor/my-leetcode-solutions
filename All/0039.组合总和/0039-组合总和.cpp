class Solution {
public:
    bool dfs(vector<int>& vec, vector<int> part, int sum, int& target, set<vector<int>>& ans){
        if(sum == target) return true;

        int tmp_sum;
        vector<int> tmp_part;
        for(auto& i : vec){
            if(sum > target - i) break;
            tmp_part = part;
            tmp_part.push_back(i);
            tmp_sum = sum;
            tmp_sum += i;
            if(dfs(vec, tmp_part, tmp_sum, target, ans)){
                sort(tmp_part.begin(), tmp_part.end());
                ans.insert(tmp_part);
            }
        }
        return false;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        set<vector<int>> ans;
        vector<int> part;

        dfs(candidates, part, 0, target, ans);

        vector<vector<int>> res;
        res.assign(ans.begin(), ans.end());

        return res;
    }
};