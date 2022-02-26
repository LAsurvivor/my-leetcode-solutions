class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.size() - 1;

        auto is_letter = [] (char c){
            return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
        };

        while(i < j){
            while(!is_letter(s[i]) && i < s.size() - 1) i++;
            while(!is_letter(s[j]) && j > 0) j--;
            if(i >= j) break;
            swap(s[i], s[j]);
            i++;
            j--;
        }

        return s;
    }
};