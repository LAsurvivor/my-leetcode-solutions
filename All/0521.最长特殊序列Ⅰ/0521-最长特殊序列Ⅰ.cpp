class Solution {
public:
    int findLUSlength(string a, string b) {
        int la = a.size(), lb = b.size();
        if(la < lb) return lb;
        if(la > lb) return la;
        if(a != b) return la;
        return -1;
    }
};