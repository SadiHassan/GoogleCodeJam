#include<iostream>
#include<cstdio>
using namespace std;

int main(){

freopen("A-small-attempt0.in","r",stdin);
freopen("Aout.txt","w",stdout);

int T, N, total_so_far, additional_friend, val;
string str;
cin>>T;

for(int t=1; t<=T; t++){

    cin>>N>>str;
    total_so_far = str[0]-'0';
    additional_friend = 0;

    for(int shyness=1; shyness<=N; shyness++){
        val = str[shyness]-'0';
        if(total_so_far>=shyness) {
                total_so_far = total_so_far + val;
                continue;
        }
        additional_friend = additional_friend + (shyness - total_so_far) ;
        total_so_far = total_so_far + val + (shyness - total_so_far);
    }
    cout<<"Case #"<<t<<": "<<additional_friend<<endl;
}
return 0;
}
