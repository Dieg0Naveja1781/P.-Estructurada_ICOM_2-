#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

const int n = 2;
#include "salatorre.cpp"

int main()
{
    srand((unsigned)time(NULL));
    int mat[n][n];
    //mat[n][n] = {{10, 2}, {1, 0}};
    printx(mat, n);
    llenar(mat, n);
}