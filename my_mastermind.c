// my_mastermind.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int main(int argc, char **argv) {
    char *secret_code = NULL;
    int attempts = 10;

    // Parse command-line arguments
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-c") && i + 1 < argc) {
            secret_code = argv[i + 1];
            i++;
        } else if (!strcmp(argv[i], "-t") && i + 1 < argc) {
            attempts = atoi(argv[i + 1]);
            i++;
        }
    }

    if (!secret_code) {
        secret_code = generate_random_code();
    } else if (strlen(secret_code) != 4 || !is_valid_guess(secret_code)) {
        printf("Invalid secret code!\n");
        return 1;
    }

    printf("Will you find the secret code?\n");
    printf("Please enter a valid guess\n");

    char guess[100];
    int round = 0;

    while (round < attempts) {
        printf("---\n");
        printf("Round %d\n", round);
        printf(">");

        int input_length = read_input(guess);
        if (input_length == 0) {
            // Handle EOF (Ctrl+D)
            printf("\nGoodbye!\n");
            break;
        }

        if (!is_valid_guess(guess)) {
            printf("Wrong input!\n");
            continue;
        }

        int well_placed = 0, misplaced = 0;
        calculate_feedback(secret_code, guess, &well_placed, &misplaced);

        if (well_placed == 4) {
            printf("Congratz! You did it!\n");
            break;
        } else {
            printf("Well placed pieces: %d\n", well_placed);
            printf("Misplaced pieces: %d\n", misplaced);
        }

        round++;
    }

    if (round == attempts) {
        printf("You've used all your attempts! The secret code was: %s\n", secret_code);
    }

    return 0;
}
