class Solution {
    public:
    vector<vector<int>> generateMatrix(int n) {
        int left=0, right=n-1, top=0, bottom=n-1;
        int val=1;

        vector<vector<int>>mat(n,vector<int>(n,0));
        while(left<=right && top<=bottom){
            // Fill every value in the top row (left to right)
            for(int c=left;c<=right;c++){
                mat[top][c]=val++;
            }
            top++;

            // Fill every value in the right column (top to bottom)
            for(int r=top;r<=bottom;r++){
                mat[r][right]=val++;
            }
            right--;

            // Fill every value in the bottom row (right to left), check boundary condition
            if(top<=bottom){
                for(int c=right;c>=left;c--){
                    mat[bottom][c]=val++;
                }
                bottom--;
            }

            // Fill every value in the left column (bottom to top), check boundary condition
            if(left<=right){
                for(int r=bottom;r>=top;r--){
                    mat[r][left]=val++;
                }
                left++;
            }
        }
        return mat;
    }
};