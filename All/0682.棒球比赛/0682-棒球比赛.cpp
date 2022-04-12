class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ans = 0;
        vector<int> vec;

        for (auto& i : ops) {
            if (i[0] == 'C') {
                vec.erase(vec.end() - 1);
            } else if (i[0] == 'D') {
                int n = vec.size();
                vec.push_back(vec[n-1] * 2);
            } else if (i[0] == '+') {
                int n = vec.size();
                vec.push_back(vec[n-1] + vec[n-2]);
            } else {
                vec.push_back(stoi(i));
            }
        }

        for(auto& i : vec) ans += i;
        return ans;
    }
};