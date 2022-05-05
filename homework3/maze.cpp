// maze.cpp Apurva Shah 705595011
// exploring inheritance and polymorphisms within c++

// basic declarations

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

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

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    Coord s_loc(sr, sc);
    Coord e_loc(er, ec);

    // if the start equals ending position
    if (s_loc.r() == e_loc.r() && s_loc.c() == e_loc.c())
        return true;
    maze[sr][sc] = '~';
    if (maze[sr - 1][sc] == '.' && pathExists(maze, sr - 1, sc, er, ec)) // north
        return true;
    if (maze[sr + 1][sc] == '.' && pathExists(maze, sr + 1, sc, er, ec)) // south
        return true;
    if (maze[sr][sc + 1] == '.' && pathExists(maze, sr, sc + 1, er, ec)) // east
        return true;
    if (maze[sr][sc - 1] == '.' && pathExists(maze, sr, sc - 1, er, ec)) // west
        return true;
    return false;
}