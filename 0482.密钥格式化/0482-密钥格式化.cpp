class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans;
        int cnt = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            char tmp = s[i];
            if(tmp == '-') continue;
            if(tmp >= 'a') tmp -= 32;
            if(cnt == k){
                cnt = 0;
                ans.push_back('-');
            }
            ans.push_back(tmp);
            cnt++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};