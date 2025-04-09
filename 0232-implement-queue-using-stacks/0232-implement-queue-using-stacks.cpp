class MyQueue {
public:
stack<int>A;
stack<int>B;
    MyQueue() {
        
    }
    
    void push(int x) {
        A.push(x);
    }
    
    int pop() {
       if(empty()) 
       return 0;
       else if(!B.empty()){
        int element=B.top();
        B.pop();
        return element;
       }
       else {

       
       while(!A.empty()){
        B.push(A.top());
        A.pop();
       }
       int element=B.top();
        B.pop();
        return element;
       }
    }
    
    int peek() {
        if(empty())
        return 0;

        else if(!B.empty())
        return B.top();
        else
        {
            while(!A.empty()){
        B.push(A.top());
        A.pop();
       }
       return B.top();
        }
    }
    
    bool empty() {
       return A.empty() && B.empty();
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