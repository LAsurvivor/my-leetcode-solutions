class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].size();
        int n = words.size();
        multiset<string> st;

        for(auto& i : words){
            st.emplace(i);
        }

        vector<int> ans;
        for(int i = 0; i < s.size(); i++){
            if(s.size() - i < n * len) break;

            multiset<string> cmp;
            for(int j = 0; j < n; j++){
                cmp.emplace(s.substr(i+j*len, len));
            }
            if(st == cmp) ans.push_back(i);
        }
        return ans;
    }
};