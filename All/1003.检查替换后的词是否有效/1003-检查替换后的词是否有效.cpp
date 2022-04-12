class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto& i : s) {
            if (i == 'a') {
                st.push(i);
            } else if (i == 'b') {
                if (st.size() >= 1 && st.top() == 'a') {
                    st.push(i);
                } else return false;
            } else {
                if (st.size() >= 2 && st.top() == 'b') {
                    st.pop();
                    if (st.top() == 'a') {
                        st.pop();
                    } else return false;
                } else return false;
            }
        }

        return st.empty();
    }
};