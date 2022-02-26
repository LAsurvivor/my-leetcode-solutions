class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        string ans;
        while(i >= 0 || j >= 0 || carry){
            int ta = i >= 0 ? a[i] - '0' : 0;
            int tb = j >= 0 ? b[j] - '0' : 0;

            ans.push_back((ta + tb + carry) % 2 + '0');
            carry = (ta + tb + carry) / 2;
            i--; j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};