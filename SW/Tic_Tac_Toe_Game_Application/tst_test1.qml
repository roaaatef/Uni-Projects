import QtQuick 2.15
import QtTest 1.0
TestCase {
    name: "testMoveHandling"

    function test_moveHandling() {
        // Setup
        GamePage gamePage;
        gamePage.handleMove(0, 0);
        gamePage.handleMove(0, 1);

        // Act
        int currentPlayer = gamePage.getCurrentPlayer();

        // Assert
        compare(currentPlayer, 2, "After two moves, it should be player 2's turn");
        compare(gamePage.getBoardValue(0, 0), 1, "First move should be marked with 1");
        compare(gamePage.getBoardValue(0, 1), 2, "Second move should be marked with 2");
    }
}
TestCase {
    name: "testAIMove"

    function test_aiMove() {
        // Setup
        GamePage gamePage;
        gamePage.setGameMode("Player1", "AI", "1 Player");

        // Act
        gamePage.handleMove(0, 0); // Player's move

        // Assert
        bool aiMoved = false;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (gamePage.getBoardValue(i, j) == 2) {
                    aiMoved = true;
                }
            }
        }
        compare(aiMoved, true, "AI should make a move after the player's move");
    }
}
TestCase {
    name: "testGameReset"

    function test_gameReset() {
        // Setup
        GamePage gamePage;
        gamePage.handleMove(0, 0);
        gamePage.resetGame();

        // Assert
        bool boardReset = true;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (gamePage.getBoardValue(i, j) != 0) {
                    boardReset = false;
                }
            }
        }
        compare(boardReset, true, "Board should be reset to initial state after resetGame");
    }
}
TestCase {
    name: "testDatabaseConnectionForHistory"

    function test_databaseConnectionForHistory() {
        // Setup
        GamePage gamePage;

        // Act
        bool dbConnected = gamePage.storeGameHistory("Test Result", "Test Moves");

        // Assert
        compare(dbConnected, true, "Database should be connected for storing game history");
    }
}
TestCase {
    name: "testPlayerNamesHandling"

    function test_playerNamesHandling() {
        // Setup
        PlayerNamesPage playerNamesPage;
        playerNamesPage.setGameMode("2 Players");

        // Act
        playerNamesPage.ui->player1LineEdit->setText("Player1");
        playerNamesPage.ui->player2LineEdit->setText("Player2");
        playerNamesPage.handleStartGame();

        // Assert
        compare(playerNamesPage.ui->player1LineEdit->text(), "", "Player1 name should be cleared after starting game");
        compare(playerNamesPage.ui->player2LineEdit->text(), "", "Player2 name should be cleared after starting game");
    }
}


