#include <stdio.h>
#include <stdint.h>
// #include <arpa/inet.h>
// changed to winsock2.h for windows
#include <winsock2.h>

int is_little_endian() {
    unsigned int x = 0x12345678;
    unsigned char *ptr = (unsigned char*)&x;

    if (*ptr == 0x78) {
        return 1;
    } else if (*ptr == 0x12) {
        return 0;
    } else {
        return -1;
    }
}

uint32_t makeNBOC(uint32_t x){
  if (is_little_endian()) {
    x = htonl(x);
  }
  return x;
}
