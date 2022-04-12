class Solution {
public:
    int minInsertions(string s) {
        int left = 0;
        int cnt = 0, n = s.size();

        for(int i = 0; i < n; i++){
            if(s[i] == '(') left++;
            else{
                if(i == n - 1 || s[i+1] != ')'){
                    if(left > 0){
                        left--;
                        cnt++;
                    } else cnt += 2;
                } else {
                    if(left > 0) left--;
                    else cnt++;
                    i++;
                }
            }
        }
        if(left > 0) cnt += left * 2;
        return cnt;
    }
};