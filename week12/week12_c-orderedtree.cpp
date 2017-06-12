//
// Created by Hwarang Go on 2017. 6. 12..
//

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int T , N , nodeNum;
int in_d , in;

vector<int> node;

long long fac(int p, int n)
{
   long long result = 1;
   for (int i = 0; i < n; ++i)
   {
      result *= (p - i);
   }

   return result;
}

int rec(int depth, int parentNum, int remainder)
{
      if (remainder == 0)   return 1;
      if (remainder < 0)   return 0;

      int mid;

      if (depth < node.size())
      {
          mid = rec(depth + 1, node[depth], remainder - node[depth]) * ((fac(parentNum+node[depth]-1, node[depth]) / fac(node[depth], node[depth])));
      }
      else
      {
         mid = 0;
         for (int i = 1; i <= remainder; ++i)
         {
         mid += (rec(depth + 1, i, remainder - i) * ((fac(parentNum+i-1, i) / fac(i,i))));
         }
      }

      return mid;
}

int main()
{
   ios::sync_with_stdio(false);
   ofstream file("output.txt");

   cin >> T;

   while (T--)
   {
      cin >> N;

      cin >> in_d;

      for (int i = 0; i <= in_d; i++)
      {
         cin >> in;
         node.push_back(in); 
      }
      
      cout << rec(1, node[0], N - node[0]) << "\n";
      //file << rec(1, node[0], N - node[0]) << "\n";

      node.clear();
   }
   return 0;
}