#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <immintrin.h>

#include "benchmark.h"
#include "mem_char.h"
#include "mem_word.h"
#include "mem_256.h"

char *buf1, *buf2;
int buf_size;

// generate a SIMD 256bit vector filled with given unsigned char
__m256i fill(unsigned char c) {
	return _mm256_setr_epi8(c, c, c, c, c, c, c, c,
			c, c, c, c, c, c, c, c,
			c, c, c, c, c, c, c, c,
			c, c, c, c, c, c, c, c);
}

size_t fillword(unsigned char c) {
	unsigned char x[8] = {c, c, c, c, c, c, c, c};
	return *((size_t *) x);
}

// wrapper functions to satisfy type signature
void run_memset_char() {
	memset_char(buf1, 'a', buf_size);
}

void run_memset_word() {
	memset_word(buf1, fillword('b'), buf_size);
}

void run_memset_256() {
	memset_256(buf1, fill('c'), buf_size);
}

void run_memcpy_char() {
	memcpy_char(buf2, buf1, buf_size);
}

void run_memcpy_word() {
	memcpy_word(buf2, buf1, buf_size);
}

void run_memcpy_256() {
	memcpy_256(buf2, buf1, buf_size);
}

int main(int argc, char **argv) {
	int n_run;
	clock_t memcpy_times[3], memset_times[3];

	assert(argc == 3);
	n_run = atoi(argv[1]);
	buf_size = 1 << atoi(argv[2]);
	posix_memalign((void **)&buf1, 32, buf_size);
	posix_memalign((void **)&buf2, 32, buf_size);

	memset_times[0] = benchmark(run_memset_char, n_run);
	memset_times[1] = benchmark(run_memset_word, n_run);
	memset_times[2] = benchmark(run_memset_256, n_run);
	
	memcpy_times[0] = benchmark(run_memcpy_char, n_run);
	memcpy_times[1] = benchmark(run_memcpy_word, n_run);
	memcpy_times[2] = benchmark(run_memset_256, n_run);

	printf("memset: Bytewise = %d | Wordwise = %d | SIMD = %d\n",
			memset_times[0],
			memset_times[1],
			memset_times[2]);
	printf("memcpy: Bytewise = %d | Wordwise = %d | SIMD = %d\n",
			memcpy_times[0],
			memcpy_times[1],
			memcpy_times[2]);

}


