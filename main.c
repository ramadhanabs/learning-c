#include <stdio.h>
#include <time.h>
#include <string.h>

void flushInput(void);

int showMenu(void){
  char c;

  char* menus[] = {
    "List Tasks",
    "Add Task",
    "Find Task by ID",
    "Delete Task by ID",
    "Exit"
  };

  int menuSize = sizeof(menus)/sizeof(char*);
  printf("Ukuran menu %d \n", menuSize);

  for(int i = 0; i < menuSize; i++){
    printf("%d. %s \n", i, menus[i]);
  }

  scanf("%c", &c);
  flushInput();

  return c - '0';
}

#define TEXT_SIZE 255

struct Task
{
  int id;
  char text[TEXT_SIZE];
  time_t timestamp;
};

void showTask(struct Task *task){
  printf("%d %s %s \n", task->id, task->text, ctime(&task->timestamp));
};


int main(void){
    struct Task Tasks[10];
    int n = 1;

    Tasks[0].id = 1;
    Tasks[0].timestamp = time(NULL);
    strncpy(Tasks[0].text, "Hello", TEXT_SIZE);

    for (;;){
      int c = showMenu();
      if (c == 0){
        // Show list task
        if (n == 0){
          printf("Nothing here");
        } else {
          showTask(&Tasks[0]);
        }
      } else if (c == 1){
        // Add task
        
      } else if (c == 2){
        // Find task
      } else if (c == 3){
        // Delete task
      } else if (c == 4) {
        // Error
        break;
      } else {
      }
    }

    return 0;
}

void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // consume characters until newline or end of file
}