#include <assert.h>
#include <stdio.h>

#include "grid.h"

#define GRID_X 10
#define GRID_Y 10

int main()
{
	int grid[GRID_X][GRID_Y];

	int i, j;
	for (i = 0; i < GRID_X; i++) {
		for(j = 0; j < GRID_Y; j++) {
			grid[j][i] = i*j;
			printf("%2d ", i*j);
		}
		printf("\n");
	}

	assert(grid_sum((int*)&grid, GRID_X, GRID_Y, 1, 1, 2, 2) == 9);
	assert(grid_sum_y((int*)&grid, GRID_X, GRID_Y, 1, 1, 2, 2) == 9);
}
