#include<iostream>
#include<stdio.h>
using namespace std;

int T, N;
int board[22][22];

void left_move(){

}

void right_move(){

}

void up_move(){

}

void down_move(){

}

int main(){

string dir;

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
