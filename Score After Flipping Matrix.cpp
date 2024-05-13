class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        //set first column value in each row
        for(int i = 0; i < row; i++){
            if(grid[i][0] == 0){

                //flip that row
                for(int j = 0; j < col; j++){
                    grid[i][j] = 1 - grid[i][j];    //flippping
                }
            }
        }
        for(int j = 1; j < col; j++){
            int countZero = 0;
                for(int i = 0; i < row; i++){
                    if(grid[i][j] == 0) countZero++;
                }
            int countOne = row - countZero;
                if(countZero > countOne){
                 //flip that column
                 for(int  i = 0; i < row; i++){
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
    int score = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            int value = grid[i][j]*pow(2,col-j-1);
            score += value;
        }
    }
    return score;
}
};
