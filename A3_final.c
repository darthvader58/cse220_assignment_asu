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

int MAX_WORD_LENGTH = INT16_MAX; // Maximum letters in a word

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

void PlayGuessingGame(const char* wordToGuess) { 
    char guessedWord[MAX_WORD_LENGTH]; 
    int len = strlen(wordToGuess);
    for (int i = 0; i < len; ++i) {
        guessedWord[i] = '_';  // Hiding and replacing letters of required word with blanks.
    }
    guessedWord[len] = '\0'; //Adding null terminator to cut the required string only

    printf("The word to guess has %d letters: %s\n", len, guessedWord);

    while (strcmp(guessedWord, wordToGuess) != 0) { //Keeps on taking guesses from the user until the guessed word is same as required word
        getGuess(wordToGuess, guessedWord);
    }

    if(strcmp(guessedWord, wordToGuess) == 0){
        printf("You got it! %s\n", wordToGuess); // Congratulations on getting it right!!
    }
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
        PlayGuessingGame(argv[1]); //Play the word game

        /* PlayGuessingGame(getRandomWord()); 
        
        // In case the commented code block function is used, we could play the guessing game
        // with the aforementioned line of code. 
        */
    }

    return 0;
}