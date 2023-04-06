#include <iostream>
using namespace std;

int main()
{
    /*We need to make a matrix of 0's and 1 beautiful.
    The matrix is beautiful when 1 is in the center*/

    int m[5][5], x, y, c=0;

    //user fills array m
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++) {
            cin >> m[i][j];
        }
    }
    //get coordinates of 1
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++) {
            if (m[i][j] == 1)
            {
                y = i;
                x = j;
            }
        }
    }

    //swapping columns and counting moves
    int tx = x;
    for (int i = 0; i < 5; i++) {
        //2 is the x-coordinate of the center
        if(tx>2)
        { 
            int t = m[y][tx];
            m[y][tx] = m[y][tx - 1];
            m[y][tx - 1] = t;
            tx--;
            c++;
        }
        else if(tx<2)
        { 
            int t = m[y][tx];
            m[y][tx] = m[y][tx + 1];
            m[y][tx + 1] = t;
            tx++;
            c++;
        }
    }
    //swapping rows and counting moves
    int ty = y;
    for (int i = 0; i < 5; i++) {
        //2 is the y-coordinate of the center
        if (ty > 2)
        {
            int t = m[ty][tx];
            m[ty][tx] = m[ty - 1][tx];
            m[ty - 1][tx] = t;
            ty--;
            c++;
        }
        else if (ty < 2)
        {
            int t = m[ty][tx];
            m[ty][tx] = m[ty + 1][tx];
            m[ty + 1][tx] = t;
            ty++;
            c++;
        }
    }
    //result (minimum numbers of moves needed to make the matrix beautiful)
    cout << c;
    return 0;
}