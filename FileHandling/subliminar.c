#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    int fd = open(argv[1], O_RDWR);
    off_t size = lseek(fd, 0, SEEK_END);
    lseek(fd, size/2, SEEK_SET);
    char* buf = "victor pochettini";

    write(fd, buf, strlen(buf));

    close(fd);
    return 0;
}