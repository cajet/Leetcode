#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > tri;
        vector<int> n1;
        n1.push_back(1);

        vector<int> n2;
        n2.push_back(1);
        n2.push_back(1);

        tri.push_back(n1);
        tri.push_back(n2);

        tri.resize(numRows);
        for (int i = 2; i < numRows; i++) {
          tri[i].push_back(1);
          for (int j = 0; j < int(tri[i-1].size())-1; j++)
            tri[i].push_back(tri[i-1][j] + tri[i-1][j+1]);
          tri[i].push_back(1);
        }

        return tri;
    }
};


int main() {
  int n;
  Solution s;
  while (cin >> n) {
    vector<vector<int> >  tri = s.generate(n);
    for (int i = 0; i < tri.size(); i++) {
      for (int j = 0; j < tri[i].size(); j++)
        cout << tri[i][j] << ", ";
      cout << endl;
    }
  }

}