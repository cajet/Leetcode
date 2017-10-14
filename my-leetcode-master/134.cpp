class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum_gas= 0, sum_cost= 0, max= 0, sta_index;
        //先判断是否存在解
        for (int i= 0; i< gas.size(); i++) {
            sum_gas+= gas[i];
            sum_cost+= cost[i];
        }
        if (sum_gas< sum_cost) return -1;  
        else {
            int sum= 0, res= 0;
            for (int i= 0; i<gas.size(); i++) {
                sum+= gas[i]-cost[i];
                if (sum< 0) {
                    sum= 0;
                    res= i+1;
                }
            }
            return res;
        }
    }
};