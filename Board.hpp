#include <string>
#include "Direction.hpp"
#include <map>
#include <iostream>
#include <climits>

using namespace std;

namespace ariel
{

    class Board
    {
    private:
        unsigned int maxRow, minRow;
        unsigned int maxCol,minCol;
        map<unsigned int, map<unsigned int, char>> board;

      public:
        Board()
        {
            maxRow = 0;
            maxCol = 0;
            minRow = UINT_MAX;
            minCol = UINT_MAX;
        }

        void post(unsigned int row, unsigned int col, Direction direc, string const &str);
        string read(unsigned int row, unsigned int col, Direction dire, unsigned int NumberOfChar);
        void show();
    };
}
