class Solution {
public:
    bool check(string s){
        unordered_set<char> st;
        for(auto& i : s) st.insert(i);

        for(auto& i : s)
            if((i < 'a' && !st.count(i+32)) || (i >= 'a' && !st.count(i-32))) return false;
        
        return true;
    }

    string longestNiceSubstring(string s) {
        int n = s.size();
        if(n < 2) return "";

        int len = 0;
        string ans;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(j - i + 1 <= len) continue;
                if(check(s.substr(i, j-i+1))){
                    len = j - i + 1;
                    ans = s.substr(i, j-i+1);
                }
            }
        }
        return ans;
    }
};