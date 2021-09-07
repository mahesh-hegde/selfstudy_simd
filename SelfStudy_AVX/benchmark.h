#include <time.h>

clock_t benchmark(void (*f) (void), int ntimes) {
	clock_t begin = clock(), end;
	for (int i = 0; i < ntimes; i++) {
		f();
	}
	end = clock();
	return end - begin;
}

