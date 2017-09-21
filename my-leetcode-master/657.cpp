class Solution {
public:
    bool judgeCircle(string moves) {
        int updown= 0, leftright= 0;
        for(int i= 0; i< moves.length(); i++) {
            if (moves[i] == 'U') updown++;
            else if (moves[i] == 'D') updown--;
            else if (moves[i] == 'R') leftright++;
            else leftright--;
        }
        if (updown != 0 || leftright != 0) return false;
        else return true;
    }
};