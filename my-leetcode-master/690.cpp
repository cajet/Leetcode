/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
	int getImportance(vector<Employee*> employees, int id) {
		unordered_map<int, Employee*> m;
		for (auto e : employees) {
			m[e->id] = e;
		}
		return getSum(m, id);
	}
	int getSum(unordered_map<int, Employee*> & m, int id) {
		int temp = m[id]->importance;
		for (auto e : m[id]->subordinates) {
			temp+= getSum(m, e);
		}
		return temp;
	}
};