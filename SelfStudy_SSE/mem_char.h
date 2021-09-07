// Character wise memory handling functions

void memcpy_char (void *dest, void *src, size_t n) {
	size_t i;
	char *dest1 = dest, *src1 = src;
	for (i = 0; i < n; i++) {
		dest1[i] = src1[i];
	}
}

void memset_char(void *s, unsigned char c, size_t n) {
	size_t i;
	char *s1 = s;
	for (i = 0; i < n; i++) {
		s1[i] = c;
	}
}

