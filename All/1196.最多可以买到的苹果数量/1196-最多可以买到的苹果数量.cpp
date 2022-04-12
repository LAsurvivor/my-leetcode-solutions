class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        sort(weight.begin(), weight.end());

        if (weight[0] > 5000) return 0;
        for (int i = 1; i < weight.size(); ++i) {
            if (5000 - weight[i-1] < weight[i]) return i;
            weight[i] += weight[i-1];
        }
        return weight.size();
    }
};