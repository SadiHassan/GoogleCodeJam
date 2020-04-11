#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > ans_arr;
int ans;

void save_answer(int sum, vector< vector<int> > arr){
    ans = sum;
    ans_arr.clear();
    for(int i = 0; i < arr.size(); i++){
        vector<int> temp;
        for(int j = 0; j < arr[i].size(); j++){
            temp.push_back(arr[i][j]);
        }
        ans_arr.push_back(temp);
    }
}

bool not_used(int i, int j, int val, vector< vector<int> >& row, vector< vector<int> >& col){
    if(row[i][val-1] == 1 || col[j][val-1] == 1) return false;
    return true;
}

int check_valid(vector< vector<int> >& arr, int N, int K){
    int sum = 0;
    for(int i = 0; i < N; i++){
        sum += arr[i][i];
    }
    if(sum != K ) return 0;
    return sum;
}

bool rec(int cur_i, int cur_j, int N, int K, vector< vector<int> >& row, vector< vector<int> >& col, vector< vector<int> >& arr){

    if(cur_i >= N){
        //cout << "validity check: " << cur_i << " --> " << cur_j << endl;
        int sum = check_valid(arr, N, K);
        /*
        cout << "validity sum: " << sum << endl;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++) cout << arr[i][j] << " "; cout << endl;
        }
        */
        if(sum == K){
            save_answer(sum, arr);
            return true;
        }
        return false;
    }

    bool res = false;

    for(int val = 1; val <= N; val++){
            if( not_used(cur_i, cur_j, val, row, col) == true){
                arr[cur_i][cur_j] = val;
                row[cur_i][val-1] = 1;
                col[cur_j][val-1] = 1;
                /*
                cout << cur_i << " -- " << cur_j << endl;
                for(int m = 0; m < N; m++){
                    for(int n = 0; n < N; n++) cout << arr[m][n] << " ";
                    cout << endl;
                }
                */
                int i, j;
                if(cur_j == N - 1) {j = 0; i = cur_i + 1;}
                else {j = cur_j + 1; i = cur_i;}

                res = rec(i, j, N, K, row, col, arr);

                if(res) return true;
                row[cur_i][val-1] = -1;
                col[cur_j][val-1] = -1;
                arr[cur_i][cur_j] = -1;
                }
    }



    return res;
}

int main(){

    int T;
    cin >> T;
    int out = 1;

/*
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

  do {
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
  } while (next_permutation(arr.begin(), arr.end()));
*/
    for(int t = 1; t <= T; t++){
        int N, K;
        cin >> N >> K;
        if(K > N * N){
            cout << "Case #" << t <<": IMPOSSIBLE" << endl;
            continue;
        }
        vector< vector<int> > arr;
        vector< vector<int> > row;
        vector< vector<int> > col;

        for(int i = 0; i < N; i++){
            vector<int> temp;
            for(int j = 0; j < N; j++)
                temp.push_back(-1);
            arr.push_back(temp);
            row.push_back(temp);
            col.push_back(temp);
        }
        /*
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++)
                cout << row[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++)
                cout << col[i][j] << " ";
            cout << endl;
        }
        */

        if(rec(0, 0, N, K, row, col, arr)){
            cout << "Case #" << t <<": POSSIBLE" << endl;
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    cout << ans_arr[i][j];
                    if(j < N - 1) cout << " ";
                    else cout << endl;
                }
            }
        }
        else
            cout << "Case #" << t <<": IMPOSSIBLE" << endl;


    }

return 0;
}
