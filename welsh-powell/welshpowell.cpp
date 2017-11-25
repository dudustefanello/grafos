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

int qtdCores = 0;
int cor[6] = {0x33F, 0xC0C, 0xCC0, 0xC90, 0x093, 0x069};
par auxiliar[N];
int matriz[N][N] = {
//    A B C D E F G H I J K
      0,1,0,0,0,0,0,1,0,0,0, // A
      1,0,0,1,0,0,0,0,0,0,0, // B
      0,0,0,1,0,0,0,0,0,0,0, // C
      0,1,1,0,0,0,0,0,1,0,1, // D
      0,0,0,0,0,1,0,0,0,1,1, // E
      0,0,0,0,1,0,1,0,0,0,0, // F
      0,0,0,0,0,1,0,1,0,0,1, // G
      1,0,0,0,0,0,1,0,1,1,1, // H
      0,0,0,1,0,0,0,1,0,1,0, // I
      0,0,0,0,0,0,0,1,1,0,1, // J
      0,0,0,1,1,0,1,1,0,1,0  // K
};

void colorir(int j, int i){ // Função para saber se algum vizinho tá pintado com a cor proibida
      for (int k = 0; k < N; k++) {
            if(j==9)printf("j:%d i:%d --> %d, %x, %x\n", j, i, auxiliar[j].first, auxiliar[k].second, auxiliar[i].second);

            if(matriz[auxiliar[j].first][k]){
                  printf("=-=-=-%x, %x\n", auxiliar[k].second, auxiliar[i].second);
                  if(auxiliar[k].second == cor[qtdCores]){
                        return;
                  }

            }
      }
      auxiliar[j].second = auxiliar[i].second;
      // printf("|");
}

int main(int argc, char const *argv[]) {
      // .first é usado como letra do vertice e .second como ordem

      for (int i = 0; i < N; i++) { // marca a ordem de cada vértice para ordenar
            int count = 0;
            for (int j = 0; j < N; j++) if (matriz[i][j]) count++;
            auxiliar[i].first = i;
            auxiliar[i].second = count;
      }

      sort(auxiliar, auxiliar + N, compara); // Efetua a ordenação no vetor de pares

      // impressão de teste:
      for (int i = 0; i < N; i++) printf("%c %d\n", auxiliar[i].first+65, auxiliar[i].second);

      // .second passa a ser usado para marcar a cor

      for (auto &t : auxiliar) t.second = 0; // zera a cor no vetor de cores

      // início do welsh e powell:
      // colocar  a cor do primeiro elemento:
      auxiliar[0].second = cor[qtdCores];

      for (int i = 0; i < N; i++) {
            printf("%c não tem adj com: ", auxiliar[i].first);
            for (int j = 0; j < N; j++) {
                  if (auxiliar[i].first != auxiliar[j].first && matriz[auxiliar[i].first][auxiliar[j].first] == 0) {
                        colorir(j, i); // j para colorir, i pára testar a cor
                        printf("%c%x, ", auxiliar[j].first+65, auxiliar[j].second);
                        // printf("%c, ", auxiliar[i].first+65);
                  }
            }
            printf("\n");
      }


      /*for (int i = 0; i < N; i++) {
            if (!coloracao[i]) {
                  coloracao[i] = cores[qtdCores];
                  printf("i:%d Linha %c (%3x) não tem adjacencia com: ", i, I+65, coloracao[i]);
                  for (int j = 0; j < N; j++) {
                        if (I != J && matriz[I][J] == 0) {
                              // printf("%x", coloracao[i]);
                              printf("%c->", J+65);
                              if (ver(i, j, coloracao[i])) {
                                    coloracao[j] = cores[qtdCores];
                                    // printf("Pinta\n");
                                    // printf("%x] ", cores[qtdCores]);
                              }
                              else{
                                    // printf("Não pinta\n");
                              }
                        }
                  }
                  qtdCores++;
                  printf("\n\n");
            }
      }*/

      for (size_t i = 0; i < 11; i++) {
            // printf("0x%3x\n", coloracao[i]);
      }
}
