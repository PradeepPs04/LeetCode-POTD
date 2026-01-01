// https://leetcode.com/problems/design-spreadsheet/description/?envType=daily-question&envId=2025-09-19

class Spreadsheet {
private:
    unordered_map<string, int>mpp;

    int get(string s) {
        if(isdigit(s[0]))   return stoi(s);

        return mpp[s];
    }
public:
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        mpp[cell] = value;
    }
    
    void resetCell(string cell) {
        mpp[cell] = 0;
    }
    
    int getValue(string formula) {
        int idx = 1;
        string one = "";
        while(formula[idx] != '+')  one += formula[idx++];

        idx++;

        string two = "";
        while(idx < formula.length())  two += formula[idx++];

        return get(one) + get(two);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */