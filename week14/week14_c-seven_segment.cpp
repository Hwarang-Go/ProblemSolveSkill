//
// Created by Hwarang Go on 2017. 6. 4..
//

#include <iostream>
#include <vector>
using namespace std;

int testcase, L, k; // testcast, m의 자릿수, m, 변할 k개

// 0~9 segment
const int segmentArr[10][7] = {{1, 1, 1, 1, 1, 1, 0},
                              {0, 1, 1, 0, 0, 0, 0},
                              {1, 1, 0, 1, 1, 0, 1},
                              {1, 1, 1, 1, 0, 0, 1},
                              {0, 1, 1, 0, 0, 1, 1},
                              {1, 0, 1, 1, 0, 1, 1},
                              {1, 0, 1, 1, 1, 1, 1},
                              {1, 1, 1, 0, 0, 0, 0},
                              {1, 1, 1, 1, 1, 1, 1},
                              {1, 1, 1, 1, 0, 1, 1} };

int changeCount[10][11];

bool game(int *num, int current, int k);

int main(){
    std::ios::sync_with_stdio(false);

    for (int i = 0; i < 10; ++i) {
        int max = 0;
        for (int j = 0; j < 10; ++j) {

            int count = 0;

            for (int m = 0; m < 7; ++m) {
                if (segmentArr[i][m] != segmentArr[j][m]) ++count;
            }

            changeCount[i][j] = count;

            if (max < count) max = count;
        }
        changeCount[i][10] = max;
    }



    string m;
    cin >> testcase;

    while(testcase--){
        cin >> L >> m >> k;
        int *num = new int[L];
        for(int i=0;i<L;i++){
            num[i] = (int)m[i] - 48;
        }
        game(num, 0, k);
        for(int i=0;i<L;i++){
            cout << num[i];
        }
        cout << endl;
        delete[] num;
    }

    return 0;
}


bool game(int *num, int current, int k){
    if(k==0) return true;
    if(current >= L) return false;

    int from = num[current];

    for(int i = 9; i >= 0; i--){

        if(k-changeCount[from][i] >= 0){
            num[current] = i;
            if(game(num,current+1,k-changeCount[from][i])) return true;
            num[current] = from;
        }
    }
    return false;
}