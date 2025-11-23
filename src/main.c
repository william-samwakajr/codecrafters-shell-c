#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
  // Flush after every printf
  

  char command[1024];
  fgets(command,sizeof(command),stdin);
  printf("%s: command not found\n",command);

  return 0;
}
