// utils.c
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "utils.h"

char *generate_random_code() {
    static char code[5];
    int used_digits[9] = {0};
    int i = 0;

    srand(time(NULL));
    while (i < 4) {
        int digit = rand() % 9;
        if (!used_digits[digit]) {
            code[i++] = '0' + digit;
            used_digits[digit] = 1;
        }
    }
    code[4] = '\0';
    return code;
}

int read_input(char *buffer) {
    char c;
    int index = 0;
    ssize_t bytes_read;

    while ((bytes_read = read(0, &c, 1)) > 0 && c != '\n') {
        buffer[index++] = c;
    }

    if (bytes_read <= 0 && index == 0) {
        // EOF or error with no input
        return 0;
    }

    buffer[index] = '\0';
    return index;
}

int is_valid_guess(char *guess) {
    if (strlen(guess) != 4)
        return 0;

    int used_digits[9] = {0};

    for (int i = 0; i < 4; i++) {
        if (guess[i] < '0' || guess[i] > '8')
            return 0;
        if (used_digits[guess[i] - '0']++)
            return 0;
    }
    return 1;
}

void calculate_feedback(char *secret, char *guess, int *well_placed, int *misplaced) {
    *well_placed = 0;
    *misplaced = 0;
    int secret_digits[9] = {0};
    int guess_digits[9] = {0};

    for (int i = 0; i < 4; i++) {
        if (secret[i] == guess[i]) {
            (*well_placed)++;
        } else {
            secret_digits[secret[i] - '0']++;
            guess_digits[guess[i] - '0']++;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (secret_digits[i] && guess_digits[i]) {
            *misplaced += (secret_digits[i] < guess_digits[i]) ? secret_digits[i] : guess_digits[i];
        }
    }
}
