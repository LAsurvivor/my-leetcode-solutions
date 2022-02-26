class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int tot_min = 24 * 60;
        if(timePoints.size() > tot_min) return 0;

        int min_ = INT_MAX;

        auto to_min = [] (string &s) {
            return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
        };

        for(int i = 0; i < timePoints.size() - 1; i++){
            for(int j = i + 1; j < timePoints.size(); j++){
                int t1 = to_min(timePoints[i]);
                int t2 = to_min(timePoints[j]);

                int gap1 = abs(t1 - t2);
                int gap2 = min(t1, t2) + min(tot_min - t1, tot_min - t2);

                if(min_ > min(gap1, gap2)) min_ = min(gap1, gap2);
            }
        }

        return min_;
    }
};