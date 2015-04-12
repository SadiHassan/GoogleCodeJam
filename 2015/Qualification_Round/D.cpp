#include<iostream>
#include<cstdio>
using namespace std;

int main(){
freopen("D-small-attempt0.in","r",stdin);
freopen("out_D.txt","w",stdout);
int X, R, C, T;

cin>>T;
for(int t=1; t<=T; t++){
    cin>>X>>R>>C;
    cout<<"Case #"<<t<<": ";

    if(X>R&&X>C){
        cout<<"RICHARD"<<endl;
        continue;
    }

    if(X==1){
        cout<<"GABRIEL"<<endl;
        continue;
    }
    if(X==2){
        if(R*C==3||R*C==9) cout<<"RICHARD"<<endl;
        else cout<<"GABRIEL"<<endl;
        continue;
    }
    if(X==3){
        if(R*C==6||R*C==9||R*C==12) cout<<"GABRIEL"<<endl;
        else cout<<"RICHARD"<<endl;
        continue;
    }
    if(X==4){
        if(R*C==16||R*C==12) cout<<"GABRIEL"<<endl;
        else cout<<"RICHARD"<<endl;
        continue;
    }
}

return 0;
}
