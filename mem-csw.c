#include <fcntl.h>
#include <sys/file.h>
#include <stdio.h>
#include <errno.h>

extern int errno;
int perror(char *);

#define CSW     "/dev/csw"

unsigned int
int main(int argc, char **argv)
{
        int fd;
        unsigned int lr;
        int i;
	
        fd = open(CSW, O_RDWR|O_EXCL, 0);
        if ( fd < 0 ) {
            printf("open failed: ");
		fflush(stdout);
		perror(CSW);
            exit(1);
        }
	
	if ( argc == 2 ) {
		lr = (unsigned int) atoi(argv[1]);
		i = write(fd, &lr, 2);
	} else {	
		i = read(fd, &lr,2);
		printf("%u\n",lr);
	}
	/* return io error , could print this out as well... */
        exit (( i == 2? 0 : -1)) ;
}


