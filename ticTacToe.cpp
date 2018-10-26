#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Player {
  char symbol;
  string name;
};

struct Location {
  int colNum;
  int rowNum;
};

struct Result {
  string moveResult;
  string gameStatus;
};

class TicTacToe {

public:
  TicTacToe();
  TicTacToe(int boardSize, Player player1, Player player2);

  int getBoardSize();
  Player getplayer1();
  Player getplayer2();
  Result MakeMove(Player player, Location location);
  void resetGame();

private:
  int boardSize;
  Player p1;
  Player p2;
  Result result;
  int moves = 0;
  bool turn = 0;

  std::set<string> playerLocation;
  std::map<int, int> possiblePlayer1;
  std::map<int, int> possiblePlayer2;
  std::vector<int> diagonal = {0};

  void setBoardSize(int gameBoardSize);
  void setPlayers(Player player1, Player player2);
  void setLocation(int rowNum, int colNum);
  bool markLocation(string playerLoc);
  bool possibilityPlayer1(int num, int rowCol);
  bool possibilityPlayer2(int num, int rowCol);
  bool diagonalMove(Player player, Location location);
};

TicTacToe ::TicTacToe() {
  setBoardSize(3);
  this->p1.symbol = 'X';
  this->p1.name = "DefaultPlayer1";
  this->p2.symbol = 'O';
  this->p2.name = "DefaultPlayer2";
}

TicTacToe ::TicTacToe(int boardSize, Player player1, Player player2) {
  setBoardSize(boardSize);
  setPlayers(player1, player2);
}

void TicTacToe ::setBoardSize(int gameBoardSize) {
  if (gameBoardSize > 0) {
    this->boardSize = gameBoardSize;
  } else {
    this->boardSize = 3;
    cout << "Invalid Boardsize; Setting Boardsize = 3" << endl;
  }
}
void TicTacToe ::setPlayers(Player player1, Player player2) {
  if ((toupper(player1.symbol) == 'O' && toupper(player2.symbol) == 'X') ||
      (toupper(player1.symbol) == 'X' && toupper(player2.symbol) == 'O')) {
    this->p1.symbol = toupper(player1.symbol);
    this->p2.symbol = toupper(player2.symbol);
    this->p1.name = player1.name;
    this->p2.name = player2.name;
  } else {
    this->p1.symbol = 'X';
    this->p1.name = "DefaultPlayer1";

    this->p2.symbol = 'O';
    this->p2.name = "DefaultPlayer2";

    cout << "Invalid Player Settings; Default settings applied" << endl;
  }
}

bool TicTacToe ::possibilityPlayer1(int num, int rowCol) {
  std::map<int, int>::iterator it;
  if (rowCol == 1) {
    int rowno = num + this->boardSize + 1;

    it = possiblePlayer1.find(rowno);
    if (it != possiblePlayer1.end()) {
      it->second = (it->second) + 1;
      if (it->second == this->boardSize) {
        return true;
      }
    } else {
      possiblePlayer1.insert(std::pair<int, int>(rowno, 1));
    }
  } else if (rowCol == 2) {
    it = possiblePlayer1.find(num);
    if (it != possiblePlayer1.end()) {
      it->second = (it->second) + 1;
      if (it->second == this->boardSize) {
        return true;
      }
    } else {
      possiblePlayer1.insert(std::pair<int, int>(num, 1));
    }
  }
  return false;
}

bool TicTacToe ::possibilityPlayer2(int num, int rowCol) {
  std::map<int, int>::iterator it;
  if (rowCol == 1) {
    int rowno = num + this->boardSize + 1;
    it = possiblePlayer2.find(rowno);
    if (it != possiblePlayer2.end()) {
      it->second = (it->second) + 1;
      if (it->second == this->boardSize) {
        return true;
      }
    } else {
      possiblePlayer2.insert(std::pair<int, int>(rowno, 1));
    }
  } else if (rowCol == 2) {
    it = possiblePlayer2.find(num);
    if (it != possiblePlayer2.end()) {
      it->second = (it->second) + 1;
      if (it->second == this->boardSize) {
        return true;
      }
    } else {
      possiblePlayer2.insert(std::pair<int, int>(num, 1));
    }
  }
  return false;
}

void TicTacToe ::resetGame() {
  possiblePlayer1.clear();
  possiblePlayer2.clear();
  playerLocation.clear();
  this->boardSize = 3;

  this->p1.symbol = 'X';
  this->p1.name = "DefaultPlayer1";

  this->p2.symbol = 'O';
  this->p2.name = "DefaultPlayer2";
}

