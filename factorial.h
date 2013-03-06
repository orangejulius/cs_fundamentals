#ifndef FACTORIAL_H
#define FACTORIAL_H

int factorial(int n)
{
	int result = 1;
	while (n > 1) {
		result *= n--;
	}

	return result;
}

#endif // FACTORIAL_H
