class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		set<int> s;
		for (int i = 0; i < candies.size(); i++) {
			s.insert(candies[i]);
		}
		int length = s.size();
		if (length < candies.size() / 2) return length;
		else return candies.size() / 2;
	}
};