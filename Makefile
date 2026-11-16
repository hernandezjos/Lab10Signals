CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O0 -g

PROGRAMS = signal_handler signal_alarm signal_segfault signal_sigaction recv_signal send_signal

.PHONY: all clean

all: $(PROGRAMS)

signal_handler: signal_handler.c
	$(CC) $(CFLAGS) -o $@ $<

signal_alarm: signal_alarm.c
	$(CC) $(CFLAGS) -o $@ $<

signal_segfault: signal_segfault.c
	$(CC) $(CFLAGS) -o $@ $<

signal_sigaction: signal_sigaction.c
	$(CC) $(CFLAGS) -o $@ $<

recv_signal: recv_signal.c
	$(CC) $(CFLAGS) -o $@ $<

send_signal: send_signal.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAMS) core core.*