/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ans;

        int x = 1, y = 1000;

        while (x <= 1000 && y > 0) {
            while (x <= 1000 && y > 0 && customfunction.f(x, y) > z) --y;

            if (x > 1000 || y <= 0) break;
            if (customfunction.f(x, y) == z) {
                ans.push_back({x, y});
            }
            ++x;

            while (x <= 1000 && y > 0 && customfunction.f(x, y) < z) ++x;

            if (x > 1000 || y <= 0) break;
            if (customfunction.f(x, y) == z) {
                ans.push_back({x, y});
            }
            --y;
        }
        return ans; 
    }
};