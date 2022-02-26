class Solution {
public:
    int reinitializePermutation(int n) {
        int ans = 0;

        auto transform = [&] (int num) {
            if(num % 2) return n / 2 + (num - 1) / 2;
            else return num / 2;
        };

        for(int i = 0; i < n; i++){
            int init = i, step = 1;
            i = transform(i);
            while(i != init){
                i = transform(i);
                step++;
            }
            ans = max(ans, step);
        }
        return ans;
    }
};