bool TicTacToe ::markLocation(string playerLoc) {
  if ((playerLocation.find(playerLoc) != playerLocation.end())) {
    return false;
  }
  playerLocation.insert(playerLocation.begin(), playerLoc);
  return true;
}

bool TicTacToe ::diagonalMove(Player player, Location location) {
  if (location.rowNum == location.colNum) {
    if (diagonal[1] == int(toupper(player.symbol))) {
      diagonal[0] = diagonal[0] + 1;
      if (diagonal[0] == this->boardSize) {
        this->result.moveResult = "Excellent Move!";
        this->result.gameStatus = "Player " + player.name + " Won!";
        return true;
      }
    } else {
      diagonal[0] = 1;
      diagonal[1] = int(toupper(player.symbol));
    }
  } else if (location.rowNum + location.colNum == ((this->boardSize) + 1)) {
    if (diagonal[3] == 0) {
      diagonal[3] = int(toupper(player.symbol));
      diagonal[2] = 1;
    }

    if (diagonal[3] == int(toupper(player.symbol))) {
      diagonal[2] = diagonal[2] + 1;
      if (diagonal[2] == this->boardSize) {
        this->result.moveResult = "Excellent Move!";
        this->result.gameStatus = "Player " + player.name + " Won!";
        return true;
      }
    } else {
      diagonal[2] = 1;
      diagonal[3] = int(toupper(player.symbol));
    }
  }
  this->result.moveResult = "Excellent Move!";
  this->result.gameStatus = "Player " + player.name + " Won!";
  return false;
}

Result TicTacToe ::MakeMove(Player player, Location location) {
  if ((location.rowNum <= this->boardSize) &&
      (location.colNum <= this->boardSize)) {

    this->moves = this->moves + 1;

    if ((this->moves) > ((this->boardSize) * (this->boardSize))) {
      this->result.gameStatus = "Game Over! Restart the game!";
      this->result.moveResult = "Invalid Move";
      return this->result;
    }

    if ((location.rowNum + location.colNum == ((this->boardSize) + 1)) ||
        (location.rowNum == location.colNum)) {
      if (diagonalMove(player, location)) {
        return result;
      }
    }

    string playerLoc = "";
    playerLoc =
        (std::to_string(location.rowNum) + std::to_string(location.colNum));

    if (this->turn == 0) {
      int rowno = 0;
      // Player 1's Turn
      if ((toupper(player.symbol) == this->p1.symbol) &&
          (player.name == this->p1.name)) {
        if (markLocation(playerLoc)) {
          this->turn = 1;
          rowno = location.rowNum + 1 + this->boardSize;
          if (possiblePlayer2.find(rowno) != possiblePlayer2.end()) {
            possiblePlayer2.erase(rowno);
          } else {
            if (possibilityPlayer1(location.rowNum, 1)) {
              this->result.moveResult = "Excellent Move!";
              this->result.gameStatus = "Player 1 Won!";
              return this->result;
              // resetGame();
            } else {
              this->result.gameStatus = "Game in Progress";
              this->result.moveResult = "Valid Move";
            }
          }
          if (possiblePlayer2.find(location.colNum) != possiblePlayer2.end()) {
            possiblePlayer2.erase(rowno);
          } else {
            if (possibilityPlayer1(location.colNum, 2)) {
              this->result.moveResult = "Excellent Move!";
              this->result.gameStatus = "Player 1 Won!";
              return this->result;
              // resetGame();
            } else {
              this->result.gameStatus = "Game in Progress";
              this->result.moveResult = "Valid Move";
            }
          }
        } else {
          this->result.gameStatus = "Game in Progress";
          this->result.moveResult = "Location not empty";
          this->turn = 0;
        }
      } else {
        this->result.gameStatus = "Game in Progress";
        this->result.moveResult = "Not your turn, it is Player 1's turn";
      }

    } else if (this->turn == 1) {
      int rowno = 0;

      // Player 2's Turn
      if ((toupper(player.symbol) == this->p2.symbol) &&
          (player.name == this->p2.name)) {
        if (markLocation(playerLoc)) {
          this->turn = 0;
          rowno = location.rowNum + 1 + this->boardSize;
          if (possiblePlayer1.find(rowno) != possiblePlayer1.end()) {
            possiblePlayer1.erase(rowno);
          } else {
            if (possibilityPlayer2(location.rowNum, 1)) {
              this->result.moveResult = "Excellent Move!";
              this->result.gameStatus = "Player 2 Won!";
              return this->result;
              // resetGame();
            } else {
              this->result.gameStatus = "Game in Progress";
              this->result.moveResult = "Valid Move";
            }
          }
          if (possiblePlayer1.find(location.colNum) != possiblePlayer1.end()) {
            possiblePlayer1.erase(rowno);
          } else {
            if (possibilityPlayer2(location.colNum, 2)) {
              this->result.moveResult = "Excellent Move!";
              this->result.gameStatus = "Player 2 Won!";
              return this->result;
              // resetGame();
            } else {
              this->result.gameStatus = "Game in Progress";
              this->result.moveResult = "Valid Move";
            }
          }
        } else {
          this->result.gameStatus = "Game in Progress";
          this->result.moveResult = "Location not empty";
          this->turn = 1;
        }
      } else {
        this->result.gameStatus = "Game in Progress";
        this->result.moveResult = "Not your turn, it is Player 2's turn";
      }
    }
    if ((this->moves) == ((this->boardSize) * (this->boardSize))) {
      if (this->result.gameStatus == "Game in Progress") {
        this->result.gameStatus = "Game Over! This was a tie";
        return this->result;
      }
    }
  } else {
    this->result.moveResult = "Invalid Location";
    this->result.gameStatus = "Game in Progress";
  }
  return this->result;
}
int TicTacToe::getBoardSize() { return this->boardSize; }
Player TicTacToe::getplayer1() { return this->p1; }
Player TicTacToe::getplayer2() { return this->p2; }

