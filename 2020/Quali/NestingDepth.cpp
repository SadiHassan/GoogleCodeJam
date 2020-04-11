#include<bits/stdc++.h>
using namespace std;

int main(){

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){
        string s;
        string out = "";
        cin >> s;
        int left = 0;

        for(int i = 0; i < s.size(); i++){
            int val = s[i] - 48;
            if(val == left) out += s[i];
            else if(val > left){
                int total = val - left;
                int temp = total;
                while(total > 0){
                    out += "(";
                    total -= 1;
                }
                out += s[i];
                left += temp;
            }
            else{
                int total = left - val;
                int temp = total;

                while(total > 0){
                    out += ")";
                    total -= 1;
                }
                out += s[i];
                left -= temp;
            }

        }

        while(left > 0){
            out += ")";
            left -= 1;
        }
        cout << "Case #" << t <<": " << out << endl;
    }

return 0;
}
