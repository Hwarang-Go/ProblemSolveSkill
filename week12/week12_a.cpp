//
// Created by Hwarang Go on 2017. 5. 23..
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    int testcase, line, lv, bridge, presentLocation, finish;
    cin >> testcase;
    while(testcase--){
        vector<int> bridgeArr;
        vector<int> finishLine;
        cin >> line >> lv;
        for(int i=0; i<lv; i++){
            cin >> bridge;
            bridgeArr.push_back(bridge); //1~n level : 0~n-1 index
        }

        cin >> presentLocation >> finish;

        int tempFinish = finish;
        finishLine.resize(bridgeArr.size()-1);  // 2~n level만 저장
        int index = finishLine.size()-1;
        for(int i=bridgeArr.size()-1; i>0; i--){ // n번째 level부터 2번째 level까지 거슬러 올라간다
            if(tempFinish == bridgeArr[i]){ // 현재 도착점의 오른쪽에 다리가 있으면
                ++tempFinish;               // 증가
                finishLine[index--] = tempFinish; // n-1~n 사이 위치를 저장
            }else if(tempFinish-1 == bridgeArr[i]){ //현재 도착점의 왼쪽에 다리가 있으면
                --tempFinish;                       //감소
                finishLine[index--] = tempFinish;   //n-1~n 사이 위치를 저장
            }else{
                finishLine[index--] = tempFinish; // 옮겨갈 다리가 없으면 그냥 n-1~n 사이 위치를 저장
            }
        }
        bool check = false;

        int tempLocation = presentLocation;
        for(int j=0;j<bridgeArr.size()-1;j++){  //1부터 n-1번째까지만 이동
            if(tempLocation == bridgeArr[j]){ // 현재 이동점의 오른쪽에 다리가 있으면
                ++tempLocation;                 //증가
                if(tempLocation+1 == finishLine[j] || tempLocation-1 == finishLine[j]){
                    check = true;
                    break;
                }
            }else if(tempLocation-1 == bridgeArr[j]){
                --tempLocation;
                if(tempLocation+1 == finishLine[j] || tempLocation-1 == finishLine[j]){
                    check = true;
                    break;
                }
            }else{
                if(tempLocation+1 == finishLine[j] || tempLocation-1 == finishLine[j]){
                    check = true;
                    break;
                }
            }
        }
        if(check){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }
    return 0;
}
