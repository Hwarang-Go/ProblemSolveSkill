//
// Created by Hwarang Go on 2017. 5. 20..
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

void distCheck(int i, vector<pair<int,int>> *road);
int dist[10000];
bool visit[10000];
long long int sum;

//bool cmp(pair<int,int> a, pair<int,int> b){return a.second < b.second;}
//bool pred(pair<int,int> a, pair<int,int> b){return a.first == b.first && a.second < b.second;}

//vector<pair<int,int>> lt; // first : city, second : time
priority_queue<P, vector<P>, greater<P> > my_pq;

int main(){
    std::ios::sync_with_stdio(false);
    int testcase, n, m;
    cin >> testcase;

    while(testcase--){
        sum = 0;
        vector<P> road[10000];
        fill(dist,dist+10000,10000000);

        cin >> n >> m; // number of city and street
        int city1, city2, time;
        for(int i=0; i<m;i++){
            cin >> city1 >> city2 >> time;
            road[city1].push_back(make_pair(time,city2));
            road[city2].push_back(make_pair(time,city1));
            visit[city1] = false;
            visit[city2] = false;
        }



        distCheck(0, road);



        cout << sum << endl;

    }

    return 0;
}


void distCheck(int i, vector<pair<int,int>> *road){
    visit[i] = true;
    for(auto j : road[i]){
        if(!visit[j.second] && dist[j.second] > j.first){
            //int nextCity = j.second;
            //int time = j.first;
            dist[j.second] = j.first;
            my_pq.push(P(dist[j.second],j.second));
        }
    }
    int nextCity;
    while(!my_pq.empty()){
        if(!visit[my_pq.top().second]){
            nextCity = my_pq.top().second;
            sum += my_pq.top().first;
            my_pq.pop();
            distCheck(nextCity, road);
        }else{
            my_pq.pop();
        }
    }
    return;
}

