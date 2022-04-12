class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> cnt;
        for (auto& word : words) {
            string tmp = "";
            for (auto& c : word) {
                tmp += code[c-'a'];
            }
            cnt.insert(tmp);
        }
        return cnt.size();
    }
};