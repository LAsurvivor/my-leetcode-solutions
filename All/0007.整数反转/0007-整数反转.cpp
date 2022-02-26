class Solution {
public:
    int reverse(int x) {
        int flag = 1;
        if(x < 0) flag = -1;
        
        int res = 0;
        
        for(int i = 1; x; i++){
            if(res > INT_MAX / 10 || res < INT_MIN / 10) 
                return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        
        return res;
    }
};