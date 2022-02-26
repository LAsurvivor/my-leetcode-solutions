class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 递归方法
        // int left = 0, right = nums.size() - 1;
        // auto binary = [&nums, &target] (auto&& self, int l, int r){
        //     if(l > r) return l;

        //     int m = ((r - l) >> 1) + l;
        //     if(nums[m] >= target)
        //         return self(self, l, m - 1);
        //     else
        //         return self(self, m + 1, r);
        // };

        // return binary(binary, left, right);

        // 非递归方法
        // int left = 0, right = nums.size() - 1;
        // int mid;
        // while(left <= right){
        //     mid = ((right - left) >> 1) + left;
        //     if(nums[mid] >= target)
        //         right = mid - 1;
        //     else
        //         left = mid + 1;
        // }
        // return left;

        // 偷鸡方法
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};