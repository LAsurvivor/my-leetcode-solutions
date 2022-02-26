class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;     // mp: value, index

        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]].push_back(i);
        }

        unordered_set<int> vis;
        vis.emplace(0);
        queue<pair<int, int>> q;
        q.emplace(0, 0);

        while(!q.empty()){
            auto [tmp_i, layer] = q.front();
            q.pop();

            if(tmp_i == arr.size() - 1) return layer;

            int value = arr[tmp_i];
            if(mp.count(value)){
                for(auto& i : mp[value]){
                    if(!vis.count(i)) {
                        q.emplace(i, layer+1);
                        vis.emplace(i);
                    }
                }
                mp.erase(value);
            }
            if(!vis.count(tmp_i+1) && tmp_i + 1 < arr.size()) {
                q.emplace(tmp_i+1, layer+1);
                vis.emplace(tmp_i+1);
            }
            if(!vis.count(tmp_i-1) && tmp_i - 1 >= 0) {
                q.emplace(tmp_i-1, layer+1);
                vis.emplace(tmp_i-1);
            }
        }
        return arr.size() - 1;
    }
};