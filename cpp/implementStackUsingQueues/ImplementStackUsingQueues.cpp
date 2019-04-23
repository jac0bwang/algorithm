/**
 * Source : https://leetcode.com/problems/implement-stack-using-queues/
 * Author : Jacob Wang
 * Date   : 2019-04-23
 */
/**
 * Implement the following operations of a stack using queues.
 *
 *     push(x) -- Push element x onto stack.
 *     pop() -- Removes the element on top of the stack.
 *     top() -- Get the top element.
 *     empty() -- Return whether the stack is empty.
 *
 * Example:
 *
 *     MyStack stack = new MyStack();
 *
 *     stack.push(1);
 *     stack.push(2);
 *     stack.top();   // returns 2
 *     stack.pop();   // returns 2
 *     stack.empty(); // returns false
 *
 * Notes:
 *
 *     You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
 *     Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
 *     You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
 */

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
    	std::queue<int> temp_queue;
    	temp_queue.push(x);
    	while(!_data.empty()){
	    	temp_queue.push(_data.front());
	    	_data.pop();
	    }
	    while(!temp_queue.empty()){
   			_data.push(temp_queue.front());
   			temp_queue.pop();
    	}
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = _data.front();
    	_data.pop();
    	return x;
    }

    /** Get the top element. */
    int top() {
        return _data.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return _data.empty();
    }
private:
	std::queue<int> _data;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
