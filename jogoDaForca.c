#include <stdio.h>
#include <string.h>
#include <ctype.h>

void desenharForca(int erros) {
  printf("\n ------\n");
  printf(" |    |\n");
  printf(" |    %c\n", (erros >=1) ? 'O' : ' ');
  printf(" |   %c%c%c\n", (erros >= 3)  ? '/' : ' ', (erros >= 2) ? '|' : ' ', (erros >= 4 ) ? '\\' : ' ');
  printf(" |   %c %c\n", (erros >= 5) ? '/' : ' ', (erros >=6) ? '\\' : ' ');
  printf("_|_\n\n");
}

int main() {

  char palavraSecreta[46];
  int tamanho;

  printf("Mestre, digite a palavra secreta: ");
  scanf("%s", &palavraSecreta);

  printf("Mestre, digite o tamanho da palavra: ");
  scanf("%d", &tamanho);

  __fpurge(stdin);
  
  //char palavraSecreta[] = "pneumoultramicroscopicossilicovulcanoconiotico"; 
  
  // nao indicado
  // int tamanho = 6;
  
  // int tamanho = strlen(palavraSecreta);
  char letra;
  int tentativas = 6;
  int acertos=0;
  char descobertas[tamanho];
  int letrasUsadas[26] = {0};
  int erros=0;

  for (int i = 0; i<tamanho ; i++)
    descobertas[i] = '_';


  printf("=== Jogo da Forca ===\n");

  while (tentativas > 0 && acertos < tamanho) {
    desenharForca(erros);

    printf("Palavra: ");
    for (int i = 0; i<tamanho ; i++)
      printf("%c ", descobertas[i]);

      // palavraSecreta == ['a', 'b', 'e', 'l', 'h', 'a']
      // palavraSecreta[0] == 'a';

    printf("\nTentativas restantes: %d", tentativas);
    printf("\nDigite uma letra: ");
    scanf("%c", &letra);
    
    // transforma de maiúscula para minúscula
    letra = tolower(letra);

    if (letrasUsadas[letra - 'a']) {
      printf("Você já tentou usar a letra '%c'. Tente outra.\n", letra);
      continue;
    }
    // letrasUsadas = [1, 0, 0, ..., 0];
    letrasUsadas[letra - ' '] = 1;

    int encontrou = 0;
    for (int i =0; i< tamanho ; i++) {
      if(palavraSecreta[i] == letra && descobertas[i] == '_'){
        descobertas[i] = letra;
        acertos++;
        encontrou = 1;
      }
    }

    // &&, || , !  
    // a | b | a && b | a || b | !a | !b
    // 0 | 1 |   0    |    1   | 1  | 0 
    

    if(!encontrou) {
      printf("Letra incorreta!\n");
      tentativas--;
      erros++;
    }
    __fpurge(stdin);
  }

  desenharForca(erros);

  if (acertos == tamanho) {
    printf("Parabéns! Você descobriu a palavra: %s\n", palavraSecreta);
  } else {
    printf("Fim de jogo! A palavra era: %s\n", palavraSecreta);
  }
  
  return 0;
}