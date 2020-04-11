#include<bits/stdc++.h>
using namespace std;

struct duration{
    int start;
    int finish;
    int ind;
};

bool comp(duration a, duration b){
    if(a.start == b.start)
        return a.finish <= b.finish;
    return a.start < b.start;
}

int main(){

    int T;
    cin >> T;
    vector<duration> arr;
    string out;

    for(int t = 1; t <= T; t++){
        int N;
        cin >> N;

        out = "";
        arr.clear();

        for(int i = 0; i < N; i++){
            int start, finish;
            cin >> start >> finish;
            duration ob;
            ob.start = start;
            ob.finish = finish;
            ob.ind = i;
            arr.push_back(ob);
            out += '.';
        }

        sort(arr.begin(), arr.end(), comp);
        int C = -1, J = -1;

        for(int i = 0; i < N; i++){
            duration ob = arr[i];
            int ind = ob.ind;

            if(ob.start >= C){
                out[ind] = 'C';
                C = ob.finish;
            }
            else if(ob.start >= J){
                out[ind] = 'J';
                J = ob.finish;
            }
            else{
                out = "IMPOSSIBLE";
                break;
            }
        }

        cout << "Case #" << t <<": " << out << endl;
    }

return 0;
}
