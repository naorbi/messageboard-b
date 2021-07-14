#include "Board.hpp"
#include <string>
#include <iomanip>
#include <limits.h>
#include <iostream>
#include <map>
#include <climits>

using namespace std;
using namespace ariel;

void Board::post(unsigned int row, unsigned int col, Direction direc, string const &sstr)
{
    theMaxRow = max(theMaxRow, row);
    theMaxCol = max(theMaxCol, col);
    theMinRow = min(theMinRow, row);
    theMinCol = min(theMinCol, col);
    if (direc == Direction::Horizontal)
    {
        unsigned int i = row;
        for (unsigned int j = 0; j < str.length(); j++)
        {
            board[row][col] = str.at(j);
            col++;
        }
    }
    if (direc == Direction::Vertical)
    {
        unsigned int j = col;

        for (unsigned int i = 0; i < str.length(); i++)
        {
            board[row][col] = str.at(i);
            row++;
        }
    }
}
string Board::read(unsigned int row, unsigned int col, Direction dire, unsigned int NumberOfChar)
{

    string answer;
    if (dire == Direction::Horizontal)
    { //line
        unsigned int i = row;
        unsigned int j = col;

        for (unsigned int ch = 0; ch < NumberOfChar; ch++)
        {
            char help = board[i][j];
            if (help == 0)
            {
                answer += '_';
            }
            else
            {
                answer += (help);
            }
            j++;
        }
    }
    else if (dire == Direction::Vertical)
    {
        unsigned int i = row;
        unsigned int j = col;
        for (unsigned int ch = 0; ch < NumberOfChar; ch++)
        {
            char help2 = board[i][j];
            if (help2 == 0)
            {
                answer += '_';
            }
            else
            {
                answer += (help2);
            }
            i++;
        }
    }

    return answer;
}

void Board::show()
{
    unsigned long j = theMinCol;
    for (unsigned long i = theMinRow; i < theMaxRow + 1; i++)
    {
        cout << i << ":";
        cout << read(i, j, Direction::Horizontal, theMaxCol + 25);
        cout << endl;
    }
}
