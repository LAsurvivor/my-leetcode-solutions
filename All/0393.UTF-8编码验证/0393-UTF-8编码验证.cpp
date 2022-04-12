class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        int i = 0;

        while(i < n){
            bitset<8> b(data[i]);

            int j = 0;
            for(; j < 8; j++){
                if(b[7-j] == 0) break;
            }

            if(j == 0) {
                i++;
            } else if (j == 1) return false;
            else if(j > 4) return false;
            else {
                for(int _ = 0; _ < j - 1; _++){
                    i++;
                    if(i >= n) return false;
                    b = data[i];
                    if(!(b[7] == 1 && b[6] == 0)) return false;
                }
                i++;
            }
        }
        return true;
    }
};