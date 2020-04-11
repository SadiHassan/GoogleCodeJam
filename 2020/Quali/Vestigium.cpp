#include<bits/stdc++.h>
using namespace std;

int main(){

    int T, N, val;
    cin >> T;

    for(int t = 1; t <= T; t++){
        cin >> N;
        int sum = N * (N + 1) / 2;
        int trace = 0;
        int row_mismatch = 0;
        vector< map<int, bool> > col_map(N);
        map<int, bool> col_mismatch;

        for(int i = 0; i < N; i++){
            map<int, bool> row_map;
            bool bad_row = false;

            for(int j = 0; j < N; j++){
                cin >> val;
                if(i == j)  trace += val;
                if(row_map.find(val) != row_map.end())
                    bad_row = true;

                row_map[val] = true;

                if(col_map[j].find(val) != col_map[j].end()){
                    col_mismatch[j] = true;
                }

                col_map[j][val] = true;
            }
            if(bad_row) row_mismatch++;

        }



        cout << "Case #" << t <<": " << trace << " " << row_mismatch << " " << col_mismatch.size() << endl;
    }

return 0;
}
