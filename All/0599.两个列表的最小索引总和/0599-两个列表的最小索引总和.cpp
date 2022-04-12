class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        int n1 = list1.size(), n2 = list2.size();
        for(int i = 0; i < n1; i++) mp[list1[i]] = i;

        vector<string> ans;
        int val = n1 + n2;
        for(int i = 0; i < n2; i++){
            string tmp = list2[i];
            if(mp.count(tmp)){
                if(i + mp[tmp] < val){
                    val = i + mp[tmp];
                    vector<string> tv;
                    swap(tv, ans);
                    ans.push_back(tmp);
                } else if(i + mp[tmp] == val){
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};