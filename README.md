# 2048 Game (CLI Version) in C

## Project Description

The project aims to develop a command-line interface (CLI) version of the popular puzzle game "2048" using the C programming language. The game will allow players to experience the classic 2048 gameplay by sliding numbered tiles on a grid to merge them and achieve the coveted 2048 tile. The primary focus will be on creating a functional and enjoyable CLI game with a user-friendly interface.

## Project Goals

- Implement a fully playable CLI version of the 2048 game that captures the essence of the original gameplay.
- Provide users with an intuitive interface for moving tiles using 'w' ,'s' ,'a' ,'d' keys and quitting the game using the 'q' key.
- Enhance user experience by displaying the game board with the help of matrix.
- Ensure the game adheres to the rules of 2048, including tile merging and random tile generation.

## Features

1. **CLI Interface:** Develop a text-based interface that allows users to interact with the game using their keyboard.

2. **Basic Gameplay:** Implement the core 2048 gameplay mechanics, including tile sliding and merging.

3. **Random Tile Generation:** Generate new tiles with value of 2  at random empty spots on the board after each move.

4. **User Input Handling:** Capture user input using 'w' ,'s' ,'a' ,'d' keys for tile movement and 'q' for quitting the game.

5. **Winning Condition:** Detect when a tile with the value 2048 is achieved, signaling the player's victory.

6. **Losing Condition:** Determine when the game is over due to the inability to make valid moves, allowing players to see their final score.

7. **Score Tracking:** Keep track of the player's score based on merged tile values.

8. **Readability:** Use meaningful variable names, appropriate comments, and organized code to ensure code readability and maintainability.

## Implementation Steps

1. **Setting Up the Project:**
   - Create the necessary C files`2048.c`.

2. **Board and Tile Generation:**
   - Define the game board data structure.
   - Implement functions to initialize the board and generate random tiles.

3. **Game Logic:**
   - Develop functions for moving tiles in different directions and merging identical tiles.
   - Implement functions to check for a win or loss condition.

4. **User Input:**
   - Create functions to capture and process user input from the keyboard.
   
5. **Winning and Losing Messages:**
   - Display appropriate messages when the player wins or loses the game.

6. **Score Tracking:**
   - Implement logic to calculate and display the player's score.

7. **Testing and Debugging:**
   - Test the game thoroughly to identify and fix any bugs or logical errors.

## Future Enhancements

While the primary focus of this project is on creating a basic CLI version of the 2048 game, there are several potential future enhancements:

- Implementing a graphical user interface (GUI) version of the game using a library like ncurses.
- Adding animations and visual effects to enhance the user experience.
- Supporting different board sizes and game variants.
- Creating a two-player mode or multiplayer functionality.

## Conclusion

The CLI version of the 2048 game project aims to provide an engaging and entertaining experience for players who enjoy the classic puzzle game. By focusing on core gameplay mechanics and user interaction, this project will serve as an educational opportunity to learn about game development and programming in C.
