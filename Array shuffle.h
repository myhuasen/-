#include <time.h>
namespace hh {
	template <typename T>
	void roll(T y, int x)
	{
		srand(time(NULL));
		int i = x, j;
		T tmp;
		if (x == 0)
			return;
		while (--i)
		{
			j = rand() % (i + 1);
			tmp = y[j];
			y[j] = y[i];
			y[i] = tmp;
		}
	}
}