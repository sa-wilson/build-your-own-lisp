CC = cc
CFLAGS = -std=c99 -Wall -g
LDFLAGS = 
FILES = prompt parsing
PLATFORM = $(shell uname)

ifeq ($(findstring Linux,$(PLATFORM)),Linux)
	LDFLAGS += -ledit -lm
endif

ifeq ($(findstring Darwin,$(PLATFORM)),Darwin)
	LDFLAGS += -ledit -lm
endif

.PHONY: default
default: lispy ;

all: $(FILES)

%: %.c mpc/mpc.c
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

