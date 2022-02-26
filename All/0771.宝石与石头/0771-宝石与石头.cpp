class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> st;
        for(auto& i : jewels) st.insert(i);

        int cnt = 0;
        for(auto& i : stones)
            if(st.count(i)) cnt++;
        
        return cnt;
    }
};