class Solution {
private:
    double findKth(vector<int>& nums1, vector<int>& nums2, int k){
        int m, n, i, j, ii, jj;
        m = nums1.size();
        n = nums2.size();
        i = 0;
        j = 0;
        
        while(1){
            if(i == m) return nums2[j + k - 1];
            if(j == n) return nums1[i + k - 1];
            if(k == 1) return min(nums1[i], nums2[j]);
            
            ii = min(i + k / 2 - 1, m - 1);
            jj = min(j + k / 2 - 1, n - 1);
            
            if(nums1[ii] < nums2[jj]){
                k -= (ii - i) + 1;
                i = ii + 1;
            }
            else{
                k -= (jj - j) + 1;
                j = jj + 1;
            }
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        
        if(len % 2)
            return findKth(nums1, nums2, (len + 1) / 2);
        else
            return (findKth(nums1, nums2, len / 2) + findKth(nums1, nums2, len / 2 + 1)) / 2.0;
    }
};