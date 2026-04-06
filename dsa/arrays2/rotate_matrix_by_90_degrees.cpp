// https://leetcode.com/problems/rotate-image/
class Solution {
public:

    void reverse(vector<vector<int>>& matrix, int n){
        for(int i = 0;i<n;i++){
            for(int j = 0, k = n- 1;j<k;j++,k--){
                int x = matrix[i][j];
                matrix[i][j] = matrix[i][k];
                matrix[i][k] = x;
            }
        }
    }

    void transpose(vector<vector<int>>& matrix, int n){
        for(int i = 0; i < n ;i++){
            for(int j = 0; j < n-i;j++){
                int y = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][n-i-1];
                matrix[n-j-1][n-i-1] = y;
            }
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        reverse(matrix, n);
        transpose(matrix, n);
    }

    //TUF Solution:
    // void rotateClockwise(vector<vector<int>>& matrix) {
    //     int n = matrix.size();

    //     // Step 1: Transpose the matrix
    //     for (int i = 0; i < n; ++i) {
    //         for (int j = i + 1; j < n; ++j) {
    //             // Swap element at (i, j) with (j, i) to transpose
    //             swap(matrix[i][j], matrix[j][i]);
    //         }
    //     }

    //     // Step 2: Reverse each row
    //     for (int i = 0; i < n; ++i) {
    //         // Reverse the current row to complete clockwise rotation
    //         reverse(matrix[i].begin(), matrix[i].end());
    //     }
    // }
};