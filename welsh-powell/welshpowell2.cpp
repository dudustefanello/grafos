#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair <int, int> par;

#define N 11

bool compara(par a, par b){
      return a.second > b.second;
}

void popula(vector <int> grafo[N]){
      grafo[0].push_back(1);
      grafo[0].push_back(7);

      grafo[1].push_back(0);
      grafo[1].push_back(3);

      grafo[2].push_back();


}

int main(int argc, char const *argv[]) {
      vector <int> grafo[N];
      popula(grafo);
      return 0;
}
