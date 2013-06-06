#ifndef SWAP_H
#define SWAP_H

void swap(int data[], int idx1, int idx2)
{
	int temp = data[idx1];
	data[idx1] = data[idx2];
	data[idx2] = temp;
}

#endif // SWAP_H
