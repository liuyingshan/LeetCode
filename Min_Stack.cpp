/*
  Min Stack Total

  Design a stack that supports push, pop, top, and retrieving the minimum
  element in constant time.

  push(x) -- Push element x onto stack.
  pop() -- Removes the element on top of the stack.
  top() -- Get the top element.
  getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
private:
    stack<int> stack_;
    stack<int> min_stack_;

public:
    void push(int x) {
        if (stack_.empty() || x <= min_stack_.top()) {
            min_stack_.push(x);
        }
        stack_.push(x);
    }

    void pop() {
        if (stack_.empty()) return;
        if (stack_.top() == min_stack_.top()) {
            min_stack_.pop();
        }
        stack_.pop();
    }

    int top() {
        return stack_.top();
    }

    int getMin() {
        return min_stack_.top();
    }
};
