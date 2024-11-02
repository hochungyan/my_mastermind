# Welcome to My Mastermind
***

## Task
My Mastermind is a classic code-breaking game where the player attempts to guess a secret code composed of 4 unique digits ranging from '0' to '8'. The challenge lies in deducing the correct code within a limited number of attempts by using logical reasoning based on the feedback provided after each guess.

## Description
This project is an implementation of the Mastermind game in C. The program can generate a random secret code or accept one provided via command-line arguments. The player interacts with the game through the terminal, entering guesses and receiving feedback on well-placed and misplaced digits.

## Installation
To compile the program, you need to have gcc installed on your system. Use the provided Makefile to compile the project by running:

make
This command will compile the source files and generate an executable named my_mastermind.

If you need to clean up object files and the executable, you can run:

make clean
To remove all compiled files and recompile the project from scratch, use:

make re

## Usage
The program can be executed from the terminal with optional arguments:
./my_mastermind [-c CODE] [-t ATTEMPTS]
-c CODE: (Optional) Specifies a custom secret code (4 unique digits between '0' and '8'). If omitted, a random code is generated.
-t ATTEMPTS: (Optional) Specifies the number of attempts the player has to guess the code (default is 10).
How It Works
Start the Game: Run the program, optionally specifying a secret code and the number of attempts.
Enter Guesses: The program will prompt you to enter your guess. Input a 4-digit code with unique digits between '0' and '8'.
Receive Feedback:
Well placed pieces: Number of digits that are correct and in the correct position.
Misplaced pieces: Number of digits that are correct but in the wrong position.
Iterate: Use the feedback to inform your next guess.
Win or Lose: The game ends when you guess the secret code correctly or run out of attempts.

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
