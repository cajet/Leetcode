class MyQueue {
public:
	stack<int> s1;
	stack<int> s2;
	/** Initialize your data structure here. */
	MyQueue() {
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		s1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (s2.empty()) {
			while (!s1.empty()) {
				int s1_top = s1.top();
				s1.pop();
				s2.push(s1_top);
			}
		}
		int temp = s2.top();
		s2.pop();
		return temp;
	}

	/** Get the front element. */
	int peek() {
		if (s2.empty()) {
			while (!s1.empty()) {
				int s1_top = s1.top();
				s1.pop();
				s2.push(s1_top);
			}
		}
		int temp = s2.top();
		return temp;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		if (s1.empty() && s2.empty()) return true;
		else return false;
	}
};