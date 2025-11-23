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
  char* copy = strdup(inputBuffer->input);
  char* token = strtok(copy," ");
    if(strcmp(token,"echo") == 0){
      inputBuffer->isValid = true;
      
      printf("%s  \n", inputBuffer->input + strlen(token) + 1);
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
