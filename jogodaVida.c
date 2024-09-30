#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // Para usar função sleep

#define LINHAS 20
#define COLUNAS 40

void inicializar(int grid[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            grid[i][j] = rand() % 2;  // Inicia aleatoriamente como 0 ou 1
        }
    }
}

int contarVizinhos(int grid[LINHAS][COLUNAS], int x, int y) {
    int vizinhos = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;  // Ignora a célula atual
            int novaX = (x + i + LINHAS) % LINHAS;
            int novaY = (y + j + COLUNAS) % COLUNAS;
            vizinhos += grid[novaX][novaY];
        }
    }
    return vizinhos;
}

void atualizar(int grid[LINHAS][COLUNAS], int novoGrid[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            int vizinhos = contarVizinhos(grid, i, j);
            if (grid[i][j] == 1) {
                // Célula viva
                if (vizinhos < 2 || vizinhos > 3) {
                    novoGrid[i][j] = 0;  // Morte por sub ou superpopulação
                } else {
                    novoGrid[i][j] = 1;  // Sobrevive
                }
            } else {
                // Célula morta
                if (vizinhos == 3) {
                    novoGrid[i][j] = 1;  // Reprodução
                } else {
                    novoGrid[i][j] = 0;
                }
            }
        }
    }
}

void imprimir(int grid[LINHAS][COLUNAS]) {
    system("clear");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf(grid[i][j] ? "O " : ". ");
        }
        printf("\n");
    }
}

int main() {
    int grid[LINHAS][COLUNAS];
    int novoGrid[LINHAS][COLUNAS];

    inicializar(grid);

    while (1) {
        imprimir(grid);
        atualizar(grid, novoGrid);

        // Copia o novo estado para o grid atual
        for (int i = 0; i < LINHAS; i++) {
            for (int j = 0; j < COLUNAS; j++) {
                grid[i][j] = novoGrid[i][j];
            }
        }

        usleep(200000);  // Pausa de 200ms entre gerações
    }

    return 0;
}
