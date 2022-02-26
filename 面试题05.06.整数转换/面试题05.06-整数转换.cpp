class Solution {
public:
    int convertInteger(int A, int B) {
        unsigned int diff = A ^ B;
        int cnt = 0;
        while(diff){ 
            cnt += diff & 1;
            diff >>= 1;
        }
        return cnt;
    }
};