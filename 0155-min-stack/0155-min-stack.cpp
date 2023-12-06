class MinStack {
public:
    stack<int>s ;
    stack<int>love;
    MinStack() {}
    void push(int val) {
        s.push(val);
          if(love.size()==0 || love.top()>=val){
              love.push(val);
          }
        return ;
    }
    
    void pop() {
        if(s.top()==love.top()){
            love.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return love.top();
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