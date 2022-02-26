class MinStack {
private:
    stack<int> data, data_rep;    
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        data.push(x);
        if(data_rep.empty() || data_rep.top() >= x){data_rep.push(x); }
    }
    
    void pop() {
        if(data.top() == data_rep.top()){data_rep.pop(); }
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return data_rep.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */