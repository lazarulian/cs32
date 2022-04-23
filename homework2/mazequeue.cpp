// mazequeue.cpp Apurva Shah 705595011

#include <iostream>
#include <string>
#include <queue>

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
    // Initial Setup
    queue<Coord> q;
    q.push(Coord(sr, sc));
    maze[sr][sc] = '~';
    int counter = 0;

    while (!q.empty())
    {
        Coord curr = q.front();
        int curr_c = curr.c();
        int curr_r = curr.r();
        if (counter != 12)
        {
            cerr << "(" << curr_r << ", " << curr_c << ")" << endl;
            counter++;
        }
        q.pop();

        if (curr_c == ec && curr_r == er)
        {
            return true;
        }

        // Explore Q
        // Explore West
        if (maze[curr_r][curr_c - 1] == '.')
        {
            q.push(Coord(curr_r, curr_c - 1));
            maze[curr_r][curr_c - 1] = '~';
        }

        // Explore North
        if (maze[curr_r - 1][curr_c] == '.')
        {
            q.push(Coord(curr_r - 1, curr_c));
            maze[curr_r - 1][curr_c] = '~';
        }

        // Explore East

        if (maze[curr_r][curr_c + 1] == '.')
        {
            q.push(Coord(curr_r, curr_c + 1));
            maze[curr_r][curr_c + 1] = '~';
        }

        // Explore South
        if (maze[curr_r + 1][curr_c] == '.')
        {
            q.push(Coord(curr_r + 1, curr_c));
            maze[curr_r + 1][curr_c] = '~';
        }
        continue;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            char n = maze[i][j];
            cout << n;
        } // end col for loop
        cout << endl;
    } // end row for loop

    
    return false;
}

int main()
{
    char maze[10][10] = {
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
        {'X', '.', 'X', '.', '.', '.', 'X', '.', '.', 'X'},
        {'X', '.', 'X', '.', 'X', 'X', 'X', 'X', '.', 'X'},
        {'X', '.', 'X', '.', '.', 'X', '.', 'X', '.', 'X'},
        {'X', '.', 'X', 'X', '.', 'X', '.', '.', '.', 'X'},
        {'X', '.', '.', '.', '.', '.', '.', 'X', 'X', 'X'},
        {'X', '.', 'X', 'X', 'X', 'X', '.', 'X', '.', 'X'},
        {'X', '.', '.', '.', '.', 'X', 'X', 'X', '.', 'X'},
        {'X', '.', 'X', '.', '.', 'X', '.', '.', '.', 'X'},
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}};

    if (pathExists(maze, 5, 6, 8, 1))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}