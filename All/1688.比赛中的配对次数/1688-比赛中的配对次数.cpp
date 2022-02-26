class Solution {
public:
    int sub(int n){
        if(n % 2) return (n - 1) / 2;
        else return n / 2;
    }

    int numberOfMatches(int n) {
        int ans = 0;
        while(n != 1){
            ans += sub(n);
            n = (n + 1) / 2;
        }
        return ans;
    }
};