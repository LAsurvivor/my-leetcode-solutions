class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        if(n < 2) return {};
        vector<string> ans;

        auto mutual_prime = [] (int a, int b) {
            int tmp = a % b;
            while(tmp){
                a = b;
                b = tmp;
                tmp = a % b;
            }
            return b == 1;
        };

        for(int den = 2; den <= n; den++){
            for(int num = 1; num < den; num++){
                if(mutual_prime(den, num)){
                    ans.push_back(to_string(num) + "/" + to_string(den));
                }
            }
        }
        return ans;
    }
};