https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> a = {1};
        ans.push_back(a);
        for(int i = 2;i<=numRows;i++){
            vector<int> small;
            small.push_back(1);
            for(int j = 1;j<i-1;j++){
                int sm = ans[i - 2][j-1] + ans[i - 2][j];
                small.push_back(sm);
            }
            small.push_back(1);
            ans.push_back(small);
        }
        return ans;
    }
};
// //TUF:
// vector<vector<int>> generate(int numRows) {
//         // Result vector to hold all rows
//         vector<vector<int>> triangle;

//         // Loop for each row
//         for (int i = 0; i < numRows; i++) {
//             // Create a row with size (i+1) and initialize all elements to 1
//             vector<int> row(i + 1, 1);

//             // Fill elements from index 1 to i-1 (middle values)
//             for (int j = 1; j < i; j++) {
//                 // Each element = sum of two elements above it
//                 row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
//             }

//             // Add current row to the triangle
//             triangle.push_back(row);
//         }
//         return triangle;
//     }