class Solution {
public:
    string pushDominoes(string dominoes) {
        auto fast = dominoes.begin(), slow = fast;

        while(fast != dominoes.end()){
            while(fast != dominoes.end() && *fast != 'R'){
                if(*fast == 'L'){
                    while(slow != fast){
                        *slow = 'L';
                        slow++;
                    }
                }
                fast++;
            }
            if(fast == dominoes.end()) break;

            slow = fast;
            while(fast != dominoes.end() && *fast != 'L'){
                if(*fast == 'R'){
                    while(slow != fast){
                        *slow = 'R';
                        slow++;
                    }
                }
                fast++;
            }
            if(fast == dominoes.end()){
                while(slow != dominoes.end()){
                    *slow = 'R';
                    slow++;
                }
                break;
            }

            while(*slow == 'R') slow++;
            
            if(*slow == 'L') continue;
            else{
                int gap = fast - slow;
                for(int i = 0; i < gap / 2; i++){
                    *slow = 'R';
                    slow++;
                }
                if(gap & 1) slow++;
                while(slow != fast){
                    *slow = 'L';
                    slow++;
                }
            }
        }
        return dominoes;
    }
};
/*
.L.R...LR..L..
.L.RRRRRRRRR..
LL.LLLLLLLLL..
*/