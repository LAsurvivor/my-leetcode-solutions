class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for(int i = 0; i < strs[0].size(); i++){
            for(auto str : strs){
                if(strs[0][i] != str[i]) return str.substr(0, i);
            }
        }
        
        return strs[0];
    }
};