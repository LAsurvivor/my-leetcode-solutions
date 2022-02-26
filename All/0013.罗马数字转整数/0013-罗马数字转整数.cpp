class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> map = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};

        for(int i = 0; i < s.size(); i++){
            if(i != s.size() - 1 && (map.find(s[i+1]))->second > (map.find(s[i]))->second)
                res -= (map.find(s[i]))->second;
            else
                res += (map.find(s[i]))->second;
        }

        return res;
    }
};