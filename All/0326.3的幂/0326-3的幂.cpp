class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;

        // if(n < 1) return false;
        // double x = log(n) / log(3);
        // if(x - round(x) > pow(10, -14)) return false;
        // return true;
    }
};