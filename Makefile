SEPFLAG= -i
CFLAGS= -O
SRCS= mem-csw.c
OBJS= mem-csw.o

all: mem-csw

mem-csw: ${OBJS}
	${CC} ${CFLAGS} ${SEPFLAG} -o $@ ${OBJS}

clean:
	rm -f ${OBJS}
