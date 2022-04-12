class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        int ans = -1;
        auto binary_search = [&] (auto self, int left, int right) {
            if(left > right) return;

            int mid = ((right - left) >> 1) + left;

            if(mid == nums[mid]){
                ans = mid;
                self(self, left, mid - 1);
            } else {
                self(self, left, mid - 1);
                if(ans == -1 || ans > right) self(self, mid + 1, right);
            }
            return;
        };
        binary_search(binary_search, 0, nums.size() - 1);
        return ans;
    }
};