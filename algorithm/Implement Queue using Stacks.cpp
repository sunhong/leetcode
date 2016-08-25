#include <stack>
using namespace std;

class Queue {
private:
    stack<int> st1,st2;
public:
    // Push element x to the back of queue.
    void push(int x) {
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        st1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        st2.pop();
    }

    // Get the front element.
    int peek(void) {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        return st2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (st1.empty() && st2.empty());
    }
};