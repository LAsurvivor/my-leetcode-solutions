class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return !(abs(coordinates[0] - 'a' - coordinates[1]) & 1);
    }
};