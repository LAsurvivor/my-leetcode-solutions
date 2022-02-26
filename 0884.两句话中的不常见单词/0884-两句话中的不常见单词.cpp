class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        s1 = s1 + ' ';
        s2 = s2 + ' ';
        unordered_multiset<string> st1, st2;

        int fast = 0, slow = 0;
        while(slow < s1.size()){
            while(s1[fast] != ' ') fast++;
            st1.insert(s1.substr(slow, fast-slow));
            slow = fast + 1;
            fast++;
        }
        slow = 0; fast = 0;
        while(slow < s2.size()){
            while(s2[fast] != ' ') fast++;
            st2.insert(s2.substr(slow, fast-slow));
            slow = fast + 1;
            fast++;
        }
        vector<string> ans;
        for(auto& i : st1){
            if(!st2.count(i) && st1.count(i) == 1) ans.push_back(i);
            else st2.erase(i);
        }

        for(auto& i : st2)
            if(st2.count(i) == 1) ans.push_back(i);
        return ans;
    }
};