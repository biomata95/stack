#include <stdio.h>

#include <stdlib.h>

#define Max 5

typedef struct {
  int valores[Max];
  int topo;
}
pilha;

typedef pilha * Ppilha; // pointer to stack structure

Ppilha cria_pilha() // function to build the stack
{
  Ppilha p = (Ppilha) malloc(sizeof(pilha));
  p -> topo = -1;
  return p;
}

int push(Ppilha p, int num) {
  if (p == NULL) {
    return -1; // stack not yet initialized
  }
  if (p -> topo >= Max - 1) {
    printf(" \n No value can be entered \n"); // stack is full
    sleep(7);
    return -1;
  }
  p -> topo++;
  p -> valores[p -> topo] = num;
  return 1;
}

int pop(Ppilha p) {

  if (p == NULL) {
    return -1; // not initialized
  }
  if (p -> topo < 0) {
    return -1; // empty

  }
  p -> topo--;
  printf(" The element of %d position has been removed \n", p -> topo + 2); // 2 because vector starts with 0, and p->top was decremented
  sleep(7);
  return 1;
}

void libera(Ppilha p) {
  int i;
  for (i = 0; i < p -> topo; i++) {
    free(p -> valores);
  }
  free(p);
}

void imprime(Ppilha p) {
  int i;
  system("clear");
  for (i = 0; i <= p -> topo; i++) {
    printf("\n                           position %d: %d \n", i + 1, p -> valores[i]);
  }
  sleep(7);
}

int main() {

  Ppilha p;
  int decisao, i, num;
  p = cria_pilha();
  do {
    printf(" \n \n \n \n \n \n ");
    printf("			  **** MENU ****");
    printf(" \n \n \n ");
    printf("\n - option 1: insert element\n");
    printf("\n - option 2: remove element \n");
    printf("\n - option 3: show stack \n");
    printf("\n - option 0: exit \n");
    printf("\n \n Enter an option ");
    printf(" \n \n \n \n \n");
    scanf("%d", & decisao);
    if ((decisao != 1) && (decisao != 2) && (decisao != 3) && (decisao != 0)) {
      printf("\n ### Your decision was incorrect. ### \n");
      sleep(2);
      system("clear");
    }
    switch (decisao) // switch that defines the user's decision
    {
    case 1:
      printf("Enter a value: \n");
      scanf("%d", & num);
      push(p, num);
      system("clear");
      break;

    case 2:

      pop(p);
      system("clear");
      break;

    case 3:
      imprime(p);
      system("clear");
      break;

    case 0:
      libera(p);
      exit(0);
      system("clear");
      break;
    }
  }
  while (decisao != 0);
  libera(p);
  return 0;
}