class Solution {
public:
	int countBinarySubstrings(string s) {
	    vector<int> rec;
        int count = 1;
        for(int i=1; i<= s.size(); ++i){
            if(s[i] == s[i-1]){
                count++;
            } else {
                rec.push_back(count);
                count = 1;
            }
        }
        int res = 0;
        for(int i=1; i< rec.size(); ++i){
            res += min(rec[i-1], rec[i]);
        }
        return res;
    }
};