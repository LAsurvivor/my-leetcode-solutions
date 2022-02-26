class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size() == 1) return 1;
        
        int cnt = 1;
        sort(pairs.begin(), pairs.end());
        for(int i = 1; i < pairs.size(); i++){
            if(pairs[i][0] <= pairs[i-1][1]) pairs[i][1] = min(pairs[i-1][1], pairs[i][1]);
            else cnt++;
        }
        return cnt;
    }
};