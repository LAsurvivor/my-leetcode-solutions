class MinStack {
private:
    multiset<int> mst;
    stack<int> st;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        st.push(x);
        mst.insert(x);
    }
    
    void pop() {
        mst.erase(mst.find(st.top()));
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return *mst.begin();
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