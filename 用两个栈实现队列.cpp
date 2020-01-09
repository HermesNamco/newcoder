class Solution		//原理就是如果发生push操作，就把所有数据倒入STACK1，如果发生pop操作，就把所有数据倒入STACK2。
{
public:
    void push(int node) {
        if(stack2.empty())
            stack1.push(node);
        else{
            while(!stack2.empty()){
                stack1.push(stack2.top());
                stack2.pop();
            }
            stack1.push(node);
        }
        return;
    }

    int pop() {
        if(stack1.empty()){
            int result = stack2.top();
            stack2.pop();
            return result;
        }else{
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
            int result = stack2.top();
            stack2.pop();
            return result;
        }
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};