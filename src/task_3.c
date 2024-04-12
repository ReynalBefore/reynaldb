#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
    int height;
} Person;

int main() {
    int N, H;
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("n/a\n");
        return 0;
    }

    Person *people = (Person *)malloc(N * sizeof(Person));
    if (people == NULL) {
        printf("n/a\n");
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if (scanf("%s %s %d", people[i].name, people[i].surname, &people[i].height) != 3) {
            printf("n/a\n");
            free(people);
            return 0;
        }
    }

    if (scanf("%d", &H) != 1 || H <= 0) {
        printf("n/a\n");
        free(people);
        return 0;
    }

    int found = 0;
    for (int i = 0; i < N; i++) {
        if (people[i].height >= H) {
            printf("%s %s", people[i].name, people[i].surname);
            found = 1;
            if (i < N - 1) {
                printf(", ");
            }
        }
    }

    if (!found) {
        printf("Nothing");
    }

    free(people);
    
    return 0;
}
