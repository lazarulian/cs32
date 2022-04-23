// pathExists.cpp - Apurva Shah 705595011

#include <iostream>
#include <string>
#include <cassert>
#include <stack>
#include <queue>

using namespace std;

////////////////////////////////////////////////////////////
/// Coordinate Class
////////////////////////////////////////////////////////////

class Coord
{
public:
    Coord(int rr, int cc) : m_row(rr), m_col(cc) {}
    int r() const { return m_row; }
    int c() const { return m_col; }
private:
    int m_row;
    int m_col;
};

////////////////////////////////////////////////////////////
/// pathExists Function
////////////////////////////////////////////////////////////

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    Coord end_coord = Coord(er, ec);
    stack <Coord> s;
    maze[sr][sc] = '~'; // setting the starting position
    s.push(Coord(sr, sc));
    int counter = 0;

    while(s.empty() != true)
    {
        Coord current = s.top();
        int curr_r = current.r();
        int curr_c = current.c();
        
        if (counter != 13) {
            cerr << "(" << curr_r << ", " << curr_c << ")" << endl;
            counter++;
        }
        
        s.pop();

        // Checking if we are at the end of the maze

        if (curr_r == er && curr_c == ec)
        {
            return true;
        }

        // Making Movements within the Maze

        // Moving West
        if (maze[curr_r][curr_c-1] == '.')
        {
            s.push(Coord(curr_r, curr_c-1));
            maze[curr_r][curr_c-1] = '~';
        }

        // Moving North
        if (maze[curr_r-1][curr_c] == '.')
        {
            s.push(Coord(curr_r-1, curr_c));
            maze[curr_r-1][curr_c] = '~';
        }

        // Moving East

        if (maze[curr_r][curr_c+1] == '.')
        {
            s.push(Coord(curr_r, curr_c+1));
            maze[curr_r][curr_c+1] = '~';
        }

        // Moving South
        if (maze[curr_r+1][curr_c] == '.')
        {
            s.push(Coord(curr_r+1, curr_c));
            maze[curr_r+1][curr_c] = '~';
        }
    } // End While Loop

    return false;
}


int main()
{
    char maze[10][10] = {
        { 'X','X','X','X','X','X','X','X','X','X' },
        { 'X','.','.','.','.','.','.','.','.','X' },
        { 'X','.','X','.','X','X','X','X','.','X' },
        { 'X','.','X','X','.','X','.','X','.','X' },
        { 'X','.','X','X','.','X','.','.','.','X' },
        { 'X','.','X','.','.','.','.','X','X','X' },
        { 'X','.','X','X','X','X','.','X','.','X' },
        { 'X','.','.','.','.','X','X','X','.','X' },
        { 'X','.','X','.','.','X','.','.','.','X' },
        { 'X','X','X','X','X','X','X','X','X','X' }
    };
    
    if (pathExists(maze, 5,6, 8,1))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}
