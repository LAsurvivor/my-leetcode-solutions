class Solution {
using ll = long long;
public:
    int findKthNumber(int n, int k) {
        auto getSteps = [] (int curr, int n) {
            int steps = 0;
            ll first = curr, last = curr;
            while(first <= n) {
                steps += (last < n ? last : n) - first + 1;
                first *= 10;
                last = last * 10 + 9;
            }
            return steps;
        };

        int curr = 1;
        k--;
        while(k > 0) {
            int steps = getSteps(curr, n);
            if(steps <= k) {
                k -= steps;
                curr++;
            } else {
                curr *= 10;
                k--;
            }
        }
        return curr;
    }
};