#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slist.h"

void insertOrdered(struct node** list, char name[], int numGuesses) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->name, name);
    newNode->numGuesses = numGuesses;
    newNode->next = NULL;

    if (*list == NULL || (*list)->numGuesses > numGuesses) {
        newNode->next = *list;
        *list = newNode;
    } else {
        struct node* curr = *list;
        while (curr->next != NULL && curr->next->numGuesses < numGuesses) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

void printList_n(struct node* list, int n) {
    struct node* curr = list;
    int count = 0;

    printf("Top %d Players:\n", n);
    while (curr != NULL && count < n) {
        printf("%s  %d guesses\n", curr->name, curr->numGuesses);
        curr = curr->next;
        count++;
    }
}