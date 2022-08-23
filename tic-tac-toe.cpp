#include<bits/stdc++.h>
using namespace std;
struct chance{
    int r,c,score;
};
struct TicTacToe{
    char player,computer;
    char grid[3][3];
    TicTacToe(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)
            grid[i][j]=' ';
        }
    }
    void print(){
        for(int i=0;i<3;i++){
            if(i) cout<<"--------------\n";
            for(int j=0;j<3;j++){
                if(j) cout<<"|";
                cout<<" ";
                if(grid[i][j]==' ')
                cout<<3*i+j+1;
                else cout<<grid[i][j];
                cout<<" ";  
            }
            cout<<'\n';
        }
    }
    void play(){
        while(true){
            cout<<"Which symbol (X or O)?";
            cin>>player;
            if(player=='X'||player=='O') break;
            else cout<<"That's invalid\n";
        }
        if(player=='X') computer='O';
        else computer='X';
        if(player=='O') computer_move();
        print();
        while(true){
            player_move();
            print();
            if(win()){
                cout<<"PLAYER WINS!\n";
                return ;
            }
            else if(tie()){
                cout<<"DRAW\n";return;
            }
            cout<<"Computer is making a move\n";
            computer_move();
            print();
            if(win()){
                cout<<"Computer wins\n";
                return;
            }
            else if(tie()){
                cout<<"DRAW\n";
                return;
            }
        }
    }
    void player_move(){
        while(true){
            cout<<"Enter an empty cell(1-9):";
            int cell;cin>>cell;
            int r=(cell-1)/3;
            int c=(cell-1)%3;
            if(cell>=1&&cell<=9&&grid[r][c]==' '){
                grid[r][c]=player;
                break;
            }
        }
    }
    bool win(){
        int win_states[8][3]={{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7}};
        for(int i=0;i<8;i++){
            bool win=true;
            int first_r=(win_states[i][0]-1)/3;
            int first_c=(win_states[i][0]-1)%3;
            for(int j=0;j<3;j++){
                int r=(win_states[i][j]-1)/3;
                int c=(win_states[i][j]-1)%3;
                if(grid[first_r][first_c]==' '||grid[first_r][first_c]!=grid[r][c]) 
                win=false;
            }
            if(win) return true;
        }
        return false;
    }
    bool tie(){
        if(win()) return false;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==' ') return false;
            }
        }
        return true;
    }
    void computer_move(){
        chance best_move=minimax(1);
        grid[best_move.r][best_move.c]=computer;
    }
    chance minimax(bool maximizing_player=true){
        chance best_move;
        if(win()){
            if(maximizing_player){
                best_move.score=-1;
            }
            else best_move.score=1;
            return best_move;
        }
        if(tie()){
            best_move.score=0;
            return best_move;
        }
        best_move.score=maximizing_player?-1e5:1e5;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==' '){
                    grid[i][j]=maximizing_player?computer:player;
                    chance board_state=minimax(maximizing_player^1);
                    if(maximizing_player){
                        if(board_state.score>best_move.score){
                            best_move.score=board_state.score;
                            best_move.r=i;
                            best_move.c=j;
                        }
                    }
                    else{
                        if(board_state.score<best_move.score){
                            best_move.score=board_state.score;
                            best_move.r=i;
                            best_move.c=j;
                        }
                    }
                    grid[i][j]=' ';
                }
            }
        }
        return best_move;
    }
};

int main(){
    TicTacToe game;
    game.play();
    return 0;
}