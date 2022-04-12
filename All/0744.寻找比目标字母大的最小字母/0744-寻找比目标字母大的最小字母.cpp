class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int left = 0, right = n - 1;

        while (left < right) {
            int mid = ((right - left) >> 1) + left;
            if (letters[mid] < target + 1) left = mid + 1;
            else right = mid;
        }

        if (letters[left] <= target) return letters[(left+1)%n];
        else return letters[left];
    }
};