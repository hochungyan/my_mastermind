// utils.h
#ifndef UTILS_H
#define UTILS_H

char *generate_random_code();
int read_input(char *buffer);
int is_valid_guess(char *guess);
void calculate_feedback(char *secret, char *guess, int *well_placed, int *misplaced);

#endif // UTILS_H
