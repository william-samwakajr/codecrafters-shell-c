#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_BUFFER_SIZE 1024



typedef struct {
  char* input;
  int size;
  bool isValid;
}InputBuffer;

InputBuffer createBuffer(){

  InputBuffer inputBuffer;
  inputBuffer.input = calloc(MAX_BUFFER_SIZE , sizeof(char));
  inputBuffer.size = 0;
  inputBuffer.isValid = false;
  return inputBuffer;
}

 int intitializeBuffer(InputBuffer* inputBuffer){

  fgets(inputBuffer->input,MAX_BUFFER_SIZE,stdin);
  inputBuffer->size = strlen(inputBuffer->input);
  inputBuffer->input[strcspn(inputBuffer->input, "\n")] = '\0';

  return inputBuffer->size;
}

 bool checkBufferValidity(InputBuffer* inputBuffer){
  
  char* pathEnv = getenv("PATH");
  if(path_env == NULL){
    fprintf(stderr,"PATH environment Variable not found. \n");
  }

  char* copy = strdup(inputBuffer->input);
  char* token = strtok(copy," ");
  char* inputAfterCommand = inputBuffer->input + strlen(token) + 1;

    if(strcmp(token,"type") == 0){

      inputBuffer->isValid = true;

      if(strcmp(inputAfterCommand,"echo") == 0){

        printf("echo is a shell builtin\n");

      }else if(strcmp(inputAfterCommand,"exit")== 0){
       
        printf("exit is a shell builtin\n");
      
      }else if(strcmp(inputAfterCommand,"type")==0){
      
      printf("type is a shell builtin\n");

    }else{
      printf("%s: not found\n",inputAfterCommand);
    }
      
    }
    if(strcmp(token,"echo") == 0){
      inputBuffer->isValid = true;
      
      printf("%s  \n", inputAfterCommand);
    }
  
   if(strcmp(inputBuffer->input,"exit") == 0){
    inputBuffer->isValid = true;
    exit(0);
  }
  

  return inputBuffer->isValid;
}

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  InputBuffer inputBuffer = createBuffer();


  printf("$ ");;
 while(intitializeBuffer(&inputBuffer) ){
    checkBufferValidity(&inputBuffer);
      
    if(inputBuffer.isValid ){
       ;
    }else{
      
      printf("%s: command not found\n",inputBuffer.input);
    }
    printf("$ ");
  }

    

  return 0;
}
