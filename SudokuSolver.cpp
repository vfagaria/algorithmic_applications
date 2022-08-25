#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
bool isvalid(int row, int col, char x,vector<vector<char>> &A)
{
    for(int i=0; i<9; i++)
    {
        if(A[i][col]==x)
        return false;
    }
    for(int i=0; i<9; i++)
    {
    if(A[row][i]==x)
    return false;
    }
    int p=row/3;
    int q=col/3;
    int a=p*3;
    int b=q*3;
    for(int i=a; i<a+3; i++)
    {
     for(int j=b; j<b+3; j++)
    {
        if(A[i][j]==x)
        return false;
    }
   
    }
     return true;
}
bool solve(vector<vector<char> > &A)
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(A[i][j]=='.')
            {
            for(char k='1'; k<='9'; k++)
            {
                if(isvalid(i, j, k, A))
                {
                  A[i][j]=k;
                 if(solve(A))
                 return true;
                  A[i][j]='.';
                }
            }
            return false;
            }
        }
    }
    return true;
}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
int main()
{
    vector<vector<char>>board(9,vector<char>(9,'.'));
    Solution nightking;
    nightking.solveSudoku(board);
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cout<<board[i][j];
            if(j!=9)
            cout<<" | ";
        }
        cout<<'\n';
        for(int j=0; j<33; j++)
        cout<<'-';
        cout<<'\n';
    }

}
