class Solution {
using pic = pair<int, char>;
public:
    string longestDiverseString(int a, int b, int c) {
        auto cmp = [] (pic p1, pic p2) {
            return p1.first < p2.first;
        };

        priority_queue<pic, vector<pic>, decltype(cmp)> q(cmp);

        if(a) q.push(make_pair(a, 'a'));
        if(b) q.push(make_pair(b, 'b'));
        if(c) q.push(make_pair(c, 'c'));

        string ans = "xx";
        while(!q.empty()){
            auto [num, ch] = q.top();
            if(ans[ans.size() - 1] == ch && ans[ans.size() - 2] == ch){
                auto tmp = q.top();
                q.pop();

                if(q.empty()) break;

                num = q.top().first;
                ch = q.top().second;
                q.pop();
                q.push(tmp);
            } else q.pop();

            ans += ch;
            num--;
            if(num) q.push(make_pair(num, ch));
        }
        ans = ans.substr(2, ans.size() - 2);
        return ans;
    }
};