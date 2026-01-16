// https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/?envType=daily-question&envId=2026-01-16

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        // insert horizontal borders
        hFences.push_back(1);
        hFences.push_back(m);

        // insert vertical borders
        vFences.push_back(1);
        vFences.push_back(n);

        // sort both fences
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        // get differences between all horizontal fences
        unordered_set<int>st;
        for(int i = 0; i < hFences.size(); i++) {
            for(int j = i+1; j < hFences.size(); j++) {
                int diff = hFences[j] - hFences[i];
                st.insert(diff);
            }
        }

        // get differences between all vertical fences
        // if same difference was present between any horizontal fences
        //      then those fences will form a square
        // if no same difference is found then we can't form a square
        int maxSide = -1;
        for(int i = 0; i < vFences.size(); i++) {
            for(int j = i+1; j < vFences.size(); j++) {
                int diff = vFences[j] - vFences[i];
                if(st.count(diff))  maxSide = max(maxSide, diff);
            }
        }

        if(maxSide == -1)   return -1;

        int modd = 1e9 + 7;
        long long area = ((long long)(maxSide % modd) * (long long)(maxSide % modd)) % modd;

        return (int) area;
    }   
};