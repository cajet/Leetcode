class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		for (int i = 0; i < flowerbed.size() && n> 0; i++) {
			if (flowerbed[i] == 0 && flowerbed[i - 1] != 1) {
                if ((i+1 < flowerbed.size() && flowerbed[i + 1] != 1)|| (i+1 == flowerbed.size()) ) {
                    flowerbed[i] = 1;
				    n--;   
                }
			}
		}
		if (n > 0) return false;
		else return true;
	}
};