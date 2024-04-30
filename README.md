My Minor Project for the Introduction to Computer Science Course!!

ICS Minor Project
   -Danie George John (B23CI1012)

Danie's Hangman Game


Welcome to the Hangman game, a modern twist on the classic word-guessing game! This version of Hangman features various categories, supports both single and multiplayer modes, and includes background music and sound effects to enhance the gaming experience.

## Features:

- **Multiple Categories**: Choose from various categories including Marvel Quotes, Famous Quotes, Famous Movies, and Graded Semester 2 Courses.
- **Single and Multiplayer Modes**: Play alone or compete against friends.
- **Leaderboard**: A final leaderboard ranks players based on the number of lives they have left, with a maximum of 8 lives per player.
- **Interactive Gameplay**: Players can predict individual letters or the entire string itself, with wrong guesses resulting in the loss of a life.
- **Background Music**: Enjoy immersive gameplay with background music playing throughout the game.
- **Sound Effects**: Engage with the game using sound effects such as rope sounds, victory sounds, and more.

## Requirements:

- C Compiler (e.g., GCC)
- Standard C Libraries
- afplay (Command Line Audio Player) - For Mac users

## How to Play:

1. Clone the repository.
2. Compile the code using a C compiler.
3. Ensure you have `afplay` installed on your Mac system for audio playback.
4. Run the compiled executable.
5. Follow the on-screen instructions to play the game.

## Background Sound and Sound Effects:

- **Background Music**: The game features background music to enhance the gaming atmosphere. The music file is played using the `afplay` command line audio player.
- **Sound Effects**: Various sound effects are used throughout the game, including rope sounds, victory sounds, and more. These sound effects are also played using `afplay`.

## Code Analysis:

The Hangman game is written in C and utilizes various standard C libraries such as `stdio.h`, `string.h`, `time.h`, `stdlib.h`, and more. Here's a brief analysis of the code structure:

- **Main Functionality**: The core functionality of the game is implemented in the `start_hangman()` function, which handles the main game loop, player input, word selection, and gameplay logic.
- **User Interface**: The game provides a user-friendly interface with clear instructions, category selection, and interactive gameplay.
- **Terminal Clearing**: The `system("clear")` command is used at appropriate places to clear the terminal screen for better readability.
- **Background Music and Sound Effects**: Background music and sound effects are implemented using the `afplay` command line audio player, enhancing the overall gaming experience.
- **Signal Handling**: Signal handling is implemented to terminate background music and sound effects when the game is exited.

---

Feel free to customize this README further with additional details, instructions, or any other information you find relevant. Enjoy playing the Hangman game!

   Rules and Regulations to be followed
    
    1. Enter the category(1,2,3,4) and the number of players in the beginning.
    2. In a game, all the players will be given the same string to predict and whoever predicts it consuming the least number
       of lives will be ahead on the leaderboard.
    3. The string given in each category will be random from a set.
    4. In each round, a player can predict either a letter or the entire string itself if confident.
    5. In either case, they will lose a life if the entered letter is not in the string, or if they predicted the wrong string.
    6. If the player loses a life, the stick man starts to get hanged on the podium. When no lives are left, he will die.
    7. If the predicted letter turns out to be correct, it will be displayed at it's corresponding positions.
    8. PLEASE DO NOT ENTER THE SAME PREDICTED LETTER REPEATEDLY!!! 
    9. The play would be such that, first the first player plays the whole game, gets a final score(lives left), then the next player
       etc..
    10. At any point in the game, if the player wants to quit out of the game, just type "quit". His lives would be reduced to 0.
    11. Please mind the fact that there might be commas at necessary positions in the quote.

      Thank You and Enjoy the game!!!! 
