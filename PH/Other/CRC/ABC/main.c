#include <stdio.h>

/* Table of CRCs of all 8-bit messages. */
   unsigned long crc_table[256];
    //unsigned long is 8 bytes, and only non-negative numbers can be stored
    //8-bites 


   /* Flag: has the table been computed? Initially false. */
   int crc_table_computed = 0;
   
   /* Make the table for a fast CRC. */
   void make_crc_table(void)
   {
     unsigned long c;
     int n, k;
   
        //& and operator, value 1 is treated as 1 on 0th position
        //>> is a binary shift to the right, e.g. 2 becomes 1, << makes 2 a four
        //^ xor operator, when equal values are summed using this operator the outcome is 0
        //n < 256 beacuse lookup table is of size 256
     for (n = 0; n < 256; n++) {
       c = (unsigned long) n;
       for (k = 0; k < 8; k++) {
         if (c & 1)
           c = 0xedb88320L ^ (c >> 1);
         else
           c = c >> 1;
       }
       crc_table[n] = c;
     }
     crc_table_computed = 1;
   }
   
   /* Update a running CRC with the bytes buf[0..len-1]--the CRC
      should be initialized to all 1's, and the transmitted value
      is the 1's complement of the final running CRC (see the
      crc() routine below)). */
   
   unsigned long update_crc(unsigned long crc, unsigned char *buf,
                            int len)
   {
     unsigned long c = crc;
     int n;
   
     if (!crc_table_computed)
       make_crc_table();
     for (n = 0; n < len; n++) {
       c = crc_table[(c ^ buf[n]) & 0xff] ^ (c >> 8);
     }
     return c;
   }
   
   /* Return the CRC of the bytes buf[0..len-1]. */
   unsigned long crc(unsigned char *buf, int len)
   {
     return update_crc(0xffffffffL, buf, len) ^ 0xffffffffL;
   }

int main(int argc, char** argv){

    make_crc_table();

    int a = 2;
    int b = 4;
    int c = 8;

    printf("%d\n",a^b);
    printf("%d\n",a^1);
    printf("%d\n",a^a);

    //printf("%d\n",(a>>1));
    //printf("%d\n",(b>>1));
    //printf("%d\n",(c>>1));
//
    //printf("%d\n",(a<<1));
    //printf("%d\n",(b<<1));
    //printf("%d\n",(c<<1));
//
//
    //printf("%d\n",(1&1));
    //printf("%d\n",(0&1));

    return 0;
}