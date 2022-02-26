class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        auto find_max = [&] (int end) {
            int max_ = 0, idx = 0;
            for(int i = 0; i <= end; i++){
                if(arr[i] > max_){
                    max_ = arr[i];
                    idx = i;
                }
            }
            return idx;
        };
        
        vector<int> ans;
        int end = arr.size() - 1;
        while(end){
            int tmp = find_max(end);
            if(tmp != end){
                reverse(arr.begin(), arr.begin() + tmp + 1);
                reverse(arr.begin(), arr.begin() + end + 1);
                if(tmp) ans.push_back(tmp+1);
                if(end) ans.push_back(end+1);
            }
            end--;
        }
        return ans;        
    }
};