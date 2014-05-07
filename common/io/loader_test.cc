

#include "loader.h"

/*
> cat a.data
1
2
3
4
5
6
7
8
9
10
11
12
13
*/

static void cb(char* data, size_t len, void* args = NULL)
{
    static int i = 0;
    printf("%d - data:%s len:%d\n", i++, data, len);
}

int main()
{
    const char* szfile = "a.data";
    load_file(szfile, cb, NULL);
}

