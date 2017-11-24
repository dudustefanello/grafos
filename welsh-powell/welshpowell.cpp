#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

typedef struct {int grau, vertice, cor;}vertice;

using namespace std;

void popula(vector <int> lista[]){
      lista[0].push_back(1);
      lista[0].push_back(7);

      lista[1].push_back(0);
      lista[1].push_back(3);

      lista[2].push_back(3);

      lista[3].push_back(1);
      lista[3].push_back(2);
      lista[3].push_back(8);
      lista[3].push_back(10);

      lista[4].push_back(5);
      lista[4].push_back(10);

      lista[5].push_back(4);
      lista[5].push_back(6);

      lista[6].push_back(5);
      lista[6].push_back(7);
      lista[6].push_back(10);

      lista[7].push_back(0);
      lista[7].push_back(6);
      lista[7].push_back(8);
      lista[7].push_back(9);
      lista[7].push_back(10);

      lista[8].push_back(3);
      lista[8].push_back(7);
      lista[8].push_back(9);

      lista[9].push_back(7);
      lista[9].push_back(8);
      lista[9].push_back(10);

      lista[10].push_back(4);
      lista[10].push_back(3);
      lista[10].push_back(6);
      lista[10].push_back(7);
      lista[10].push_back(9);
}

bool compara(vertice a, vertice b) {
      return a.grau > b.grau;
}

void wp(vector <int> lista[], vertice graus[]){
      int cor = 0;


}

int main(int argc, char const *argv[]) {
      vector <int> lista[11];
      vertice vetor[11];
      popula(lista);
      for (size_t i = 0; i < 11; i++) {
            vetor[i].grau = (int) lista[i].size();
            vetor[i].vertice = i;
      }
      sort(vetor, vetor+11, compara);
      for(auto &t : vetor) printf("%c - %d\n", t.vertice + 65, t.grau);
      wp(lista, vetor);
      // print();
      return 0;
}
