class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(!nums.size()) return 0;

        int count = 0, temp;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                temp = nums[i];
                nums[i] = nums[count];
                nums[count] = temp;
                count++;
            }
        }

        return count;
    }
};