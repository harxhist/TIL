//https://leetcode.com/problems/merge-intervals/
class Solution {
public:

    static bool comp(vector<int> a, vector<int>  b){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), comp);
        int last = intervals[0][1];
        int start= intervals[0][0];
        for(int i = 1; i < intervals.size(); i++){
            int s = intervals[i][0];
            int e = intervals[i][1];
            if( s <=last){
                last = max(e, last);
            }else{
                ans.push_back({start, last});
                last  = e;
                start = s;
            }
        }
        ans.push_back({start, last});
        return ans;
    }
};