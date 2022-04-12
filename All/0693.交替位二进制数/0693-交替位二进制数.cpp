class Solution {
public:
    bool hasAlternatingBits(int n) {
        int flg = n & 1;
        while(n) {
            if ((n & 1) == flg) {
                flg = !flg;
                n >>= 1;
            } else {
                return false;
            }
        }
        return true;
    }
};