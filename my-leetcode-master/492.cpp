class Solution {
public:
	vector<int> constructRectangle(int area) {
		int temp;
		for (int i = area; i >= sqrt(area); i--) {
			if (area%i==0) temp = i;
		}
		return{temp, area/temp};
	}
};