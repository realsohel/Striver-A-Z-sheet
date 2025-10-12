#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:

    bool wordSerch(int i,int j, vector<vector<char>>& board, string word, int idx){
        // Base Case
        if(idx==word.length())
            return true;
        
        if((i<0 or j<0) or (i>=board.size() or j>=board[0].size()) or board[i][j]=='$')
            return false;

        if(board[i][j]!=word[idx])
            return false;

        // Do
        char temp = board[i][j];
        board[i][j]='$';
        
        // Explore
        if(wordSerch(i+1,j,board,word,idx+1))
            return true;
        if(wordSerch(i-1,j,board,word,idx+1))
            return true;
        if(wordSerch(i,j+1,board,word,idx+1))
            return true;
        if(wordSerch(i,j-1,board,word,idx+1))
            return true;
        
        // Undo
        board[i][j]=temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++){
            
            for(int j=0;j<board[0].size();j++){
                
                if(board[i][j]==word[0] and wordSerch(i,j,board,word,0))
                    return true;
            }
        }

        return false;
    }
};