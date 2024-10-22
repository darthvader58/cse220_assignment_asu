#ifndef SLIST_H
#define SLIST_H

struct node {
    int numGuesses;
    char name[30];
    struct node* next;
};

// Function declarations for slist.c as instructed
void insertOrdered(struct node** list, char name[], int numGuesses);
void printList_n(struct node* list, int n);

#endif
