class Solution {
public:
    bool isUnique(string astr) {
        unordered_set<char> st;
        for(auto& c : astr) {
            if (st.count(c)) return false;
            st.insert(c);
        }
        return true;

        // sort(astr.begin(), astr.end());
        // for(int i = 1; i < astr.size(); ++i) {
        //     if (astr[i-1] == astr[i]) return false;
        // }
        // return true;
    }
};