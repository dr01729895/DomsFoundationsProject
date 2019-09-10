#include <stdio.h>
#include <stdlib.h>
#include "string.h"


int main(int argc, char *argv[]){

    String* s = NULL;

    printf("%d, %d", s->size, s->length);

    delString(&s);

    return 0;
}