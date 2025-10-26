// https://leetcode.com/problems/simple-bank-system/?envType=daily-question&envId=2025-10-26

#define ll long long

class Bank {
private:
    vector<ll>mpp;

public:
    Bank(vector<long long>& balance) {
        mpp = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 > mpp.size() || account2 > mpp.size() || mpp[account1-1] < money)   return false;

        mpp[account1-1] -= money;
        mpp[account2-1] += money;

        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account > mpp.size())   return false;

        mpp[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account > mpp.size() || mpp[account-1] < money)   return false;

        mpp[account-1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */