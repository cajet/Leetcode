class MyStack {
public:
	queue<int> q1;
	queue<int> q2;
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		q1.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		if (q1.size() == 1) {
			int temp = q1.front();
			q1.pop();
			return temp;
		}
		else {
			while (q1.size() > 1) {
				int temp = q1.front();
				q1.pop();
				q2.push(temp);
			}
			int temp2 = q1.front();
			q1.pop();
			while (!q2.empty()) {
				int temp3 = q2.front();
				q2.pop();
				q1.push(temp3);
			}
			return temp2;
		}
	}

	/** Get the top element. */
	int top() {
		if (q1.empty()) {
			q2.back();
		}
		else {
			return q1.back();
		}
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q1.empty() && q2.empty();
	}
};