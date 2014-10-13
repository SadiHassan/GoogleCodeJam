#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int T, N, t, tot;
string arr[303];

void dfs(int i, int j){

    arr[i][j]='.';

                if(i-1>=0){
                        if(arr[i-1][j]=='#') dfs(i-1,j);
                }

                if(i+1<=N-1){
                        if(arr[i+1][j]=='#') dfs(i+1,j);
                }

                if(j-1>=0){
                        if(arr[i][j-1]=='#') dfs(i,j-1);
                }

                if(j+1<=arr[i].size()-1){
                        if(arr[i][j+1]=='#') dfs(i,j+1);
                }

                if(i-1>=0&&j-1>=0){
                        if(arr[i-1][j-1]=='#') dfs(i-1,j-1);
                }

                if(i-1>=0&&j+1<=arr[i].size()-1){
                        if(arr[i-1][j+1]=='#') dfs(i-1,j+1);
                }

                if(i+1<=N-1&&j-1>=0){
                        if(arr[i+1][j-1]=='#') dfs(i+1,j-1);
                }

                if(i+1<=N-1&&j+1<=arr[i].size()-1){
                        if(arr[i+1][j+1]=='#') dfs(i+1,j+1);
                }
return;
}


int main(){


//freopen("A-large.in","r",stdin);
//freopen("A.out","w",stdout);

cin>>T;

for(t=1;t<=T;t++){
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];

    //////////////////////////////////////////////////

        for(int i=0; i<N; i++){
        for(int j=0; j<arr[i].size();j++){

                if(arr[i][j]=='*') continue;

                tot=0;

                if(i-1>=0){
                        if(arr[i-1][j]=='*') tot++;
                }

                if(i+1<=N-1){
                        if(arr[i+1][j]=='*') tot++;
                }

                if(j-1>=0){
                        if(arr[i][j-1]=='*') tot++;
                }

                if(j+1<=arr[i].size()-1){
                        if(arr[i][j+1]=='*') tot++;
                }

                if(i-1>=0&&j-1>=0){
                        if(arr[i-1][j-1]=='*') tot++;
                }

                if(i-1>=0&&j+1<=arr[i].size()-1){
                        if(arr[i-1][j+1]=='*') tot++;
                }

                if(i+1<=N-1&&j-1>=0){
                        if(arr[i+1][j-1]=='*') tot++;
                }

                if(i+1<=N-1&&j+1<=arr[i].size()-1){
                        if(arr[i+1][j+1]=='*') tot++;
                }


               arr[i][j] = 48+tot;



        }
    }

    //cout<<"_____________________________________________________"<<endl<<endl;
    //for(int i=0; i<N; i++) cout<<arr[i]<<endl;
    //cout<<"_____________________________________________________"<<endl<<endl;
    ///////////////////////////////////////////////////


    int ans=0;
    bool hash_found;
    for(int i=0; i<N; i++){

        for(int j=0; j<arr[i].size();j++){

                if(arr[i][j]=='*') continue;
                if(arr[i][j]=='0') {
                    arr[i][j]='#';
                    continue;
                }
                hash_found=false;

                if(i-1>=0){
                        if(arr[i-1][j]=='#'||arr[i-1][j]=='0') hash_found=true;
                }

                if(i+1<=N-1){
                        if(arr[i+1][j]=='#'||arr[i+1][j]=='0') hash_found=true;
                }

                if(j-1>=0){
                        if(arr[i][j-1]=='#'||arr[i][j-1]=='0') hash_found=true;
                }

                if(j+1<=arr[i].size()-1){
                        if(arr[i][j+1]=='#'||arr[i][j+1]=='0') hash_found=true;
                }

                if(i-1>=0&&j-1>=0){
                        if(arr[i-1][j-1]=='#'||arr[i-1][j-1]=='0') hash_found=true;
                }

                if(i-1>=0&&j+1<=arr[i].size()-1){
                        if(arr[i-1][j+1]=='#'||arr[i-1][j+1]=='0') hash_found=true;
                }

                if(i+1<=N-1&&j-1>=0){
                        if(arr[i+1][j-1]=='#'||arr[i+1][j-1]=='0') hash_found=true;
                }

                if(i+1<=N-1&&j+1<=arr[i].size()-1){
                        if(arr[i+1][j+1]=='#'||arr[i+1][j+1]=='0') hash_found=true;
                }


                if(hash_found==false) ans++;

                if(arr[i][j]=='0')   arr[i][j]='#';

                //cout<<i<<" "<<j<<" : "<<arr[i][j]<<"---> "<<ans<<endl;

          }

          //cout<<arr[i]<<endl;
    }

    for(int i=0; i<N; i++)
        for(int j=0; j<arr[i].size();j++){
            if(arr[i][j]=='#'){
                ans++;
                dfs(i,j);
            }
        }


    cout<<"Case #"<<t<<": "<<ans<<endl;
}


return 0;
}
