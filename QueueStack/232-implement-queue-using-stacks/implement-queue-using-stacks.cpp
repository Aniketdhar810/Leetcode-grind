class MyQueue {
public:
    stack<int>st;
    stack<int> temp;
    MyQueue() {

    }
    
    void push(int x) {
        while(!st.empty()){
            int tempval=st.top();
            temp.push(tempval);
            st.pop();
        }
        st.push(x);
        while(!temp.empty()){
            int tempval=temp.top();
            st.push(tempval);
            temp.pop();
        }
    }
    
    int pop() {
        int temp=st.top();
        st.pop();
        return temp;
    }
    
    int peek() {
        int temp=st.top();
        return temp;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */