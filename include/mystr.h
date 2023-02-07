

typedef unsigned int size_t;

size_t strlen(const char *str);

void *memchr(const void *str, int c, size_t n);

int memcmp(const void *str1, const void *str2, size_t n);

void *memcpy(void *dest, const void *src, size_t n);

void *memmove(void *str1, const void *str2, size_t n);

void *memset(void *str, int c, size_t n);

char *strcat(char *dest, const char *src);