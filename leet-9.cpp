class CQueue {
    stack<int> stack1, stack2;
public:
    CQueue() {
        // clear
        while(!stack1.empty())
            stack1.pop();
        while(!stack2.empty())
            stack2.pop();
    }
    
    void appendTail(int value) {
        while(!stack1.empty()){
            int v = stack1.top() ;
            stack1.pop();
            stack2.push(v);
        }
        stack1.push(value);

        while(!stack2.empty()){
            int v = stack2.top();
            stack2.pop();
            stack1.push(v);
        }
    }
    
    int deleteHead() {
        if (stack1.empty()) return -1;
        int v = stack1.top();
        stack1.pop();
        return v;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */