class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if(k == 1) return 1;

        vector<int> fib;
        fib.push_back(1);

        int a = 1, b = 1;
        while(b <= k){
            a = a + b;
            swap(a, b);
            fib.push_back(a);
        }

        int ans = 1;
        k -= fib.back();
        while(k){
            k -= *(upper_bound(fib.begin(), fib.end(), k) - 1);
            ans++;
        }

        return ans;
    }
};