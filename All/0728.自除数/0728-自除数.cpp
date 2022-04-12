class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        auto isSelfDividing = [] (int num) {
            int ori = num;
            while(num){
                if(num % 10 == 0) return false;
                if(ori % (num % 10)) return false;
                num /= 10;
            }
            return true;
        };

        vector<int> ans;
        for(int i = left; i <= right; i++){
            if(isSelfDividing(i)) ans.push_back(i);
        }
        return ans;
    }
};