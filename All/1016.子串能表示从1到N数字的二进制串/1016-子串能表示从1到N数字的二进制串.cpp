class Solution {
public:
    bool queryString(string s, int n) {
        for(int i = 1; i <= n; i++){
            string ss = bitset<32>(i).to_string();
            ss.erase(0, ss.find('1'));
            if(s.find(ss) == string::npos) return false;
        }
        return true;
    }
};