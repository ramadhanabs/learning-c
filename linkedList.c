#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *link;
};


int main(void){
  struct node *head = malloc(sizeof(struct node));
  head->value = 45;
  head->link = NULL;
  printf("Head link => %d \n", head->link);

  struct node *current = malloc(sizeof(struct node));
  current->value = 100;
  current->link = NULL;
  head->link = current;

  struct node *current2 = malloc(sizeof(struct node));
  current2->value = 200;
  current2->link = NULL;
  head->link->link = current2;

  struct node *ptr = NULL;
  ptr = head;

  while (ptr != NULL){
    printf("Value => %d \n", ptr->link);
    ptr = ptr->link;
  }

  return 0;
}
