class CQueue {
public:
    stack<int> st1;
    stack<int> st2;

    CQueue() {

    }
    
    void appendTail(int value) {
        if(!st2.empty()){
            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
        }
        st1.push(value);
    }
    
    int deleteHead() {
        if(st1.empty() && st2.empty()) return -1;
        
        if(!st1.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int ans = st2.top();
        st2.pop();
        return ans;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */