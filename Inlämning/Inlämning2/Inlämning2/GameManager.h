#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

void initializeGame();
void manage();
gameState setState(gameState state);
gameState getCurrentState();
void drawMainMenu();
void handleGameInput();
void exitGame();

#endif //!GAMEMANAGER