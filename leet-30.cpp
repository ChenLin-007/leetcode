class MinStack {
    stack<int> stk;
    stack<int> m;
    // must have another stack;
public:
    /** initialize your data structure here. */
    MinStack() {
        while(!stk.empty())
            stk.pop();
    }
    
    void push(int x) {
        stk.push(x);
        if(m.empty()){
            m.push(x);
        } else {
            if (x <= m.top()){
                m.push(x);
            }
        }
    }
    
    void pop() {
        int v = stk.top();
        if (v == m.top()){
            m.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int min() {
        return m.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */