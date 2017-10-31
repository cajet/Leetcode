class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int n = houses.size();
        int m = heaters.size();
        int minimum = 0;
        int j = 0;
        for(int i = 0 ;i< n ;i++){
            while( j < m - 1 && (abs(heaters[j] - houses[i]) >= abs(heaters[j+1] - houses[i]))) j ++;
            minimum = max(minimum, abs(heaters[j] - houses[i]));
        }
        return minimum;
	}
};