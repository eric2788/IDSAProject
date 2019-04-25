#ifndef ALL_HEADER
#define ALL_HEADER
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

#define MAXLENGTH 1000
#define ERROR -1
#endif

typedef char *ElementType;

typedef struct List{
	ElementType entry[MAXLENGTH];
	int size; 
} list;

void initiate(list *);
int length(list);

int get(list, int, char *);

int next(list, int, char *);

int prior(list, int, char *);

void insert(list *, int, const char *);
void mydelete(list *, int);

void add(list *, const char *);
bool isempty(list);

bool contain(list, const char *);


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

int get(list L, int i, char *as) {
	if ((i<1) || (i>length(L)))
		return ERROR;
	else{
        strcpy(as, L.entry[i - 1]);
		return 0;
	}
}

int next(list L, int i, char *as) {
	return get(L, i+1, as);
}

int prior(list L, int i, char *as) {
	return get(L, i-1, as);
}

void add(list *L, const char *str) {
    if (contain(*L, str))
        return;
    insert(L, length(*L) + 1, str);
}

bool contain(list L, const char *str) {
    int i = 0;
    char string[100];
    while (next(L, ++i, string) != -1) {
        if (strcmp(str, string) == 0) {
            return true;
        }
    }
    return false;
}

void insert(list *L, int i, const char *x) {
    char *copy = malloc(sizeof(copy));
    strcpy(copy, x);
	int j;
	if ((i < 1) || (i > length(*L)+1))
		printf("Insert Error! Out of range.\n");
	else{
		if(!full(*L)){
			for(j=length(*L)-1; j>=i-1; j--){
				L->entry[j+1] = L->entry[j];
			}
            L->entry[i - 1] = copy;
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




