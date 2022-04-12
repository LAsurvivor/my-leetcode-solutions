class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st;
        for(auto& i : candyType) st.insert(i);
        int n = candyType.size(), type = st.size();
        return n / 2 > type ? type : n / 2;
    }
};