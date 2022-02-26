class Solution {
private:
    stack<char> st;
public:
    bool isValid(string s) {
        for(int i = 0; i < s.length(); i++){
            switch(s[i]){
                case '(': 
                case '[':
                case '{': st.push(s[i]); break;
                case ')': 
                    if(!st.empty() && st.top() == '(') st.pop();
                    else return false; break;
                case ']': 
                    if(!st.empty() && st.top() == '[') st.pop();
                    else return false; break;
                case '}': 
                    if(!st.empty() && st.top() == '{') st.pop();
                    else return false; break;
                default: break;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};