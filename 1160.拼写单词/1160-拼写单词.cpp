class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        for(auto& c : chars) mp[c]++;

        int cnt = 0;
        for(auto& word : words){
            int flag = 1;
            unordered_map<char, int> tmp = mp;
            for(auto& c : word){
                if(!tmp.count(c)){
                    flag = 0;
                    break;
                } else {
                    if(tmp[c] == 1) tmp.erase(c);
                    else tmp[c]--;
                }
            }
            if(flag) cnt += word.size();
        }
        return cnt;
    }
};