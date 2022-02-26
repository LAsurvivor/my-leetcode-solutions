class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int max_ = 0, cnt = 0;
        for(auto& i : rectangles){
            int tmp = min(i[0], i[1]);
            if(max_ < tmp){
                max_ = tmp;
                cnt = 1;
            } else if (max_ == tmp){
                cnt++;
            }
        }
        return cnt;
    }
};