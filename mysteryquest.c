#include <stdio.h> // Asenate de Melo Protti
#include <stdlib.h> 
#include <time.h>

int main() {
    int numeroSecreto;
    int palpite;
    int tentativas = 10;
    int pontuacao = 0;
    int vidas = 3;
    int vidaExtraUsada = 0;

    srand(time(NULL));

    printf("------BEM VINDO AO MYSTERY QUEST!!------\n");
    printf("========================================\n\n");
    printf("=== Regras do Jogo ===\n");
    printf("1. O programa vai gerar um numero aleatorio entre 0 e 30.\n");
    printf("2. Voce tem um total de 10 tentativas para adivinhar o numero.\n");
    printf("3. A pontuacao eh baseada na ordem em que voce acertar:\n");
    printf("   - 1o lugar: 1000 pontos\n");
    printf("   - 2o lugar: 800 pontos\n");
    printf("   - 3o lugar: 600 pontos\n");
    printf("   - 4o lugar: 400 pontos\n");
    printf("   - 5o lugar: 200 pontos\n");
    printf("   - 6o lugar: 100 pontos\n");
    printf("   - 7o lugar: 50 pontos\n");
    printf("   - 8o lugar: 25 pontos\n");
    printf("   - 9o lugar: 10 pontos\n");
    printf("   - 10o lugar: 5 pontos\n");
    printf("4. Se voce nao acertar o numero em 10 tentativas, perdera uma vida.\n");
    printf("5. Voce comeca o jogo com 3 vidas.\n");
    printf("6. Se voce alcancar 2000 pontos durante o jogo, ganhara uma vida extra.\n");
    printf("7. O jogo termina quando voce ficar sem vidas.\n");
    printf("========================================\n\n");

    while (vidas > 0) {
    	numeroSecreto = rand() % 31;
    	
        printf("Tentativas restantes: %d\n", tentativas);
        printf("Pontuacao: %d\n", pontuacao);
        printf("Vidas restantes: %d\n\n", vidas);

        printf("Digite o seu palpite: ");
        scanf("%d", &palpite);

        

        if (palpite == numeroSecreto) {
            printf("\n---Parabens! Voce acertou o numero!---\n\n");

            switch (tentativas) {
                case 10:
                    pontuacao += 1000;
                    printf("Voce ganhou 1000 pontos!\n");
                    break;
                case 9:
                    pontuacao += 800;
                    printf("Voce ganhou 800 pontos!\n");
                    break;
                case 8:
                    pontuacao += 600;
                    printf("Voce ganhou 600 pontos!\n");
                    break;
                case 7:
                    pontuacao += 400;
                    printf("Voce ganhou 400 pontos!\n");
                    break;
                case 6:
                    pontuacao += 200;
                    printf("Voce ganhou 200 pontos!\n");
                    break;
                case 5:
                    pontuacao += 100;
                    printf("Voce ganhou 100 pontos!\n");
                    break;
                case 4:
                    pontuacao += 50;
                    printf("Voce ganhou 50 pontos!\n");
                    break;
                case 3:
                    pontuacao += 25;
                    printf("Voce ganhou 25 pontos!\n");
                    break;
                case 2:
                    pontuacao += 10;
                    printf("Voce ganhou 10 pontos!\n");
                    break;
                case 1:
                    pontuacao += 5;
                    printf("Voce ganhou 5 pontos!\n");
                    break;
            }

            printf("Pontuacao acumulada: %d\n\n", pontuacao);

            tentativas--;

            if (tentativas == 0) {
                vidas--;
                printf("Voce perdeu uma vida!\n");

                if (pontuacao >= 2000 && vidaExtraUsada == 0) {
                    vidas++;
                    printf("Voce ganhou uma vida extra por ter alcancado 2000 pontos!\n");
                    pontuacao -= 2000;
                    vidaExtraUsada = 1;
                }

                if (vidas == 0) {
                    printf("\nGame over! Voce ficou sem vidas.\n");
                    break;
                }

                printf("Deseja usar uma vida extra e tentar novamente? (1 - Sim, 0 - Nao): ");
                int opcao;
                scanf("%d", &opcao);

                if (opcao == 1) {
                    tentativas = 10;
                } else {
                    break;
                }
            }
        } else {
            printf("\n==Palpite incorreto! :( ==\n\n");

            if (palpite < numeroSecreto) {
                printf("Dica: O numero esta entre %d e 30.\n\n", palpite + 1);
            } else {
                printf("Dica: O numero esta entre 0 e %d.\n\n", palpite - 1);
            }

            tentativas--;

            if (tentativas == 0) {
                vidas--;
                printf("Voce perdeu uma vida!\n");

                if (pontuacao >= 2000 && vidaExtraUsada == 0) {
                    vidas++;
                    printf("Voce ganhou uma vida extra por ter alcancado 2000 pontos!\n");
                    pontuacao -= 2000;
                    vidaExtraUsada = 1;
                }

                if (vidas == 0) {
                    printf("\nGame over! Voce ficou sem vidas.\n");
                    break;
                }

                printf("Deseja usar uma vida extra e tentar novamente? (1 - Sim, 0 - Nao): ");
                int opcao;
                scanf("%d", &opcao);

                if (opcao == 1) {
                    tentativas = 10;
                } else {
                	printf("\nO numero correto era %d.\n", numeroSecreto);
    				printf("Pontuacao final: %d\n", pontuacao);
                    break;
                }
            }
        }
    }

    printf("\nO numero correto era %d.\n", numeroSecreto);
    printf("Pontuacao final: %d\n", pontuacao);

    return 0;
}
