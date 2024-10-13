#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/* Stack */
typedef struct
{
  char *data;
  int size;
  int capacity;
} CharStack;

void initStack(CharStack *stack, int initialCapacity)
{
  stack->data = (char*)malloc(initialCapacity * sizeof(char));
  stack->size = 0;
  stack->capacity = initialCapacity;
}

bool isEmpty(CharStack *stack)
{
  return stack->size == 0;
}

void push(CharStack *stack, char element)
{
  if (stack->size >= stack->capacity)
  {
    stack->capacity *= 2; // Double the capacity
    stack->data = (char*)realloc(stack->data, stack->capacity * sizeof(char));
    stack->data[stack->size++] = element;
  }
  else
  {
    stack->data[stack->size++] = element;
  }
}

char pop(CharStack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack underflow! Cannot pop from an empty stack.\n");
    return '\0'; // Return null character or handle error
  }

  return stack->data[--stack->size];
}

char getLatestValue(CharStack *stack){
  if(stack->size > 0){
    return stack->data[stack->size - 1];
  }

  return '\0';
}

void freeStack(CharStack *stack)
{
  free(stack->data);
  stack->data = NULL; // Set to NULL to avoid dangling pointer
}

void printStack(const CharStack *stack)
{
  for (int i = 0; i < stack->size; i++)
  {
    printf("%c ", stack->data[i]);
  }
  printf("\n");
}
/* End of Stack */

/* Bracket */
typedef struct
{
  char closing;
  char opening;
} BracketMap;

BracketMap bracketMap[] = {
    {'}', '{'},
    {']', '['},
    {')', '('}};

int size = sizeof(bracketMap) / sizeof(bracketMap[0]);

bool includes(char *array, int size, char target)
{
  for (int i = 0; i < size; i++)
  {
    if (array[i] == target)
    {
      return true;
    }
  }

  return false;
};

char getOpeningBracket(char closingBracket){
  for(int i = 0; i < size; i++){
    if(bracketMap[i].closing == closingBracket){
      return bracketMap[i].opening;
    };
  };

  return '\0';
}
/* End of Bracket */


bool isValid(char *s)
{
  if (strlen(s) <= 1)
  {
    return false;
  };

  char openingBracketList[size];

  for (int i = 0; i < size; i++)
  {
    openingBracketList[i] = bracketMap[i].opening;
  };

  CharStack stack;
  initStack(&stack, 2);

  for (int i = 0; s[i] != '\0'; i++)
  {
    if (includes(openingBracketList, size, s[i]))
    {
      push(&stack, s[i]);
    }
    else
    {
      if(stack.size == 0){
        return false;
      };

      char openingBracket = getOpeningBracket(s[i]);
      char latestChar = getLatestValue(&stack);

      if (openingBracket != '\0' && openingBracket == latestChar){
        pop(&stack);
      } else {
        return false;
      }
    }
  };

  if (stack.size == 0){
    freeStack(&stack);
    return true;
  } else {
    freeStack(&stack);
    return false;
  }
};

int main(void){
  bool value = isValid("(([]){})");
  printf("Value is %s", value ? "true" : "false");
  return 0;
}