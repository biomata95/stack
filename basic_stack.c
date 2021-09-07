#include <stdio.h>

#include <stdlib.h>

#define MAX 500

struct stack {
  int topo;
  int item[MAX];
};

void inicPilha(struct stack * ps) {
  ps -> topo = -1;
}

int cheia(struct stack * ps) {
  if (ps -> topo == MAX - 1) {
    return 1;
  } else {
    return 0;
  }
}

int vazia(struct stack * ps) {
  if (ps -> topo == -1) {
    return 1;
  } else {
    return 0;
  }
}

void insere(struct stack * ps, int x) {
  if (cheia(ps) == 1) {
    printf("Full Stack \n");
  } else {
    ps -> item[++ps -> topo] = x;
  }
}

void remover(struct stack * ps) {
  if (vazia(ps) == 1) {
    printf("Empty Stack \n");
  } else {
    ps -> item[ps -> topo--];
  }
}

void mostra(struct stack * ps) {
  int i;
  for (i = 0; i < ps -> topo; i++) {
    printf("%d \n", ps -> item[i]);
  }
}

main() {
  struct stack s;
  inicPilha( & s);
  char op = 's';
  int num;
  while (op != 'n') {
    scanf("%c", & op);
    if (op == 's') {
      printf("Value: \n");
      scanf("%d", & num);
      insere( & s, num);
    }
    if (op == 'e') {
      mostra( & s);
    }
    if (op == 't') {
      remover( & s);
    }
  }

}