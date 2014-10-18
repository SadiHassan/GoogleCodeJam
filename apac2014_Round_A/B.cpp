#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int T, N;
int board[22][22];
bool merged[22][22];

void print_board(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)  cout<<board[i][j]<<" ";
        cout<<endl;
    }
}

void left_move(){

    int k, tmp;
    memset(merged,false,sizeof(merged));

    for(int i=0; i<N; i++){

        for(int j=0; j<N; j++){

            if(board[i][j]!=0){
                k = j;
                while(k>0){
                    if(board[i][k-1]==0){
                        board[i][k-1] = board[i][k];
                        board[i][k] = 0;
                        if(merged[i][k]==true) merged[i][k-1]=true;
                    }
                    else if(merged[i][k-1]==true) break;
                    else if (board[i][k]!=board[i][k-1]) break;
                    else if (!merged[i][k]&&!merged[i][k-1]){
                            board[i][k-1] = board[i][k-1]*2;
                            board[i][k] = 0;
                            merged[i][k-1] = true;

                    }

                    k--;
                }
            }
        }

}

print_board();
}

void right_move(){

    int k, tmp;
    memset(merged,false,sizeof(merged));

    for(int i=0; i<N; i++){

        for(int j=N-1; j>=0; j--){

            if(board[i][j]!=0){
                k = j;

                while(k<N-1){
                    if(board[i][k+1]==0){
                        board[i][k+1] = board[i][k];
                        board[i][k] = 0;
                        if(merged[i][k]==true) merged[i][k+1]=true;
                    }
                    else if(merged[i][k+1]==true) break;
                    else if (board[i][k]!=board[i][k+1]) break;
                    else if (!merged[i][k]&&!merged[i][k+1]){
                            board[i][k+1] = board[i][k+1]*2;
                            board[i][k] = 0;
                            merged[i][k+1] = true;
                    }

                    k++;
                }
            }
        }

}

print_board();

}

void up_move(){

int k, tmp;
    memset(merged,false,sizeof(merged));

    for(int j=0; j<N; j++){

        for(int i=0; i<N; i++){

            if(board[i][j]!=0){
                k = i;
                while(k>0){
                    if(board[k-1][j]==0){
                        board[k-1][j] = board[k][j];
                        board[k][j] = 0;
                        if(merged[k][j]==true) merged[k-1][j]=true;
                    }
                    else if(merged[k-1][j]==true) break;
                    else if (board[k][j]!=board[k-1][j]) break;
                    else if (!merged[k][j]&&!merged[k-1][j]){
                            board[k-1][j] = board[k-1][j]*2;
                            board[k][j] = 0;
                            merged[k-1][j] = true;

                    }

                    k--;
                }
            }
        }

}
print_board();
}

void down_move(){

int k, tmp;

memset(merged,false,sizeof(merged));

    for(int j=0; j<N; j++){

        for(int i=N-1; i>=0; i--){

            if(board[i][j]!=0){
                k = i;

                while(k<N-1){
                    if(board[k+1][j]==0){
                        board[k+1][j] = board[k][j];
                        board[k][j] = 0;
                        if(merged[k][j]==true) merged[k+1][j]=true;
                    }
                    else if(merged[k+1][j]==true) break;
                    else if (board[k][j]!=board[k+1][j]) break;
                    else if (!merged[k][j]&&!merged[k+1][j]){
                            board[k+1][j] = board[k+1][j]*2;
                            board[k][j] = 0;
                            merged[k+1][j] = true;
                    }

                    k++;
                }
            }
        }

}

print_board();
}

int main(){

string dir;
//freopen("B-large-practice.in","r",stdin);
//freopen("out.txt","w",stdout);
cin>>T;

for(int t=1; t<=T; t++){
    cin>>N>>dir;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        cin>>board[i][j];

    cout<<"Case #"<<t<<":"<<endl;
    if(dir=="left") left_move();
    else if(dir=="right") right_move();
    else if(dir=="up") up_move();
    else if(dir=="down") down_move();
}

return 0;
}
