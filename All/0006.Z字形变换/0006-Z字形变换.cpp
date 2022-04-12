class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        
        string res;
        
        int len = 2 * numRows - 2;
        
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < s.size(); j++){
                if(j % len == i || len - j % len == i)
                    res = res + s[j];
            }
        }
        
        return res;
    }
};