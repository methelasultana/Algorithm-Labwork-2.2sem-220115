#include<iostream>
using namespace std;
#define N 8
void printsol(int board[N][N]){
for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
      cout<<(board[i][j]?"Q":".");
      cout<<endl;
    }
    cout<<endl;

}
bool issafe(int board[N][N],int row,int col)
{
    for(int i=0;i<col;i++)
        if(board[row][i])return false;//check lest side
    for(int i=row, j=col;i>=0&&j>=0;i--,j--)//check upper diagonal
if(board[i][j])return false;
for(int i=row, j=col;i<N&&j>=0;i++,j--)//check lower diagonal
if(board[i][j])return false;
return  true;}

bool solveQueen(int board[N][N],int col)
{
    if(col>=N)return true;//place all queens
    for(int i=0;i<N;i++){
        if(issafe(board,i,col)){
           board[i][col]=1;
    if(solveQueen(board,col+1))return true;
    board[i][col]=0;//backtract
}}
return false;}
void solve()
{
    int board[N][N]={0};
    if(solveQueen(board,0))
        printsol(board);
        else
            cout<<"no sol exists\n";
}
int main()
{
    solve();
    return 0;
}