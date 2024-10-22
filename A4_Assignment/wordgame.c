/*
Name : Shashwat Raj
ASU ID : 1230779344
Course : CSE 220
Professor : David Claveau
Assignment : A4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slist.h"

#define MAX_WORD_LENGTH 100 

void getGuess(const char* wordToGuess, char* guessedWord) {
    char guess[MAX_WORD_LENGTH + 1]; 
    printf("Guess a letter or the complete word: %s\n", guessedWord);
    scanf("%100s", guess);

    if (strlen(guess) == 1) {
        int found = 0;
        int len = strlen(wordToGuess);
        for (int i = 0; i < len && i < MAX_WORD_LENGTH; ++i) {
            if (wordToGuess[i] == guess[0] && guessedWord[i] == '_') {
                guessedWord[i] = wordToGuess[i];
                found = 1;
            }
        }
        if (!found) {
            printf("No '%c' in the word.\n", guess[0]);
        }
    } else if (strcmp(guess, wordToGuess) == 0) {
        strcpy(guessedWord, wordToGuess);
    } else {
        printf("Incorrect guess.\n");
    }
}

int PlayGuessingGame(const char* wordToGuess) {
    char guessedWord[MAX_WORD_LENGTH + 1];
    int len = strlen(wordToGuess);
    int guesses = 0;

    for (int i = 0; i < len; ++i) {
        guessedWord[i] = '_';
    }
    guessedWord[len] = '\0';

    printf("The word to guess has %d letters: %s\n", len, guessedWord);

    while (strcmp(guessedWord, wordToGuess) != 0) {
        getGuess(wordToGuess, guessedWord);
        guesses++;
    }

    printf("You got it! %s\n", wordToGuess);
    printf("You made %d guesses.\n", guesses);

    return guesses;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <word_to_guess>\n", argv[0]);
        return 1;
    }

    printf("Welcome! Press 'q' to quit or any other key to continue:\n");
    char c;
    scanf(" %c", &c);

    if (c == 'q') {
        printf("Bye Bye!\n"); //for quitting.
        return 0;
    } else {
        struct node* leaderboard = NULL; 

        while (1) {
            char playerName[30];
            printf("Please enter your name to start: ");
            scanf("%29s", playerName);

            int num_guesses = PlayGuessingGame(argv[1]);

            insertOrdered(&leaderboard, playerName, numGuesses);

            printList_n(leaderboard, 5);

            printf("Press 'q' to quit or any other key to play again: ");
            scanf(" %c", &c);
            if (c == 'q') {
                printf("Bye Bye!\n");
                break;
            }
        }
    }

    return 0;
}
