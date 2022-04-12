class Solution {
public:
    int trailingZeroes(int n) {
        if(n == 0) return 0;

        int ans = 0;
        for(int i = 5; i <= n; i += 5) {
            int tmp = i;
            while(tmp % 5 == 0){
                ans++;
                tmp /= 5;
            }
        }
        return ans;
    }
};