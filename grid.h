#include <stdlib.h>

int grid_sum(int *grid, int x, int y, int x1, int y1, int x2, int y2)
{
	int sum = 0;
	int i, j;
	for (i = x1; i <= x2; i++) {
		for (j = y1; j <= y2; j++) {
			sum += grid[j*x + i];
		}
	}
	return sum;
}
