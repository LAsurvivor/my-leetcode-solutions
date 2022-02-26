class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cap = 0, min_cap = INT_MAX, start = -1, n = gas.size();
        for(int i = 0; i < n; i++){
            cap += gas[i] - cost[i];
            if(cap < min_cap){
                min_cap = cap;
                start = i;
            }
        }
        return cap >= 0 ? (start + 1) % n : -1;
    }
};