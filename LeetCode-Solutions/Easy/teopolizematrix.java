class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        int row = matrix.length , col =matrix[0].length ; 
        for(int i = 1 ; i < row ; i++){
            for(int j = 1 ; j < col ; j++){
                if(matrix[i - 1][j -1]!= matrix[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
}
