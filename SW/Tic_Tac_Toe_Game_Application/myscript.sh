#!/bin/bash

echo "Running game test cases..."

# Test Case 1: testMoveHandling
echo "Test Case: testMoveHandling"
# Setup
echo "Setup: GamePage gamePage; gamePage.handleMove(0, 0); gamePage.handleMove(0, 1);"
# Act
echo "Act: int currentPlayer = gamePage.getCurrentPlayer();"
# Assert
echo "Assert: compare(currentPlayer, 2, 'After two moves, it should be player 2's turn');"
echo "        compare(gamePage.getBoardValue(0, 0), 1, 'First move should be marked with 1');"
echo "        compare(gamePage.getBoardValue(0, 1), 2, 'Second move should be marked with 2');"
echo

# Test Case 2: testAIMove
echo "Test Case: testAIMove"
# Setup
echo "Setup: GamePage gamePage; gamePage.setGameMode('Player1', 'AI', '1 Player');"
# Act
echo "Act: gamePage.handleMove(0, 0);"
# Assert
echo "Assert: bool aiMoved = false;"
echo "        for (int i = 0; i < 3; ++i) {"
echo "            for (int j = 0; j < 3; ++j) {"
echo "                if (gamePage.getBoardValue(i, j) == 2) { aiMoved = true; }"
echo "            }"
echo "        }"
echo "        compare(aiMoved, true, 'AI should make a move after the player's move');"
echo

# Test Case 3: testGameReset
echo "Test Case: testGameReset"
# Setup
echo "Setup: GamePage gamePage; gamePage.handleMove(0, 0); gamePage.resetGame();"
# Assert
echo "Assert: bool boardReset = true;"
echo "        for (int i = 0; i < 3; ++i) {"
echo "            for (int j = 0; j < 3; ++j) {"
echo "                if (gamePage.getBoardValue(i, j) != 0) { boardReset = false; }"
echo "            }"
echo "        }"
echo "        compare(boardReset, true, 'Board should be reset to initial state after resetGame');"
echo

# Test Case 4: testDatabaseConnectionForHistory
echo "Test Case: testDatabaseConnectionForHistory"
# Setup
echo "Setup: GamePage gamePage;"
# Act
echo "Act: bool dbConnected = gamePage.storeGameHistory('Test Result', 'Test Moves');"
# Assert
echo "Assert: compare(dbConnected, true, 'Database should be connected for storing game history');"
echo

# Test Case 5: testPlayerNamesHandling
echo "Test Case: testPlayerNamesHandling"
# Setup
echo "Setup: PlayerNamesPage playerNamesPage; playerNamesPage.setGameMode('2 Players');"
# Act
echo "Act: playerNamesPage.ui->player1LineEdit->setText('Player1');"
echo "     playerNamesPage.ui->player2LineEdit->setText('Player2');"
echo "     playerNamesPage.handleStartGame();"
# Assert
echo "Assert: compare(playerNamesPage.ui->player1LineEdit->text(), '', 'Player1 name should be cleared after starting game');"
echo "        compare(playerNamesPage.ui->player2LineEdit->text(), '', 'Player2 name should be cleared after starting game');"
echo

echo "All test cases completed."
