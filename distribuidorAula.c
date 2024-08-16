#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
    Criar um algortimo sendo distribuição de horarios e aulas
    Disciplina Teoria da computação
    3 dias de aula
    1 turma

*/

#define DIAS_SEMANA 5
#define AULAS_DIA 3
#define DURACAO_AULA "2 horas"
#define Q_DISCIPLINA 1

char *dias_semana[DIAS_SEMANA] = {"Segunda-feira", "Terça-feira",
                                  "Quarta-feira", "Quinta-feira",
                                  "Sexta-feira"};
char *disciplinas[Q_DISCIPLINA] = {"TEORIA DA COMPUTACAO"};

void distribuir_aulas() {
  srand(time(NULL));

  char *horarios[DIAS_SEMANA][AULAS_DIA];
  memset(horarios, 0, sizeof(horarios));

  int dias[3] = {0, 2, 4}; // Segunda, Quarta e Sexta

  for (int i = 0; i < Q_DISCIPLINA; i++) {
    char *disciplina = disciplinas[i];
    for (int k = 0; k < 3; k++) {
      int dia = dias[k];
      for (int j = 0; j < AULAS_DIA; j++) {
        if (horarios[dia][j] == NULL) {
          horarios[dia][j] = disciplina;
          break;
        }
      }
    }
  }

  for (int i = 0; i < DIAS_SEMANA; i++) {
    printf("%s:\n", dias_semana[i]);
    for (int j = 0; j < AULAS_DIA; j++) {
      if (horarios[i][j != NULL]) {
        printf("%d aula - %s - %s\n", j + 1, DURACAO_AULA, horarios[i][j]);
      }
    }
    printf("\n");
  }
}

int main() {

  distribuir_aulas();

  return 0;
}
