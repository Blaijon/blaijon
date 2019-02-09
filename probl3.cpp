#include <iostream>
#include <cstdlib>
using namespace std;
void setupRow();
void printRow();
void updateRow();
int findNextCellState(int left_neighbor, int cell, int right_neighbor);
const int WIDTH = 80;
int row[WIDTH];
int i = 0;
int temp[WIDTH];
int main()
{
setupRow();
printRow();
for (int i = 0; i < 100; i++)
{
updateRow();
printRow();
}
return 0;
}
// The setupRow function creates an initial state for the cellular autonoma
void setupRow()
{
for(i = 0; i < 80; ++i)
{
if(i != 39)
row[i] = 0;
if(i == 39)
row[i] = 1;
}
}

void printRow()
{
for(i = 0; i < 80; ++i)
{
if(row[i] == 0)
{
cout << " ";
}
if(row[i] == 1)
{
cout << "*";
}
}
}
// The updateRow function updates the contents of the row after calculating
// the next states using the findNextCellState function
void updateRow()
{
temp[WIDTH] = findNextCellState(0, row[0], row[1]);
for(i = 0; i < 80; ++i)
{
temp[i] = findNextCellState(row[i-1], row[0], row[i+1]);
row[i] = temp[i];
}
}

int findNextCellState(int left_neighbor, int cell, int right_neighbor)
{
if (0 == cell)
{
if (1 == (left_neighbor + right_neighbor))
{
return 1;
}
else
{
return 0;
}
}
else
{
if (1 == left_neighbor + right_neighbor)
{
return 0;
}
else
{
return 1;
}
}
}v
