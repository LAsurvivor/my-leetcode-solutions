class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        string ans = "";
        int flag = 0;
        if(num < 0){
            flag = 1;
            ans += to_string(num % 7 * -1);
            num /= 7;
            num *= -1;
        }
        while(num){
            ans += to_string(num % 7);
            num /= 7;
        }
        if(flag) ans += "-";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};