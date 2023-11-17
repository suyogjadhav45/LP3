#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>>ans;


// bool safe(int row,int col,vector<string>&b){
//     int r=row,c=col;

//     while(r>=0 && c>=0){
//         if(b[r][c]=='Q') return false;
//         r--;
//         c--;
//     }

//     r=row;
//     c=col;

//     while(c>=0){
//         if(b[r][c]=='Q') return false;
//         c--;
//     }

//     r=row;
//     c=col;

//     while(c>=0 && r<b.size()){
//         if(b[r][c]=='Q') return false;
//         c--;
//         r++;
//     }
//     return true;
// }


// void fun(int col,vector<string>&b){
//     if(col==b.size()){
//         ans.push_back(b);
//         return;
//     }
//     for(int i=0;i<b.size();i++){
//         if(safe(i,col,b)){
//             b[i][col]='Q';
//             fun(col+1,b);
//             b[i][col]='.';
//         }
//     }
// }













bool isSafe(vector<string> &board, int row, int col)
{
    int duplicateRow = row;
    int duplicateCol = col;


    // upper left diagonal
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    row = duplicateRow;
    col = duplicateCol;

    // left horizontal
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    col = duplicateCol;

    // lower left diagonal
    while (row < board.size() && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true;
};

void solve(vector<vector<string>> &ans, vector<string> &board, int n, int col)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 'Q';
            solve(ans, board, n, col + 1);
            board[row][col] = '.';
        }
    }
}

void printBoard(vector<string> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout<<"["<<board[i][j]<<"]";
        }
        cout << endl;
    }
    cout << endl;
}


int main(){

    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    // vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    // //  .....
    // //  .....
    // //  .....
    // //  .....
    // //  .....
    solve(ans, board, n, 0);
    // fun(0,board);
    cout << "Total number of solutions: " << ans.size() << endl;
    cout<<"Solutions ---> : \n";
    for (int i = 0; i < ans.size(); i++)
    {
        printBoard(ans[i]);
        cout<<"\n------------------\n";
    }


    return 0;
}

// O(n!) time complexity
// O(n^2) space complexity for board and ans array