class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n > 1) {
            while (n % 3 == 0) {
                n /= 3;
            }
            n -= 1;
            if (n != 0 && n % 3 != 0) return false;
        }
        return true;
    }
};