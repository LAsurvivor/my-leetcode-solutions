class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int last = bits.size() - 2;
        while(last >= 0 && bits[last]) last--;
        return ((bits.size() - last) & 1) == 0;
    }
};