#include<bits/stdc++.h>
using namespace std;
char board[9][9];
int total =0 ;
bool check(int row,int col){
   
    for(int i=row-1 ; i>= 0 ;i--)
        if(board[i][col]=='p') return false;
        
    
    
    
    for(int i=row-1 ,j=col-1 ; i>=0 and j>=0 ;i--,j--)
        if(board[i][j]=='p') return false;
      
    
    for(int i=row-1,j=col+1 ; i>= 0 and j<8;i--,j++)
        if(board[i][j]=='p') return false;
       
    return true;
}
void backtrack(int row,int col,int count){
    if(count==8) {   
    total++;   
    return ;
    }
    for(int i=row;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]!='*'&& check(i,j)){
                board[i][j]='p';
                backtrack(i+1,j,count+1);
           
                board[i][j]='.';
            }
                
        }
    }
    
}
int main(){
    char x;
    //freopen("input.txt","r",stdin);
    //memset(board,'.',sizeof(board)*8*8);
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++){
         cin>> board[i][j];
        }
   

        backtrack(0,0,0);
        cout<<total<<endl;

    return 0;
}