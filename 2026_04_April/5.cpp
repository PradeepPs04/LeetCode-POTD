// https://leetcode.com/problems/robot-return-to-origin/description/?envType=daily-question&envId=2026-04-05

class Solution {
public:
    bool judgeCircle(string moves) {
        int horizontal = 0;
        int vertical = 0;

        for(auto it:moves) {
            if(it == 'L')   horizontal--;
            else if(it == 'R')  horizontal++;
            else if(it == 'U')  vertical++;
            else    vertical--; 
        }

        return (horizontal == 0 && vertical == 0);
    }
};
