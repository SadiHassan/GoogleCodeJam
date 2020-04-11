// WA :(
#include<bits/stdc++.h>
using namespace std;


int main(){
    int T, N, S;
    cin >> T;

    for(int t = 1; t <= T; t++){
        cin >> N >> S;
        map< int, vector<int> > m;
        for(int n = 1; n <= N; n++){
            int total_skills;
            cin >> total_skills;
            for(int i = 1; i <= total_skills; i++){
                int skill;
                cin >> skill;
                if(m.find(skill) == m.end()){
                    vector<int> temp;
                    temp.push_back(n);
                    m[skill] = temp;
                }
                else m[skill].push_back(n);
            }
        }

        map< int, vector<int> >::iterator it;

        for ( it = m.begin(); it != m.end(); it++ )
        {
            sort(it->second.begin(), it->second.end());
            cout << it->first << " ==> " ;
            for(int i = 0; i < it->second.size(); i++) cout << it->second[i] << " ";
            cout << endl;
        }

        for ( it = m.begin(); it != m.end(); it++ ){

        }

    }

    return 0;
}

/*
1
4 100
4 80 90 100 5
1 90
1 80
3 80 90 100

*/
