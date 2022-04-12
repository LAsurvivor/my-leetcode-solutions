class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [] (const vector<int> v1, const vector<int> v2) {
            return v1[1] > v2[1];
        });

        int ans = 0;
        for (auto& box : boxTypes) {
            if (box[0] <= truckSize) {
                ans += box[0] * box[1];
                truckSize -= box[0];
            } else {
                ans += truckSize * box[1];
                truckSize = 0;
            }
            if (truckSize == 0) break;
        }
        return ans;
    }
};