#include<bits/stdc++.h>
using namespace std;

int main(){

    int T, N, P;

    cin >> T;
    for(int t = 1; t <= T; t++){

            cin >> N >> P;
            vector<int> arr(N); //SADI: CheatSheet Notes

            for(int i = 0; i < N; i++){
                cin >> arr[i];
            }

            sort(arr.begin() , arr.end());

            int ans = INT_MAX; //SADI: CheatSheet Notes --> what is the header to use INT_MAX???
            int sum = 0;
            int max_level = arr[P - 1];
            for(int i = 0; i < P; i++)
                sum += (max_level - arr[i]);

            ans = min(ans, sum);
            int i = 1;
            int j = P;
            while( j < N ){
                sum = sum - (max_level - arr[i - 1]);
                sum = sum + (P - 1) * (arr[j] - arr[j - 1]);
                ans = min(ans , sum);
                max_level = arr[j];
                j++;
                i++;
            }

            cout << "Case #" << t <<": " << ans << endl;
    }
return 0;
}
