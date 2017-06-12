//
// Created by Hwarang Go on 2017. 6. 12..
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>
using namespace std;

bool cmp180(pair<int, int> a, pair<int, int> b){return a.second > b.second;}
bool cmp360(pair<int, int> a, pair<int, int> b){return a.second < b.second;}

int main(){
    std::ios::sync_with_stdio(false);
    int testcase, wind, island;
    cin >> testcase;

    while(testcase--){
        vector<pair <int, int> > vIsland;
        int x, y;
        cin >> wind >> island;
        for(int i=0; i<island; i++){
            cin >> x >> y;
            vIsland.push_back(make_pair(x,y));
        }
        int cntX, cntPrev, result=0;
        int cnt=0;
        int prev;
        int *arr;
        switch(wind){
            case 45:    // 북동
                sort(vIsland.begin(),vIsland.end(),cmp360);
                prev = vIsland[0].second;
                vIsland[0].second=0;
                for(int i=1;i<=vIsland.size();i++){
                    if(prev == vIsland[i].second){
                        vIsland[i].second = cnt;
                    }else{
                        prev = vIsland[i].second;
                        cnt++;
                        vIsland[i].second = cnt;
                    }
                }
                sort(vIsland.begin(),vIsland.end());
                arr = new int[cnt+1];
                memset(arr,0,(cnt+1)*sizeof(int));
                for(auto tIsland : vIsland){
                    for(int i=0;i<=tIsland.second;i++){
                        result += arr[i];
                    }
                    arr[tIsland.second]++;
                }
                cout << result << endl;
                delete[] arr;
                break;

            case 90:    // 동
                sort(vIsland.begin(),vIsland.end());
                cntX=1;
                cntPrev=0;
                result=0;
                prev = vIsland[0].first;
                for(int i=1; i<= vIsland.size();i++){
                    if(prev == vIsland[i].first && i!=vIsland.size()){
                        cntX++;
                        continue;
                    }else{
                        prev = vIsland[i].first;
                        result += cntX*(cntPrev + (cntX-1));
                        cntPrev += cntX;
                        cntX = 1;
                    }
                }
                cout << result << endl;
                break;

            case 135:   // 남동
                sort(vIsland.begin(),vIsland.end(),cmp180);
                prev = vIsland[0].second;
                vIsland[0].second=0;
                for(int i=1;i<=vIsland.size();i++){
                    if(prev == vIsland[i].second){
                        vIsland[i].second = cnt;
                    }else{
                        prev = vIsland[i].second;
                        cnt++;
                        vIsland[i].second = cnt;
                    }
                }
                sort(vIsland.begin(),vIsland.end());
                arr = new int[cnt+1];
                memset(arr,0,(cnt+1)*sizeof(int));
                for(auto tIsland : vIsland){
                    for(int i=0;i<=tIsland.second;i++){
                        result += arr[i];
                    }
                    arr[tIsland.second]++;
                }
                cout << result << endl;
                delete[] arr;
                break;

            case 180:   // 남
                sort(vIsland.begin(),vIsland.end(), cmp180);
                cntX=1;
                cntPrev=0;
                result=0;
                prev = vIsland[0].second;
                for(int i=1; i<=vIsland.size();i++){
                    if(prev == vIsland[i].second && i!=vIsland.size()){
                        cntX++;
                        continue;
                    }else{
                        prev = vIsland[i].second;
                        result += cntX*(cntPrev + (cntX-1));
                        cntPrev += cntX;
                        cntX = 1;
                    }
                }
                cout << result << endl;
                break;

            case 225:   // 남서
                sort(vIsland.begin(),vIsland.end(),cmp360);
                prev = vIsland[0].second;
                vIsland[0].second=0;
                for(int i=1;i<=vIsland.size();i++){
                    if(prev == vIsland[i].second){
                        vIsland[i].second = cnt;
                    }else{
                        prev = vIsland[i].second;
                        cnt++;
                        vIsland[i].second = cnt;
                    }
                }
                sort(vIsland.begin(),vIsland.end(),greater<pair<int,int> >());
                arr = new int[cnt+1];
                memset(arr,0,(cnt+1)*sizeof(int));
                for(auto tIsland : vIsland){
                    for(int i=tIsland.second;i<=cnt;i++){
                        result += arr[i];
                    }
                    arr[tIsland.second]++;
                }
                cout << result << endl;
                delete[] arr;
                break;

            case 270:   // 서
                sort(vIsland.begin(),vIsland.end(), greater<pair<int,int> >());
                cntX=1;
                cntPrev=0;
                result=0;
                prev = vIsland[0].first;
                for(int i=1; i<=vIsland.size();i++){
                    if(prev == vIsland[i].first && i!=vIsland.size()){
                        cntX++;
                        continue;
                    }else{
                        prev = vIsland[i].first;
                        result += cntX*(cntPrev + (cntX-1));
                        cntPrev += cntX;
                        cntX = 1;
                    }
                }
                cout << result << endl;
                break;

            case 315:   // 북서
                sort(vIsland.begin(),vIsland.end(),cmp180);
                prev = vIsland[0].second;
                vIsland[0].second=0;
                for(int i=1;i<=vIsland.size();i++){
                    if(prev == vIsland[i].second){
                        vIsland[i].second = cnt;
                    }else{
                        prev = vIsland[i].second;
                        cnt++;
                        vIsland[i].second = cnt;
                    }
                }
                sort(vIsland.begin(),vIsland.end(),greater<pair<int,int> >());
                arr = new int[cnt+1];
                memset(arr,0,(cnt+1)*sizeof(int));
                for(auto tIsland : vIsland){
                    for(int i=tIsland.second;i<=cnt;i++){
                        result += arr[i];
                    }
                    arr[tIsland.second]++;
                }
                cout << result << endl;
                delete[] arr;
                break;

            case 360:   // 북
                sort(vIsland.begin(),vIsland.end(), cmp360);
                cntX=1;
                cntPrev=0;
                result=0;
                prev = vIsland[0].second;
                for(int i=1; i<=vIsland.size();i++){
                    if(prev == vIsland[i].second && i!=vIsland.size()){
                        cntX++;
                        continue;
                    }else{
                        prev = vIsland[i].second;
                        result += cntX*(cntPrev + (cntX-1));
                        cntPrev += cntX;
                        cntX = 1;
                    }
                }
                cout << result << endl;
                break;
        }
    }

    return 0;
}