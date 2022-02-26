class Solution {
using pii = pair<int, int>;
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // set the wordList to be [beginWord, ... , endWord]
        // end
        auto it = find(wordList.begin(), wordList.end(), endWord);
        if(it == wordList.end()) return 0;
        else swap(*it, wordList[wordList.size()-1]);
        // begin
        wordList.insert(wordList.begin(), beginWord);
        
        auto str_cmp = [] (string s1, string s2) {
            int cnt = 0;
            for(int i = 0; i < s1.size(); i++){
                if(s1[i] != s2[i]) cnt++;
            }
            return cnt == 1;
        };

        // undirected graph
        unordered_map<int, vector<int>> graph;
        int n = wordList.size();    // note : n is equal to original size of wordList + 1
        for(int i = 0; i <n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(str_cmp(wordList[i], wordList[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        // bfs
        // <index, step>
        queue<pii> q;
        q.push(make_pair(0, 1));
        unordered_set<int> vis;

        while(!q.empty()){
            auto [idx, step] = q.front();
            q.pop();

            if(idx == n - 1) return step;
            vis.insert(idx);

            for(auto& des : graph[idx]) 
                if(!vis.count(des))
                    q.push(make_pair(des, step+1));
        }
        return 0;
    }
};