int main(int argc, char **argv) {
  std::cout << "Starting test! " << std::endl;

  // TicTacToe game1;
  // cout << "size: " << game1.getBoardSize() << endl;

  Player q1;
  q1.name = "New1";
  q1.symbol = 'X';
  Player q2;
  q2.name = "New2";
  q2.symbol = 'o';
  TicTacToe game2(3, q1, q2);

  Location l1;
  l1.rowNum = 3;
  l1.colNum = 1;

  Location l2;
  l2.rowNum = 2;
  l2.colNum = 2;

  Location l3;
  l3.rowNum = 2;
  l3.colNum = 1;

  Location l4;
  l4.rowNum = 3;
  l4.colNum = 2;

  Location l5;
  l5.rowNum = 1;
  l5.colNum = 1;

  Result result;
  result = game2.MakeMove(game2.getplayer1(), l1);
  if ((result.moveResult == "Excellent Move!") ||
      (result.gameStatus == "Game Over! This was a tie")) {
    cout << "Move Result 1: " << result.moveResult << endl;
    cout << "Game Status 1: " << result.gameStatus << endl;
    game2.resetGame();
  }
  result = game2.MakeMove(game2.getplayer2(), l2);
  if ((result.moveResult == "Excellent Move!") ||
      (result.gameStatus == "Game Over! This was a tie")) {
    cout << "Move Result 2: " << result.moveResult << endl;
    cout << "Game Status 2: " << result.gameStatus << endl;
    game2.resetGame();
  }
  result = game2.MakeMove(game2.getplayer1(), l3);
  if ((result.moveResult == "Excellent Move!") ||
      (result.gameStatus == "Game Over! This was a tie")) {
    cout << "Move Result 3: " << result.moveResult << endl;
    cout << "Game Status 3: " << result.gameStatus << endl;
    game2.resetGame();
  }
  result = game2.MakeMove(game2.getplayer2(), l4);
  if ((result.moveResult == "Excellent Move!") ||
      (result.gameStatus == "Game Over! This was a tie")) {
    cout << "Move Result 4: " << result.moveResult << endl;
    cout << "Game Status 4: " << result.gameStatus << endl;
    game2.resetGame();
  }
  result = game2.MakeMove(game2.getplayer1(), l5);
  if ((result.moveResult == "Excellent Move!") ||
      (result.gameStatus == "Game Over! This was a tie")) {
    cout << "Move Result 5: " << result.moveResult << endl;
    cout << "Game Status 5: " << result.gameStatus << endl;
    game2.resetGame();
  }
  result = game2.MakeMove(game2.getplayer2(), l4);
  if ((result.moveResult == "Excellent Move!") ||
      (result.gameStatus == "Game Over! This was a tie")) {
    cout << "Move Result 6: " << result.moveResult << endl;
    cout << "Game Status 6: " << result.gameStatus << endl;
    game2.resetGame();
  }
  result = game2.MakeMove(game2.getplayer1(), l5);
  if ((result.moveResult == "Excellent Move!") ||
      (result.gameStatus == "Game Over! This was a tie")) {
    cout << "Move Result 7: " << result.moveResult << endl;
    cout << "Game Status 7: " << result.gameStatus << endl;
    game2.resetGame();
  }
  return 0;
}
