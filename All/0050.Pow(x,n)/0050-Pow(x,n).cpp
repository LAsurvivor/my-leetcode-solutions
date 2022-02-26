class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(x == 1) return 1;
        if(x == -1) return abs(n) % 2 ? -1 : 1;

        double ans = 1, temp;
        long int i, nn = n;
        int flag = 1;
        if(n < 0){
            flag = 0;
            nn = -nn;
        }

        // main
        while(nn > 0){
            i = 1;
            temp = x;
            while(i << 1 <= nn){
                temp *= temp;
                i = i << 1;
            }
            ans *= temp;
            nn -= i;
        }

        return flag ? ans : 1 / ans;
    }
};