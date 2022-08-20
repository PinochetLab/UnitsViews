#pragma once
#include <math.h>

struct Index2D {
	int i;
	int j;

	Index2D(int i, int j) {
		this->i = i;
		this->j = j;
	}

	void Clamp(int N) {
		i = mod(i, N);
		j = mod(j, N);
	}

	static int mod(int n, int d)
	{
		int result = n % d;
		if (sign(result) * sign(d) < 0)
			result += d;
		return result;
	}

	static int sign(int n) {
		if (n > 0) {
			return 1;
		}
		else if (n == 0) {
			return 0;
		}
		else {
			return -1;
		}
	}
};