class Solution {
public:
    int maxVowels(string s, int k) {
        auto is_vowel = [] (char& c){
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        int cnt = 0;
        for(int i = 0; i < k; i++){
            if(is_vowel(s[i])) cnt++;
        }
        int ans = cnt;
        for(int i = k; i < s.size(); i++){
            cnt = cnt + is_vowel(s[i]) - is_vowel(s[i-k]);
            ans = max(ans, cnt);
        }
        return ans;
    }
};