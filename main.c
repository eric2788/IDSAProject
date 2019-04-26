#include <stdio.h>
#include "utils.h"
#include "string-list.h"

#define DEBUG "[DEBUG]"

List *outputList(const char *);

List *filter(List *);

int main() {
    char filename[99];
    printf("Input the file name to scan: ");
    scanf("%s", filename);
    fflush(stdin);
    List *list = outputList(filename);
    if (list == NULL) {
        return 0;
    }
    List_print(filter(list));
    return 0;
}

List *outputList(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("%s is not exist, cancelled.\n", filename);
        return NULL;
    }
    char str[100];
    List *input = List_create();
    while (fscanf(fp, "%s", str) != EOF) {
        if (strlen(str) < 2) continue;
        printf("%sAdding \"%s\" to the List\n", DEBUG, str);
        List_append(input, str);
    }
    fclose(fp);
    FILE *list_fp = fopen("list.txt", "w+");
    for (int i = 0; i < List_length(input); ++i) {
        const char *string = List_get(input, i);
        printf("%sPrinting \"%s\" to the file \"list.txt\"\n", DEBUG, string);
        fprintf(list_fp, "%s\n", string);
    }
    fclose(list_fp);
    return input;
}

List *filter(List *words) {
    char *previous, *next;
    List *filter = List_create();
    int l, j;
    for (l = 0; l < List_length(words); ++l) {
        bool equal = false;
        bool contain = false;
        previous = List_get(words, l);
        printf("%shandling \"%s\"\n", DEBUG, previous);
        for (j = 0; j < List_length(filter); j++) {
            next = List_get(filter, j);
            //printf("checking %s\n",next);
            char tempStr[100];
            strcpy(tempStr, next);
            char *compare;
            compare = strtok(tempStr, ", "); // "abcd, bacd"
            if (compare == NULL) compare = next; //"abcd"
            if (strcmp(compare, previous) == 0) continue;
            //printf("compare: %s vs %s (%s)\n",compare,previous,next);
            equal = equal_char_arr(compare, previous);
            //printf("result: %s\n",(equal?"yes":"no"));
            //char *con = strstr(filter[j], original[l]);
            contain = str_contain(next, previous);
            //printf("Checking contain :%s and %s\n",next,previous);
            //printf("contain: %s\n",contain ? "true" : "false");
            if (equal){
                char *temp = next; // "abcd, bacd"
                char *dest = ", "; // ", "
                strcat(temp,dest); // "abcd, bacd, "
                //filter[j] = strcat(temp,dest);
                strcat(temp, previous); // "abcd, bacd, abcd"
                List_remove(filter, j);
                List_insert(filter, j, temp);
                //printf("filter[%d]: %s\n",j,next);
                break;
            }
        }
        if (!equal && !contain) {
            //filter[i] = str;
            List_append(filter, previous);
            //printf("added %s in filter \n",previous);
        }
    }
    return filter;
}


int wholeProcess() {
    char *previous;
    char *next;
    List *words = List_create();
    List *filter = List_create();
    char str[9999];
    FILE *fp = fopen("data.txt", "a+");
    int j = 1, i, l, k;
    i = l = k = 0;
    while (fscanf(fp, "%s", str) != EOF) {
        List_append(words, str);
        ++j;
    }
    fclose(fp);
    i = 0;
    List_print(words);
    for (l = 0; l < List_length(words); ++l) {
        bool equal = false;
        bool contain = false;
        previous = List_get(words, l);
        printf("handling %s\n", previous);
        for (j = 0; j < List_length(filter); j++) {
            next = List_get(filter, j);
            printf("checking %s\n", next);
            char tempStr[9999];
            strcpy(tempStr, next);
            char *compare;
            compare = strtok(tempStr, ", "); // "abcd, bacd"
            if (compare == NULL) compare = next; //"abcd"
            if (strcmp(compare, previous) == 0) continue;
            printf("compare: %s vs %s (%s)\n", compare, previous, next);
            equal = equal_char_arr(compare, previous);
            printf("result: %s\n",(equal?"yes":"no"));
            //char *con = strstr(filter[j], original[l]);
            contain = str_contain(next, previous);
            printf("Checking contain :%s and %s\n", next, previous);
            printf("contain: %s\n",contain ? "true" : "false");
            if (equal){
                char *temp = next; // "abcd, bacd"
                char *dest = ", "; // ", "
                strcat(temp,dest); // "abcd, bacd, "
                //filter[j] = strcat(temp,dest);
                strcat(temp, previous); // "abcd, bacd, abcd"
                List_remove(filter, j);
                List_insert(filter, j, temp);
                printf("filter[%d]: %s\n", j, next);
                break;
            }
        }
        if (!equal && !contain) {
            //filter[i] = str;
            List_append(filter, previous);
            printf("added %s in filter \n", previous);
            ++i;
        }
    }
    List_print(filter);
    return 0;
}

