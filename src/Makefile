CC = gcc
CFLAGS = -O2 -march=native -Wall -Wextra -pedantic -ansi
LD = gcc
LDFLAGS = -lm

SCALC = scalc
SCALC_OBJS = scalc.o
TTT = ttt
TTT_OBJS = ttt.o

all: makedirs ${SCALC} ${TTT}

makedirs:
	mkdir -p ../bin
	mkdir -p ../objs

${SCALC}: ${SCALC_OBJS}
	${LD} -o ../bin/$@ $(addprefix ../objs/, $+)

${TTT}: ${TTT_OBJS}
	${LD} -o ../bin/$@ $(addprefix ../objs/, $+)

%.o: %.c
	${CC} ${CFLAGS} -o ../objs/$@ -c $<

clean:
	rm -rf ../objs ../bin *~
