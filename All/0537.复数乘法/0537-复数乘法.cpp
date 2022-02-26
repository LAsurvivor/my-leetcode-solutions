class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        auto sep = [] (string s) {
            int a, b, n = s.size();
            string sa, sb;
            for(int i = 0; i < n; i++){
                if(s[i] == '+'){
                    sa = s.substr(0, i);
                    if(i < n - 2) sb = s.substr(i + 1, n - i - 2);
                    else sb = "0";
                    break;
                }
            }
            a = atoi(sa.c_str());
            b = atoi(sb.c_str());
            return make_pair(a, b);
        };

        auto [a1, b1] = sep(num1);
        auto [a2, b2] = sep(num2);
        int a, b;

        a = a1 * a2 - b1 * b2;
        b = a1 * b2 + a2 * b1;

        return (to_string(a) + "+" + to_string(b) + "i");
    }
};