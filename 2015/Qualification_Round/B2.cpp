#include<iostream>
#include<cstdio>
#define LI long int
using namespace std;

LI _max(LI a, LI b){ return ( a>=b ? a : b ); }
LI _min(LI a, LI b){ return ( a<=b ? a : b ); }

int main(){

//freopen("B-large.in","r",stdin);
//freopen("out.txt","w",stdout);

LI T, P[1010], D, max_height, ans, val, tot;

cin>>T;
for(int t=1; t<=T; t++){
    max_height = -1;

    cin>>D;
    for(int i=0; i<D; i++){
        cin>>P[i];
        max_height = _max(max_height,P[i]);
    }
    ans = max_height;
    for(int height=max_height; height>=1; height--){

            tot = 0;

            for(int i=0; i<D; i++){

                if(P[i]>height){
                    if(P[i]%height==0) tot = tot + (P[i]/height)-1;
                    else tot = tot + (P[i]/height);
                }
            }

        ans = _min( ans , (height+tot) );
    }

    cout<<"Case #"<<t<<": "<<ans<<endl;
}

return 0;
}
