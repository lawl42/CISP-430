#include "stdio.h"

#define SIZE 10
#define DEBUG

// GLOBAL DATA
// a cell type containing a row and column position
// and the compass direction most recently moved
struct cell_type {
	int row;
	int col;
	int dir;
	// the most recent compass direction, 'n', 's', 'e', 'w', 0
};
typedef struct cell_type Cell;
Cell sol[SIZE*SIZE];

// the solution represented as an array of Cells
int maze[SIZE][SIZE] = {
	// the maze
	1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,1,
	1,1,1,1,0,1,1,1,0,1,
	1,0,1,1,0,1,0,1,0,1,
	1,0,0,1,0,1,1,1,0,1,
	1,1,0,1,0,1,1,1,0,1,
	1,0,0,1,0,1,0,1,0,1,
	1,0,1,1,0,1,1,1,0,1,
	1,0,0,1,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1
};

// FUNCTION PROTOTYPES
void build(int);
void printSolution(int);
int cellOk(int);
int getNextCell(int);

void main()
{
	// set starting position and direction
	sol[0].row = 1;
	sol[0].col = 1;
	sol[0].dir = 0;
	// start recursive solution
	build(0);
}

/*
A recursive function to determine a path through the maze.
Called for each cell in the solution array.  Finds the next
valid cell to move to, then calls itself for the next cell.
Inside the function, all possible moves for the current cell
are tried before the function returns.
*/
void build(int n)
{
	// *** YOU WRITE THIS FUNCTION ***
	if (getNextCell(n) == 0)
		return;

	while (sol[n].row != 8 || sol[n].col != 8)
	{
		if (cellOk(n))
		{
			if (sol[n + 1].row == 8 && sol[n + 1].col == 8) {
				printSolution(n);
				return;
			}
			else
				build(n + 1);
		}
		else
		{
			build(n);
		}
	}

	// a handy debug function
#ifdef DEBUG
	printf("Iteration: %d\tAt: (%d, %d)\t Trying : (%d, %d)\n", n, sol[n].row, sol[n].col, sol[n + 1].row, sol[n + 1].col);
#endif
	
}

/*
Outputs the current solution array.
*/
void printSolution(int n)
{
	int i;
	printf("\nA solution was found at :\n");
	for (i = 0; i <= n; i++)
		printf("(%d, %d) ", sol[i].row, sol[i].col);
	printf("\n\n");
}

/*
Determines the next cel to try.  Increments the position
of the next cell and increments the direction of current cell.
Directions are tried in the order east, south, west, north.
*/
int getNextCell(int n)
{
	// set initial position and direction for the next cell
	sol[n + 1].row = sol[n].row;
	sol[n + 1].col = sol[n].col;
	sol[n + 1].dir = 0;
	// try all positions; east, south, west, north
	// increment direction of current cell
	// increment postion of next cell
	switch (sol[n].dir) {
	case 0:
		sol[n].dir = 'e';
		sol[n + 1].col++;
		return 1;
	case 'e':
		sol[n].dir = 's';
		sol[n + 1].row++;
		return 1;
	case 's':
		sol[n].dir = 'w';
		sol[n + 1].col--;
		return 1;
	case 'w':
		sol[n].dir = 'n';
		sol[n + 1].row--;
		return 1;
	case 'n':
		return 0;
		// all directions have been tried
	}
	return 0;
	// make compiler happy
}

/*
Checks if a cell is a valid move.  Invalid moves are cells
that are blocked with a wall, or with a cell that is
part or the present
path.
*/
int cellOk(int n)
{
	int i;
	// check if cell is a border cell
	if (maze[sol[n + 1].row][sol[n + 1].col])
		return 0;
	// check if we are attempting to cross our own path
	for (i = 0; i<n; i++)
		// if where we want to go is somewhere we've been...
		if (sol[n + 1].row == sol[i].row && sol[n + 1].col == sol[i].col)
			return 0;
	return 1;
}