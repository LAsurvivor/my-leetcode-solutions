class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;
        string s = "balon";
        for(auto& i : s) mp[i] = 0;

        for(auto& i : text){
            if(i == 'b' || i == 'a' || i == 'l' || i == 'o' || i == 'n')
                mp[i]++;
        }

        mp['l'] /= 2; mp['o'] /= 2;
        int ans = INT_MAX;
        for(auto& i : s) ans = min(ans, mp[i]);

        return ans;
    }
};