#include <assert.h>
#include <stdio.h>
#include <sys/time.h>

#include "grid.h"

#define GRID_X 10
#define GRID_Y 10

#define GRID2_X 10000
#define GRID2_Y 10000

double microTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec*1000000.0 + tv.tv_usec;
}

int main()
{
	int grid[GRID_X][GRID_Y];

	for (int i = 0; i < GRID_X; i++) {
		for(int j = 0; j < GRID_Y; j++) {
			grid[j][i] = i*j;
			printf("%2d ", i*j);
		}
		printf("\n");
	}

	assert(grid_sum((int*)&grid, GRID_X, GRID_Y, 1, 1, 2, 2) == 9);
	assert(grid_sum_y((int*)&grid, GRID_X, GRID_Y, 1, 1, 2, 2) == 9);

	int* grid2 = malloc(sizeof(int)*GRID2_X*GRID2_Y);

	for (int i = 0; i < GRID2_X; i++) {
		for(int j = 0; j < GRID2_Y; j++) {
			grid2[j*GRID2_X + i] = 0;
		}
	}

	double start = microTime();

	int sum1 = grid_sum(grid2, GRID2_X, GRID2_Y, 0, 0, GRID2_X-1, GRID2_Y-1);

	double mid = microTime();

	int sum2 = grid_sum_y(grid2, GRID2_X, GRID2_Y, 0, 0, GRID2_X-1, GRID2_Y-1);

	double end = microTime();

	printf("%f\n", mid - start);
	printf("%f\n", end - mid);
}
