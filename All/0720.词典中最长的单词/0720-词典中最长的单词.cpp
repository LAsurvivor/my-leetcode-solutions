class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            if(a.size() != b.size()){
                return a.size() < b.size();
            } else {
                return a > b;
            }
        });

        unordered_set<string> st;
        st.insert("");
        string ans = "";

        for(auto& i : words){
            int len = i.size();
            if(st.count(i.substr(0, len-1))){
                st.insert(i);
                ans = i;
            }
        }
        return ans;
    }
};