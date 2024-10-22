/*
Name : Shashwat Raj
ASU ID : 1230779344
Course : CSE 220
Professor : David Claveau
Assignment : A3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slist.h"

int MAX_WORD_LENGTH = INT16_MAX; // Maximum letters in a word

struct node {
    int num_guesses;
    char name[30];
    struct node *next;
};

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

void getGuess(const char* wordToGuess, char* guessedWord) { // Takes the guessed letters/words from user
    char guess[MAX_WORD_LENGTH]; 
    printf("Guess a letter or the complete word: %s\n", guessedWord);
    scanf("%100s", guess);

    if (strlen(guess) == 1) { // Guessing letter by letter
        int found = 0;
        for (int i = 0; strlen(wordToGuess) && i < MAX_WORD_LENGTH; ++i) {
            if (wordToGuess[i] == guess[0] && guessedWord[i] == '_') {
                guessedWord[i] = wordToGuess[i]; // printing position of guessed letter in the blank word
                found = 1;
            }
        }
        if (!found) {
            printf("No '%c' in the word.\n", guess[0]);
        }
    } else if (strcmp(guess, wordToGuess) == 0) { // Correct Full word guess
        strcpy(guessedWord, wordToGuess); 
        
    } else {
        printf("Incorrect guess.\n"); // Incorrect Full word guess
    }
}

int PlayGuessingGame(const char* wordToGuess) { 
    
    char guessedWord[MAX_WORD_LENGTH]; 
    int len = strlen(wordToGuess);
    int guesses = 0;

    for (int i = 0; i < len; ++i) {
        guessedWord[i] = '_';  // Hiding and replacing letters of required word with blanks.
    }
    guessedWord[len] = '\0'; //Adding null terminator to cut the required string only

    printf("The word to guess has %d letters: %s\n", len, guessedWord);

    while (strcmp(guessedWord, wordToGuess) != 0) { //Keeps on taking guesses from the user until the guessed word is same as required word
        getGuess(wordToGuess, guessedWord);
        guesses++;
       
    }

    if(strcmp(guessedWord, wordToGuess) == 0){
        printf("You got it! %s\n", wordToGuess); // Congratulations on getting it right!!
        printf("You made %d guesses.\n", guesses);
    }

    return guesses;

} 

/*
const char* getRandomWord() {
    static char words[MAX_WORDS][MAX_WORD_LENGTH + 1];
    int wordCount = 0;

    char filename[] = "/Users/shalini/Downloads/CSE220_Codes/A3_Gradescope/words.txt";
    FILE* file = NULL;
    file = fopen( filename, "r" );

    if (!file) {
        printf("Failed to open file at %s\n", filePath);
        return "default";
    }

    while (fscanf(file, "%100s", words[wordCount]) == 1) {
        if (++wordCount >= MAX_WORDS) break;
    }
    fclose(file);

    if (wordCount > 0) {
        srand((unsigned int)time(NULL));
        return words[rand() % wordCount];
    } else {
        return "default";
    }
}

// This code can be used to get a random word from the words.txt file which is downloaded from :
//https://github.com/dwyl/english-words/blob/master/words.txt

*/

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
    }

    else{
        struct node* leaderboard = NULL;  // Initialize the leaderboard (linked list)

        while (c!='q') {
            // Get player's name
            char playerName[30];
            printf("Please enter your name to start: ");
            scanf("%s", playerName);

            // Play the word guessing game and get the number of guesses
            int num_guesses = PlayGuessingGame(argv[1]);

            // Insert the player into the leaderboard
            insertOrdered(&leaderboard, playerName, num_guesses);

            // Print the top 5 players
            printList_n(leaderboard, 5);

            printf("Press 'q' to quit or any other key to play again: ");
            scanf(" %c", &c);
            
        }
         //Play the word game

        /* PlayGuessingGame(getRandomWord()); 
        
        // In case the commented code block function is used, we could play the guessing game
        // with the aforementioned line of code. 
        */
    }

    return 0;
}