//
// Created by Hwarang Go on 2017. 6. 11..
//

#include <iostream>
using namespace std;

int map[6][6];
int visit[6][6];
int maxc;
int testcase, N, M, x, y;

int dfs(int y, int x);


int main(){
    std::ios::sync_with_stdio(false);
    cin >> testcase;

    while(testcase--){
        cin >> N >> M;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> map[i][j];
                visit[i][j] = map[i][j];
            }
        }

        while(M--){
            cin >> y >> x;
            maxc=0;
            dfs(y,x);
            cout << maxc << endl;
        }

    }

    return 0;
}

int dfs(int y, int x){
    int temp = 0;
    int cnt = 1;
    visit[y][x] = 1;

    //위
    if(y != 0){
        if(visit[y-1][x] == 0){
            temp = dfs(y-1,x);
            if(cnt <= temp) cnt = temp + 1;
        }

    }

    //오른
    if(x != N-1){
        if(visit[y][x+1] == 0) {
            temp = dfs(y,x+1);
            if(cnt <= temp) cnt = temp + 1;
        }

    }

    //아래
    if(y != N-1){
        if(visit[y+1][x] == 0) {
            temp = dfs(y+1,x);
            if(cnt <= temp) cnt = temp + 1;
        }
    }

    //왼
    if(x != 0){
        if(visit[y][x-1] == 0) {
            temp = dfs(y,x-1);
            if(cnt <= temp) cnt = temp + 1;
        }
    }


    if(maxc < cnt) maxc = cnt;

    visit[y][x] = 0;
    return cnt;
}