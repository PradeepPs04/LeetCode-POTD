// https://leetcode.com/problems/compare-version-numbers/description/?envType=daily-question&envId=2025-09-23

class Solution {
private:
    string getNum(string& s, int& idx) {
        string temp = "";
        while(idx < s.length() && s[idx] != '.') {
            temp += s[idx];
            idx++;
        }

        if(temp.length() == 0)  temp = "0";

        return temp;
    }
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while(i < version1.length() || j < version2.length()) {
            // get next number
            string s1 = getNum(version1, i);
            string s2 = getNum(version2, j); 

            // convert string to integer
            int num1 = stoi(s1);
            int num2 = stoi(s2);

            // compare
            if(num1 > num2) return 1;
            if(num1 < num2) return -1;

            // increament index
            if(i < version1.length())   i++;
            if(j < version2.length())   j++;
        }

        // both equal
        return 0;
    }
};