// WA :(
#include<bits/stdc++.h>
using namespace std;

int manhatan(int r, int c, int rr, int cc){
    return (abs(r-rr)+abs(c-cc));
}
int main(){
    int T;
    cin >> T;
    int dist_row[] = {-1,1,0};
    int dist_col[] = {-1,1,0};
    for(int t = 1; t <= T; t++){
        int R,C;
        cin >> R >> C;
        vector< vector<int> > dist(R, vector<int>(C,0));
        vector<string> arr;
        for(int r = 0; r < R; r++){
            string str;
            cin >> str;
            arr.push_back(str);
        }

        queue< pair<int,int> > q;
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++){
                if(arr[i][j]=='1'){
                    pair<int,int> p;
                    p = make_pair(i,j);
                    q.push(p);
                }
            }
        if(q.empty()){ //There is no delivery office
            int ans2;
            int rrr = (R-1)/2;
            int ccc = (C-1)/2;
            ans2 = manhatan(0,0,rrr,ccc);
            ans2 = max(ans2,manhatan(0,C-1,rrr,ccc));
            ans2 = max(ans2,manhatan(R-1,0,rrr,ccc));
            ans2 = max(ans2,manhatan(R-1,C-1,rrr,ccc));
            cout<<"Case #"<<t<<": "<<ans2<<endl;
            continue;
        }
        while(!q.empty()){
            pair<int,int> u = q.front();
            q.pop();
            int r = u.first;
            int c = u.second;
            for(int i=0; i<3; i++)
            for(int j=0; j<3; j++){
                int rr = r + dist_row[i];
                int cc = c + dist_col[j];
                if(r==rr && c==cc) continue;
                if(0<=rr && rr<R && 0<=cc && cc<C){
                    if(arr[rr][cc]!='1'){
                        int distance = manhatan(r,c,rr,cc);
                        if(dist[rr][cc]==0 || dist[rr][cc] > distance+dist[r][c]){
                            if(dist[rr][cc]==0) dist[rr][cc] = distance;
                            else dist[rr][cc] = min(dist[rr][cc]+dist[r][c], distance);
                            pair<int,int> pp;
                            pp = make_pair(rr,cc);
                            q.push(pp);
                        }
                    }
                }
            }
        }//while - Q
        int max_dist = 0;
        pair<int,int> max_p(-1,-1);
        for(int i=0;i<R;i++)
        for(int j=0; j<C; j++){
            if(dist[i][j] > max_dist && arr[i][j] != '1'){
                max_dist = dist[i][j];
                max_p.first = i;
                max_p.second = j;
            }
        }
        //cout<<max_p.first<<","<<max_p.second<<endl;
        int ans = 10000;
        if(max_p.first!=-1 && max_p.second!=-1)
        arr[max_p.first][max_p.second] = '1';
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++){
                if(arr[i][j]=='1'){
                    pair<int,int> p;
                    p = make_pair(i,j);
                    q.push(p);
                }
            }
        while(!q.empty()){
            pair<int,int> u = q.front();
            q.pop();
            int r = u.first;
            int c = u.second;
            for(int i=0; i<3; i++)
            for(int j=0; j<3; j++){
                int rr = r + dist_row[i];
                int cc = c + dist_col[j];
                if(r==rr && c==cc) continue;
                if(0<=rr && rr<R && 0<=cc && cc<C){
                    if(arr[rr][cc]!='1'){
                        int distance = manhatan(r,c,rr,cc);
                        if(dist[rr][cc]==0 || dist[rr][cc] > distance+dist[r][c]){
                            if(dist[rr][cc]==0) dist[rr][cc] = distance;
                            else dist[rr][cc] = min(dist[rr][cc]+dist[r][c], distance);
                            pair<int,int> pp;
                            pp = make_pair(rr,cc);
                            q.push(pp);
                        }
                    }
                }
            }
        }//while - Q
        max_dist = 0;
        //pair<int,int> max_p(-1,-1);
        for(int i=0;i<R;i++)
        for(int j=0; j<C; j++){
            if(dist[i][j] > max_dist && arr[i][j]!='1'){
                max_dist = dist[i][j];
                max_p.first = i;
                max_p.second = j;
            }
        }
        cout<<"Case #"<<t<<": "<<max_dist<<endl;
    }
    return 0;
}

/*

10001
00000
00000
00000
10001

*/
