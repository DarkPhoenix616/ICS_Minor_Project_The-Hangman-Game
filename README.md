My Individual Project for the Introduction to Computer Science Course!!

ICS Minor Project
   -Danie George John (B23CI1012)

Hangman Game with Twists

   I have created and added some twists to the classic Hangman game. Instead of just words,
    the player has to predict quotes, movie names, etc.. Any number of players can play the game (Single and Multiplayer) 
    and a final leadboard will be displayed which ranks the players based on the number of lives they have left(max:8).

   system(“clear”) was used at appropriate places to clear the terminal. It is valid for Mac. If
    the user is using a windows system, system(“cls”) should be used as per my knowledge.
    The code runs perfectly on the GDB Online Debugger as well.

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