class Solution {
public:
    static int cmp(pair<int,int> &p1, pair<int,int> &p2) {
        return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
    }
    
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(),cmp);
        vector<pair<int,int>> sol;
        for (int i = 0; i< people.size(); i++) {
            sol.insert(sol.begin() + people[i].second, people[i]);
        }
        return sol;
    }
};