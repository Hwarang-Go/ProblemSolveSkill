//
// Created by Hwarang Go on 2017. 5. 8..
//

#include <iostream>
#include <vector>
using namespace std;

long long int tot_car;
long long int tot_park;
long long int max_car;
int visit[5001];
//int streetArr[5001][5001];

struct returnSum{
    long long int sumCar;
    long long int sumPark;
};

struct city{
    int car;
    int park;
    city(int _car, int _park) : car(_car), park(_park){};
};

returnSum dfs(int i, vector<city> &cityArr, vector<int> *relation);

int main(){
    std::ios::sync_with_stdio(false);
    int testcase, numCity, numStreet;

    cin >> testcase;

    int tCar, tPark;

    while(testcase--){
        tot_car = 0;
        tot_park = 0;
        max_car = 0;

        vector<city> cityArr;
        vector<int> relation[5001];

        //dummy
        cityArr.push_back(city(0,0));

        cin >> numCity >> numStreet;
        for(int i=1;i<=numCity;i++){
            cin >> tCar >> tPark;
            tot_car += tCar;
            tot_park += tPark;
            cityArr.push_back(city(tCar,tPark));
            visit[i] = 0;
        }
        int src, des;
        for(int j=1;j<=numStreet;j++){
            cin >> src >> des;
            relation[src].push_back(des);
            relation[des].push_back(src);
        }

        dfs(1, cityArr, relation);

        cout << max_car << endl;
    }

    return 0;
}

returnSum dfs(int i, vector<city> &cityArr, vector<int> *relation){
    long long int temp;
    returnSum resultSum;
    resultSum.sumPark = cityArr[i].park;
    resultSum.sumCar = cityArr[i].car;
    visit[i] = 1;
    for(auto j : relation[i]){
        if(visit[j] != 1) {
            returnSum tempSum = dfs(j, cityArr, relation);
            resultSum.sumCar += tempSum.sumCar;
            resultSum.sumPark += tempSum.sumPark;
        }
    }
    temp = (tot_car-resultSum.sumCar)*resultSum.sumPark + (tot_park-resultSum.sumPark)*resultSum.sumCar;
    if(max_car < temp) max_car = temp;

    return resultSum;
}