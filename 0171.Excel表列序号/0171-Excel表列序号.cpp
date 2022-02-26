class Solution {
public:
    int titleToNumber(string columnTitle) {
        int cnt = 0;

        for(auto it = columnTitle.begin(); it != columnTitle.end(); it++){
            cnt *= 26;
            cnt += *it - 'A' + 1;
        }
        return cnt;
    }
};