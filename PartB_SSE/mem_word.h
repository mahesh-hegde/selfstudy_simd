// memory functions using 8 bytes at a time

#include <assert.h>

void memcpy_word(void *dest, void *src, size_t n) {
	assert((n & 7) == 0);

	n >>= 3; // divide n by 8
	for (size_t i = 0; i < n; i++) {
		((size_t *)dest)[i] = ((size_t *)src)[i];
	}
}

void memset_word(void *dest, size_t cs, size_t n) {
	assert((n & 7) == 0);

	n >>= 3;
	for (size_t i = 0; i < n; i++) {
		((size_t *)dest)[i] = cs;
	}
}

