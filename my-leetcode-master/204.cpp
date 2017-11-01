/*先将 2~n 的各个数放入表中，然后在2的上面画一个圆圈，然后划去2的其他倍数；
第一个既未画圈又没有被划去的数是3，将它画圈，再划去3的其他倍数；
现在既未画圈又没有被划去的第一个数 是5，将它画圈，并划去5的其他倍数……
依次类推，一直到所有小于或等于 n 的各数都画了圈或划去为止。
这时，表中画了圈的以及未划去的那些数正好就是小于 n 的素数。*/

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> v(n, true);
        v[0] = false, v[1] = false;
        for (int i = 2; i < sqrt(n); ++i) {
            if (v[i]) {
                for (int j = i*i; j < n; j += i) { 
                    v[j] = false;
                }    
            }    
        }
        return count(v.begin(), v.end(), true);
    }
};