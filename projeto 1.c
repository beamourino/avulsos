//realizar um jogo da velha em C
#include <stdio.h>
void imprime_matriz(char tabuleiro[3][3]) { 
printf("  0   1   2\n");
printf("0 %c | %c | %c\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
printf(" ---+---+---\n");
printf("1 %c | %c | %c\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
printf(" ---+---+---\n");
printf("2 %c | %c | %c\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
}
void inicializa_matriz(char tabuleiro[3][3]) {
char linha, coluna;
  for (linha = 0; linha < 3; linha++) {
  for (coluna = 0; coluna < 3; coluna++) {
  tabuleiro[linha][coluna] = ' ';
}}}
char verificar_posicao(char tabuleiro[3][3], char linha, char coluna){
if (linha<0 || linha>2 || coluna<0 || coluna>2){
  return 'n';
}
if (tabuleiro[linha][coluna] != ' '){
  return 'n';
}
  return 's';
}
char ganhou_linhas(char tabuleiro[3][3], char jogador){
int linha;
for (linha = 0; linha < 3; linha++){
if (tabuleiro[linha][0] == jogador && tabuleiro[linha][1] == jogador && tabuleiro[linha][2] == jogador){
return 's';
}}
  return 'n';
}
char ganhou_colunas(char tabuleiro[3][3], char jogador){
int coluna;
for (coluna = 0; coluna < 3; coluna++){
if (tabuleiro[0][coluna] == jogador && tabuleiro[1][coluna] == jogador && tabuleiro[2][coluna] == jogador){
return 's';
}}
  return 'n';
}
char ganhou_diagonais(char tabuleiro[3][3], char jogador){
if ((tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ||(tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)){
return 's';
}
return 'n';
}
int main(void) {
  char nome1[30], nome2[30];
  int linha,coluna,i=1;
  char tabuleiro[3][3];
  printf("**************JOGO DA VELHA*************\n\n");
  printf("Jogador 1: ");
  scanf(" %[^\n]s", nome1);
  printf("Jogador 2: ");
  scanf(" %[^\n]s", nome2);
  printf("\n*******Boa sorte jogadores, %s e %s!!!*********", nome1, nome2);
  printf("\n\n-- %s será o X e o %s será o O --\n", nome1,nome2);
  printf("*****************************************\n\n");
  inicializa_matriz(tabuleiro);
  imprime_matriz(tabuleiro);
  while ( i<=9) {
    if (i%2==1){
      printf("Vez do Jogador 1\n");
      printf("%s, escolha a posição da sua jogada:\n", nome1);
      printf("Linha: ");
      scanf("%d", &linha);
      printf("Coluna: ");
      scanf("%d", &coluna);
      if (verificar_posicao(tabuleiro, linha, coluna)=='s'){
      tabuleiro[linha][coluna] = 'X';
        if (ganhou_linhas(tabuleiro, 'X') == 's' || ganhou_colunas(tabuleiro, 'X') == 's' || ganhou_diagonais (tabuleiro, 'X') == 's'){
        imprime_matriz(tabuleiro);
        printf("%s venceu!!!! Arrasou!!\n", nome1);
        printf("Obrigada por jogar!!!\n");
        break;}
        i++;
      }else if (verificar_posicao(tabuleiro, linha, coluna)=='n'){
        printf("Posição inválida, tente novamente\n");
      }
      imprime_matriz(tabuleiro);
    }else if (i%2==0){
      printf ("Vez do Jogador 2\n");
      printf("%s, escolha a posição da sua jogada:\n",nome2);
      printf("Linha: ");
      scanf("%d", &linha);
      printf("Coluna: ");
      scanf("%d", &coluna);
      if (verificar_posicao(tabuleiro, linha, coluna)=='s'){
      tabuleiro[linha][coluna] = '0';
        if (ganhou_linhas(tabuleiro, '0') == 's' || ganhou_colunas(tabuleiro, '0') == 's'|| ganhou_diagonais (tabuleiro, '0') == 's') {
        imprime_matriz(tabuleiro);
        printf("%s venceu!!!! Arrasou!!\n", nome1);
        printf("Obrigada por jogar!!!\n");
        break;}
        i++;
      }else if (verificar_posicao(tabuleiro, linha, coluna)=='n'){
      printf("Posição inválida, tente novamente\n");
      }
      imprime_matriz(tabuleiro);
    }
  }
   return 0;
  }
