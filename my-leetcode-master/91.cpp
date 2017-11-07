class Solution {
public:
    bool isValid(char pre,char cur){
        if(pre == '1' || (pre == '2' && cur <= '6')) return true;
        else return false;
    }
    
    bool isValid(char cur){   //判断是否为0
        if(cur >= '1' && cur <= '9') return true;
        else return false;
    }
    int numDecodings(string s) {
        int size = s.size();
        if(s[0] == '0') return 0;
        if(size == 0 || size == 1) return size;
        int pre = 1,cur = 1,res;
        for(int i = 1; i < size; ++i) {
            if(isValid(s[i-1],s[i]) && isValid(s[i])){  //第二种情况
                res = pre + cur;
            }
            else if(!isValid(s[i-1],s[i]) && isValid(s[i])){  //第三种情况
                res = cur;
            }
            else if(isValid(s[i-1],s[i]) && !isValid(s[i])){  //第一种情况
                res = pre;
            }
            else{
                return 0;
            }
            pre = cur;
            cur = res;
        }
        return res;
    }
};