#ifndef ALL_HEADER
#define ALL_HEADER
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

#define MAXLENGTH 100
#define ERROR -1
#endif

typedef struct line{
    char *text;
} text;

typedef text ElementType;

typedef struct List{
	ElementType entry[MAXLENGTH];
	int size; 
} list;

void initiate(list *);
int length(list);
int get(list, int, ElementType*);
int next(list, int, ElementType*);
int prior(list, int, ElementType*);
void insert(list *, int, ElementType);
void mydelete(list *, int);
void add(list *,char *str);
bool isempty(list);


void initiate(list *L){
	L->size = 0;
}

int length(list L){
	return L.size;
}

bool isempty(list L){
	if(length(L)==0)
		return true;
	else
		return false;
}

bool full(list L){
	if(length(L)==MAXLENGTH)
		return true;
	else
		return false;
}

int get(list L, int i, ElementType* as){
	if ((i<1) || (i>length(L)))
		return ERROR;
	else{
		*as = L.entry[i-1];
		return 0;
	}
}

int next(list L, int i, ElementType* as){
	return get(L, i+1, as);
}

int prior(list L, int i, ElementType* as){
	return get(L, i-1, as);
}

void add(list *L,char* str){
    text x = {.text = ""};
    strcpy(x.text,str);
    insert(L,length(*L)+1,x);
}

void insert(list *L, int i, ElementType x){
	int j;
	if ((i < 1) || (i > length(*L)+1))
		printf("Insert Error! Out of range.\n");
	else{
		if(!full(*L)){
			for(j=length(*L)-1; j>=i-1; j--){
				L->entry[j+1] = L->entry[j];
			}
			L->entry[i-1] = x;
			L->size++;
		}
		else{
			printf("Insert Error! The list is full.\n");
		}	
	}

}

void mydelete(list *L, int i){
    int j;
	if ((i < 1) || (i > length(*L)))
		printf("Delete Error! Out of range.\n");
	else{
		if(!isempty(*L)){ 	
			for (j=i; j<length(*L); j++){
				L->entry[j-1] = L->entry[j];
			}
			L->size--;
		}
		else{
			printf("Delete Error! The list is empty.\n");
		}	
	}
}




