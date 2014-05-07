

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


static void example_cb(char* data, size_t len, void* args = NULL)
{
    static int i = 0;
    printf("%d - data:%s len:%d\n", i++, data, len);
}


int load_file(const char* szfile, void (*cb)(char* data, size_t len, void* args), void* args=NULL)
{
    int fd = open(szfile, O_RDONLY);
    if(fd == -1) {
        fprintf(stderr, "open file %s failed, %d-%s\n", szfile, errno, strerror(errno));
        return -1;
    }
    char buf[10*1024*1024+1] = {0};
    const ssize_t max_len = sizeof(buf)-1;
    int offset = 0;
    while(true) {
        ssize_t r = read(fd, buf+offset, max_len-offset);
        if(r == 0) {
            break;
        } else if (r == -1) {
            fprintf(stderr, "read file %s failed, %d-%s\n", szfile, errno, strerror(errno));
            return -1;
        }
        offset += r;
        *(buf+offset) = '\0';

        char* pbegin = buf + strspn(buf , "\r\n"); 
        char* plineend = NULL;
        while(pbegin < buf+offset) {
            plineend = strpbrk(pbegin, "\r\n");
            if(!plineend) break;

            *plineend++ = '\0';
            if(cb) 
                cb(pbegin, plineend-pbegin-1, args);
            else
                printf("line-len %d\n", plineend-1-pbegin);
            pbegin = plineend  + strspn(plineend  , "\r\n");
        }
        if(pbegin < buf+offset) { // plineend==NULL, 剩余内容，没有换行
            memmove(buf, pbegin, buf+offset-pbegin);
            offset = buf+offset-pbegin;
        } else {
            offset = 0;
        }
    }
    if(offset > 0) {
        char* pbegin = buf + strspn(buf , "\r\n");
        if(pbegin < buf+offset) { // 存在有效数据
            if(cb) 
                cb(buf, offset, args);
            else
                printf("line-len %d\n", offset);
        }
    }

}

