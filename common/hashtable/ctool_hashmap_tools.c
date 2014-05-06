

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ctool_hashmap.h"

int main(int argc, char** argv)
{
    void* hmap = ctool_hashmap_init(1000, 1000, 1000);
    void* buf = ctool_hashmap_buf(hmap, 50);
    memcpy(buf, "aaaa", strlen("aaaa"));
    ctool_hashmap_add(hmap, 0x0000001, buf);

    void* value_buf = ctool_hashmap_get(hmap, 0x0000001, NULL);

    printf("%s\n", (char*)value_buf);

    ctool_hashmap_drop(hmap);
    
}