/*int main(){
    char* previous = malloc(sizeof(previous));
    char* next = malloc(sizeof(next));
    list words;
    list filter;
    initiate(&words);
    initiate(&filter);
    char str[9999];
    FILE *fp = fopen("test.txt","a+");
    int j = 1, i, l , k;
    while (fscanf(fp, "%s", str) != EOF) {
        printf("%sAdding %s\n",DEBUG,str);
        add(&words,str);
        ++j;
    }
    fclose(fp);
    i = 0;
    for (int m = 1; m <= length(words); m++) {
        get(words,m,previous);
        printf("debug: original[%d] = %s\n",m,previous);
    }
    for (l = 1; l <= length(words); ++l) {
        bool equal = false;
        bool contain = false;
        printf("handling %s\n",previous);
        for (j = 1; j <= length(filter); j++) {
            get(filter,j,next);
            printf("checking %s\n",next);
            char tempStr[9999];
            strcpy(tempStr,next);
            char* compare;
            compare = strtok(tempStr, ", "); // "abcd, bacd"
            if (compare == NULL) compare = next; //"abcd"
            if (strcmp(compare,previous) == 0) continue;
            printf("compare: %s vs %s (%s)\n",compare,previous,next);
            equal = equal_char_arr(compare, previous);
            printf("result: %s\n",(equal?"yes":"no"));
            //char *con = strstr(filter[j], original[l]);
            contain = str_contain(next,previous);
            printf("Checking contain :%s and %s\n",next,previous);
            printf("contain: %s\n",contain ? "true" : "false");
            if (equal){
                char *temp = next; // "abcd, bacd"
                char *dest = ", "; // ", "
                strcat(temp,dest); // "abcd, bacd, "
                //filter[j] = strcat(temp,dest);
                strcat(temp,previous); // "abcd, bacd, abcd"
                strcpy(next,temp);
                printf("filter[%d]: %s\n",j,next);
                break;
            }
        }
        if (!equal && !contain) {
            //filter[i] = str;
            strcpy(next,previous);
            printf("added %s in filter \n",next);
            ++i;
        }
    }
    for (k = 1; k <= length(filter); ++k) {
        get(filter,k,next);
        printf("\n%s",next);
    }
    return 0;
}*/

/*int main2221() {
    char **original = (char**) malloc(1000 * sizeof(*original));
    char **filter = malloc(1000 * sizeof(*filter));
    FILE *fp = fopen("test.txt", "a+");
    char str[9999];
    char *compare;
    int i = 0, j = 0, l = 0, k = 0;
    while (fscanf(fp, "%s", str) != EOF) {
        bool contain = containStr(str,original);
        printf("contain is %s\n",(contain ? "true" : "false"));
        if (contain) continue;
        original[i] = str;
        //strcpy(original[i],str);
        printf("added \"%s\"\n",original[i]);
        ++i;
    }
    fclose(fp);
    i = 0;
    for (int m = 0; m < getlength(original); m++) {
        printf("debug: original[%d] = %s\n",m,original[m]);
    }
    for (l = 0; l < getlength(original); ++l) {
        bool equal = false;
        bool contain = false;
        printf("handling %s\n",original[l]);
        for (j = 0; j < getlength(filter); j++) {
            printf("checking %s\n",filter[j]);
            char tempStr[9999];
            strcpy(tempStr,filter[j]);
            compare = strtok(tempStr, ", "); // "abcd, bacd"
            if (compare == NULL) compare = filter[j]; //"abcd"
            if (strcmp(compare,original[l]) == 0) continue;
            printf("compare: %s vs %s (%s)\n",compare,original[l],filter[j]);
            equal = equal_char_arr(compare, original[l]);
            printf("result: %s\n",(equal?"yes":"no"));
            //char *con = strstr(filter[j], original[l]);
            contain = str_contain(filter[j],original[l]);
            printf("Checking contain :%s and %s\n",filter[j],original[l]);
            printf("contain: %s\n",contain ? "true" : "false");
            if (equal){
                char *temp = filter[j]; // "abcd, bacd"
                char *dest = ", "; // ", "
                strcat(temp,dest); // "abcd, bacd, "
                //filter[j] = strcat(temp,dest);
                strcat(temp,original[l]); // "abcd, bacd, abcd"
                strcpy(filter[j],temp);
                printf("filter[%d]: %s\n",j,filter[j]);
                break;
            }
        }
        if (!equal && !contain) {
            //filter[i] = str;
            strcpy(filter[i],original[l]);
            printf("added %s in filter \n",filter[i]);
            ++i;
        }
    }
    for (k = 0; k < getlength(filter); ++k) {
        printf("\n%s",filter[k]);
    }
    return 0;
}*/