#include <stdio.h>

int main(void)
{
    unsigned int lastOctet = 200;   // host part of 192.168.1.200
    unsigned int maskOctet = 192;   // last octet of mask 255.255.255.192

    // network = ip AND mask
    printf("Network octet  : %u\n", lastOctet & maskOctet);   // 192

    unsigned int flags = 0;
    flags = flags | 4;          // turn ON bit 2 (value 4)
    printf("Flag 4 set? %u\n", (flags & 4) != 0);

    printf("8 << 1 = %u\n", 8u << 1);   // 16
    printf("8 >> 2 = %u\n", 8u >> 2);   // 2
    return 0;
}
