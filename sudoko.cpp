#include<vector>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 bool safe(vector<vector<char>>&board,int i,int j,char k){
        for(int p=0;p<9;p++){
            if(board[i][p]==k)
                return false;
        }
        for(int p=0;p<9;p++){
            if(board[p][j]==k)
                return false;
        }
        int p1=i/3;
        int p2=p1*3;
        
        int q1=j/3;
        int q2=q1*3;
        
        for(int k1=0;k1<3;k1++){
            for(int k2=0;k2<3;k2++){
                if(board[p2+k1][q2+k2]==k){
                    return false;
                }        
            }
        }
        return true;
    }
    bool find(vector<vector<char>>&board){
        bool check=false,flag=false;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.')
                    continue;
                check=true;
                    for(char k='1';k<='9';k++){
                        if(safe(board,i,j,k)==true){
                            board[i][j]=k;
                           flag=find(board);
                             if(flag==true){
                           return true;
                           }   
                              board[i][j]='.';       
                        }
                               
                    }   
                if(flag==false)
                    return false;
            }           
        }
        if(check==false)
            return true;
        
            return flag;
    
    }
void solveSudoku(vector<vector<char>>& board) {
        bool t=find(board);
    }
 bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_map<char,int>mp;
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                    continue;
                if(mp.find(board[i][j])!=mp.end())
                    return false;
                else
                    mp[board[i][j]]++;
            }
        }
        
        
        for(int i=0;i<9;i++){
            unordered_map<char,int>mp;
            for(int j=0;j<9;j++){
                if(board[j][i]=='.')
                    continue;
                if(mp.find(board[j][i])!=mp.end())
                    return false;
                else
                    mp[board[j][i]]++;
            }
        }
        for(int i=0;i<9;i++){
            int x=(i/3)*3;
            int y=(i%3)*3;
             unordered_map<char,int>mp;
            for(int p=0;p<3;p++){
                
                for(int j=0;j<3;j++){
                    if(board[x+p][y+j]=='.')
                        continue;
                    if(mp.find(board[x+p][y+j])!=mp.end())
                        return false;
                    else
                        mp[board[x+p][y+j]]++;
                }
            }
        }
        return true;
    }
int main(){
    vector<vector<char>>grid(9,vector<char>(9,'.'));
    cout<<"enter your sudoko here"<<endl;
    cout<<"empty space as /./ "<<endl;
    char temp;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++){
            cin>>temp;
            grid[i][j]=temp;
        }
    }
    bool ans=isValidSudoku(grid);
    if(ans==false)
    {
        cout<<"The given sudoko is not valid"<<endl;
    }
    else
    {
       solveSudoku(grid);
       cout<<"solved sudoko is:"<<endl;
       for(int i=0;i<9;i++)
       {
           for(int j=0;j<9;j++)
           cout<<grid[i][j]<<" ";
           cout<<endl;
       }
    }
}