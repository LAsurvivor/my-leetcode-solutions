class Solution {
using pic = pair<int, char>;
public:
    string reorganizeString(string s) {
        int len = s.size();
        unordered_map<char, int> mp;

        for(auto& i : s) mp[i]++;
    
        auto cmp = [] (pic p1, pic p2) {
            return p1.first < p2.first;
        };
        priority_queue<pic, vector<pic>, decltype(cmp)> q(cmp);

        for(auto it = mp.begin(); it != mp.end(); it++){
            q.push({it->second, it->first});
        }

        string ans = "\0";
        while(!q.empty()){
            auto [n, c] = q.top();
            q.pop();

            if(ans.back() == c){
                if(q.empty()) break;

                auto tmp = q.top();
                q.pop();
                q.push({n, c});

                n = tmp.first;
                c = tmp.second;
            }
            ans += c;
            if(--n) q.push({n, c});
        }

        if(len == ans.size()) return ans;
        return "";
    }
};