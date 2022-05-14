#include <iostream>
using namespace std;

bool symbolValidation(char currentChar) {
    if (currentChar != 'X' && currentChar != 'O' && currentChar != '.') {
        return false;
    }
    return true;
}
char getCurrentChar(int x, int y, string firstLine, string secondLine, string thirdLine) {
    if (y == 0) {
        return firstLine[x];
    }
    if (y == 1) {
        return secondLine[x];
    }
    if (y == 2) {
        return thirdLine[x];
    }
}
int firstDiagonalWinnerResult(string firstLine, string secondLine, string thirdLine) {
    int xWinning = 0;
    int oWinning = 0;
    int lineSumm = 0;
    for (int x = 0; x < 3; x++) {

        if (x == 0) {
            if (firstLine[x] == 'X') lineSumm++;
            else if (firstLine[x] == 'O')lineSumm--;
        }
        if (x == 1) {
            if (secondLine[x] == 'X') lineSumm++;
            else if (secondLine[x] == 'O')lineSumm--;
        }
        if (x == 2) {
            if (thirdLine[x] == 'X') lineSumm++;
            else if (thirdLine[x] == 'O')lineSumm--;
        }
        if (lineSumm == 3) xWinning++;
        if (lineSumm == -3) oWinning++;

    }
    if (xWinning == 1 && oWinning == 0) return 1;
    else if (oWinning == 1 && xWinning == 0) return 2;
    else if (xWinning == 0 && oWinning == 0) return 3;
    else if (xWinning > 1 || oWinning > 1) return 0;
    else return 0;
}
int secondDiagonalWinnerResult(string firstLine, string secondLine, string thirdLine) {
    int xWinning = 0;
    int oWinning = 0;
    int lineSumm = 0;
    for (int x = 0; x < 3; x++) {

        if (x == 0) {
            if (thirdLine[x] == 'X') lineSumm++;
            else if (thirdLine[x] == 'O')lineSumm--;
        }
        if (x == 1) {
            if (secondLine[x] == 'X') lineSumm++;
            else if (secondLine[x] == 'O')lineSumm--;
        }
        if (x == 2) {
            if (firstLine[x] == 'X') lineSumm++;
            else if (firstLine[x] == 'O')lineSumm--;
        }
        if (lineSumm == 3) xWinning++;
        if (lineSumm == -3) oWinning++;

    }
    if (xWinning == 1 && oWinning == 0) return 1;
    else if (oWinning == 1 && xWinning == 0) return 2;
    else if (xWinning == 0 && oWinning == 0) return 3;
    else if (xWinning > 1 || oWinning > 1) return 0;
    else return 0;
}
int сollumnWinnerResult(string firstLine, string secondLine, string thirdLine) {
    int xWinning = 0;
    int oWinning = 0;
    for (int x = 0; x < 3; x++) {
        int lineSumm = 0;

        if (firstLine[x] == 'X') lineSumm++;
        else if (firstLine[x] == 'O')lineSumm--;

        if (secondLine[x] == 'X') lineSumm++;
        else if (secondLine[x] == 'O')lineSumm--;

        if (thirdLine[x] == 'X') lineSumm++;
        else if (thirdLine[x] == 'O')lineSumm--;
        
        if (lineSumm == 3) xWinning++;
        if (lineSumm == -3) oWinning++;
    }
    if (xWinning == 1 && oWinning == 0) return 1;
    else if (oWinning == 1 && xWinning == 0) return 2;
    else if (xWinning == 0 && oWinning == 0) return 3;
    else if (xWinning > 1 || oWinning > 1) return 0;
    else return 0;
}
int lineWinnerResult(string firstLine, string secondLine, string thirdLine) {
    int xWinning = 0;
    int oWinning = 0;
    for (int y = 0; y < 3; y++) {
        int lineSumm = 0;
        for (int x = 0; x < 3; x++) {
            if (y == 0) {
                if (firstLine[x] == 'X') lineSumm++;
                else if (firstLine[x] == 'O')lineSumm--;
            }
            if (y == 1) {
                if (secondLine[x] == 'X') lineSumm++;
                else if (secondLine[x] == 'O')lineSumm--;
            }
            if (y == 2) {
                if (thirdLine[x] == 'X') lineSumm++;
                else if (thirdLine[x] == 'O')lineSumm--;
            }
            if (lineSumm == 3) xWinning++;
            if (lineSumm == -3) oWinning++;
        }
    }
    if (xWinning == 1 && oWinning == 0) return 1;
    else if (oWinning == 1 && xWinning == 0) return 2;
    else if (xWinning == 0 && oWinning == 0) return 3;
    else if (xWinning > 1 || oWinning > 1) return 0;
    else return 0;
}


int gameResults(string firstLine, string secondLine, string thirdLine) {
    bool gameValidation = true;
    int gameResult = 0;
    int xAmmount = 0;
    int oAmmount = 0;
        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                char currentChar = getCurrentChar(x, y, firstLine, secondLine, thirdLine);
                if (currentChar == 'X') xAmmount++;
                if (currentChar == 'O') oAmmount++;
                gameValidation = symbolValidation(currentChar);
                if (gameValidation == false) {
                    return 0;
                }
            }
        }
        if (oAmmount > xAmmount) return 0;

        int lineResult = lineWinnerResult(firstLine, secondLine, thirdLine);
        if (lineResult == 0) return 0;

        int columnResult = сollumnWinnerResult(firstLine, secondLine, thirdLine);
        if (columnResult == 0) return 0;

        int firstDiagonalResult = firstDiagonalWinnerResult(firstLine, secondLine, thirdLine);
        if (firstDiagonalResult == 0) return 0;

        int secondDiagonalResult = secondDiagonalWinnerResult(firstLine, secondLine, thirdLine);
        if (secondDiagonalResult == 0) return 0;

        gameResult = lineResult + columnResult + firstDiagonalResult + secondDiagonalResult - 9;

        if (gameResult == 2 && xAmmount > oAmmount) return 0;
        else if (gameResult == 2) return 2;

        if (gameResult == 1 && oAmmount == xAmmount) return 0;
        else if (gameResult == 1) return 1;

        if (gameResult == 3) return 3;
}

int main()
{
    string firstLine;
    string secondLine;
    string thirdLine;
    for (;;) {
        cout << "Input first line: " << endl;
        cin >> firstLine;
        cout << "Input second line: " << endl;
        cin >> secondLine;
        cout << "Input third line: " << endl;
        cin >> thirdLine;

        if (gameResults(firstLine, secondLine, thirdLine) == 0) {
            cout << "Incorrect";
        }
        if (gameResults(firstLine, secondLine, thirdLine) == 1) {
            cout << "Petya won!";
        }
        if (gameResults(firstLine, secondLine, thirdLine) == 2) {
            cout << "Vasya won!";
        }
        if (gameResults(firstLine, secondLine, thirdLine) == 3) {
            cout << "Nobody";
        }
    }
   
}