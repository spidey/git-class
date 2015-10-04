CC = gcc
CFLAGS = -O2 -march=native -Wall -Wextra -pedantic -ansi
LD = gcc
LDFLAGS = -lm

SCALC = scalc
SCALC_OBJS = scalc.o
TTT = ttt
TTT_OBJS = ttt.o

all: ${SCALC} ${TTT}

${SCALC}: ${SCALC_OBJS}
	${LD} -o $@ $+

${TTT}: ${TTT_OBJS}
	${LD} -o $@ $+

%.o: %.c
	${CC} ${CFLAGS} -o $@ -c $<

clean:
	rm -f ${SCALC} ${SCALC_OBJS} ${TTT} ${TTT_OBJS} *~
