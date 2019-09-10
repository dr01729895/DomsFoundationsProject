#ifndef StringH
#define StringH

#include <stdio.h>
#include <stdlib.h>

typedef struct string {
    int size;
    int length;
    int* data;
}String;

String* makeString(void){
    String* s = NULL;
    s = (String*)malloc(sizeof(String));
    if(s == NULL){
        printf("Error, OoM1\n");
        exit(1);
    } else {
        s->size = 0;
        s->length = 10;
        s->data = (int*)malloc(sizeof(int)*s->length);
        if(s->data == NULL){
            printf("Error, OoM2\n");
            exit(1);
        }
    }
    return s;
}

void delString(String** s){
    if((*s) != NULL){
        if((*s)->data != NULL){
            free((*s)->data);
        }
        free(*s);
        *s = NULL;
    }
}

#endif