// https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int maxSum = INT_MIN;
        int sum = 0;
        for(int i = 0;i< arr.size();i++){
            sum += arr[i];
            maxSum = max(maxSum, sum);
            if(sum<0){
                sum = 0;
            }
        }
        return maxSum;
    }
};