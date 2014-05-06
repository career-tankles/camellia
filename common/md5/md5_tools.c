

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "md5.h"

int main(int argc, char** argv)
{
    char* inString = argv[1];
    size_t inLen = strlen(inString);

    unsigned char md5pword[16];
    unsigned char hex_digest[32] = {0};

    md5_state_t md5state;
    md5_init( &md5state );
    md5_append( &md5state, (unsigned char *)inString, inLen);
    md5_finish( &md5state, md5pword );
    md5_to_hex(md5pword, hex_digest);
    printf("%s\n", hex_digest);

    //
    md5_digest(hex_digest, (unsigned char *)inString, inLen);
    printf("%s\n", hex_digest);

}
