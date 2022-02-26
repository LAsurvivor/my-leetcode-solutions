class Solution {
public:
    int longestBeautifulSubstring(string word) {
        if(word.size() < 5) return 0;
        vector<char> lst{'a', 'e', 'i', 'o', 'u'};
        int cnt = 0, len = 0, ans = 0, flag = 0;

        for(int i = 0; i < word.size(); i++){
            if(word[i] == 'a') flag = 1;

            if(word[i] == lst[cnt]) len++;
            else if(flag && cnt != 4 && word[i] == lst[cnt+1]){
                cnt++;
                len++;
            } else {
                if(cnt == 4) ans = max(ans, len);
                len = word[i] == 'a' ? 1 : 0;
                cnt = 0;
                flag = word[i] == 'a' ? 1 : 0;
            }
        }
        if(cnt == 4) ans = max(ans, len);
        return ans;
    }
};