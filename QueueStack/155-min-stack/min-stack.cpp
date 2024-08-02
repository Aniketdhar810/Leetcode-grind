class MinStack {
public:
    stack<int> st;
    stack<int> min_st;
    MinStack() {
        min_st.push(INT_MAX);
    }
    
    void push(int val) {
            st.push(val);
            if (val <= min_st.top()) {
                min_st.push(val);
            }
        }
    
    void pop() {
        if (st.top() == min_st.top()) {
            min_st.pop();
        }
        st.pop();
    }
    
    int top() {
        int temp=st.top();
        return temp;
    }
    
    int getMin() {
        int temp=min_st.top();
        return temp;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */