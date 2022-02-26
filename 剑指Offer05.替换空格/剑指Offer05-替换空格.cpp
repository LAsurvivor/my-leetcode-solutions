class Solution {
public:
    string replaceSpace(string s) {
        const string sub = "%20";
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == ' '){
                s.erase(i, 1);
                s.insert(i, sub);
            }
        }
        return s;
    }
};