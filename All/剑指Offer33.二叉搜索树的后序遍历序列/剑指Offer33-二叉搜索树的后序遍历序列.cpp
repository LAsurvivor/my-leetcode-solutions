class Solution {
public:
    bool recur(vector<int>& vec, int left, int root) {
        if (left >= root) return true;

        int mid = left;
        while (vec[mid] < vec[root]) ++mid;
        int right = mid;
        while (vec[right] > vec[root]) ++right;

        return right == root && recur(vec, left, mid - 1) && recur(vec, mid, right - 1);
    }

    bool verifyPostorder(vector<int>& postorder) {
        return recur(postorder, 0, postorder.size() - 1);
    }
};