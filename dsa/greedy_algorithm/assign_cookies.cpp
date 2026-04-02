//https://leetcode.com/problems/assign-cookies/

//TIP: read question properly, think through problem
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // sort(g.begin(), g.end());
        // sort(s.begin(), s.end());
        // int i = 0;
        // int j = 0;
        // int answer = 0;
        // while(i<g.size()){
        //     if(j >= s.size()){
        //         break;
        //     }
        //     if(s[j] >= g[i]){
        //         answer++;
        //         i++;
        //         j++;
        //     }else{
        //         j++;
        //     }
        // }
        // return answer;
        
        //Clean code
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;
        int count = 0;

        while(i < g.size() && j < s.size()) {
            if(s[j] >= g[i]) {
                count++;
                i++;
            }
            j++;
        }

        return count;
    }
};