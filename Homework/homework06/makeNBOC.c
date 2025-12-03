#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

int is_little_endian() {
    unsigned int x = 0x12345678;
    unsigned char *ptr = (unsigned char*)&x;

    if (*ptr == 0x78) {
        printf("Little-endian\n");
        return 1;
    } else if (*ptr == 0x12) {
        printf("Big-endian\n");
        return 0;
    } else {
        printf("Unknown endianness\n");
        return -1;
    }
}

uint32_t makeNBOC(uint32_t x){
  if (is_little_endian()) {
    x = htonl(x);
  }
  return x; 
}
