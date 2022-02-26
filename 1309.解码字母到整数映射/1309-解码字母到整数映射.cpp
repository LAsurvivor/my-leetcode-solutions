class Solution {
public:
    string freqAlphabets(string s) {
        string ans;

        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '#'){
                ans.push_back('a'+(s[i-2]-'0')*10+(s[i-1]-'0')-1);
                i -= 2;
            } else {
                ans.push_back(s[i]-'0'+'a'-1);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};