class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //https://leetcode.com/problems/set-matrix-zeroes/
        // check if 0,0 -> 0.
        // check if any 0 row element is 0
        // check if any 0 column element is 0
        // if i,j -> then set matrix[i][0] = 0 and matrix[0][j] = 0
        // basically using 0th row and column as hash map
        // then, lastly, set 0th row or 0th column or both as 0 
        // based on checks done at the beginning
        bool set0r0c = false;
        bool set0r = false;
        bool set0c = false;
        if(matrix[0][0]==0)
            set0r0c = true;
        for(int i = 0; i < matrix[0].size(); i++)
            if(matrix[0][i] == 0)
            {
                set0r = true;
                break;
            }
        for(int i = 0; i < matrix.size(); i++)
            if(matrix[i][0] == 0)
            {
                set0c = true;
                break;
            }
        for(int i = 1; i < matrix.size(); i++)
            for(int j = 1;j < matrix[i].size(); j++)
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        for(int i = 1; i < matrix.size(); i++)
            if(matrix[i][0] == 0){
                 for(int j = 1;j < matrix[i].size(); j++)
                 {
                     matrix[i][j] = 0;
                 }
            }
        for(int j = 1;j < matrix[0].size(); j++)
            if(matrix[0][j] == 0){
                 for(int i = 1;i < matrix.size(); i++)
                 {
                     matrix[i][j] = 0;
                 }
        }
        if(set0r0c)
        {
            for(int i = 0; i < matrix.size(); i++)
                matrix[i][0] =0;
            for(int j = 0; j < matrix[0].size(); j++)
                matrix[0][j] = 0;
        }
        if(set0r)
        {
            for(int i = 0; i < matrix[0].size(); i++)
                matrix[0][i] =0;
        }
        if(set0c){
            for(int j = 0; j < matrix.size(); j++)
                matrix[j][0] = 0;
        }
        
    }
};
