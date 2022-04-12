class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        bitset<32> b;

        auto isPrime = [] (int num) {
            if (num <= 1) return false;
            for (int i = 2; i <= sqrt(num); ++i) {
                if (num % i == 0) return false;
            }
            return true;
        };

        int ans = 0;
        for (int i = left; i <= right; ++i) {
            b = i;
            int tmp = b.count();
            if (isPrime(tmp)) ans++;
        }
        return ans;
    }
};