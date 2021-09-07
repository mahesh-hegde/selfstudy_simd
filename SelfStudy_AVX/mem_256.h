#include <x86intrin.h>
#include <stdint.h>

const int64_t all_ones = 0xFFFFFFFFFFFFFFFF;

void memcpy_256(void *dest, void *src, size_t n) {
	__m256i *d = dest, *s = src;
	size_t i;
	// For benchmark purposes, assume everything is aligned
	// We are passing memory allocated with posix_memalign
	n >>= 5;
	for (i = 0; i != n; i++) {
		_mm256_store_si256(&d[i], _mm256_load_si256(&s[i]));
	}
}

void memset_256(void *dest, __m256i c, size_t n) {
	__m256i *d = dest;
	size_t i;
	n >>= 5;
	for(i = 0; i != n; i++) {
		_mm256_storeu_si256(&d[i], c);
	}
}

