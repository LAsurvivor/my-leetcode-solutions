class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        multiset<int> st;

        for(auto& i : nums) st.insert(i);

        int sum = 0;
        for(auto& i : nums) {
            if(st.count(i) == 1) sum += i;
        }
        return sum;
    }
};