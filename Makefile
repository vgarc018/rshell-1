CFLAGS = -Werror -Wall -pedantic -ansi

all:
	if[ ! -d bin] then mkdir bin; fi
		g++ $(CLFAGS) src/rshell.cpp -0 bin/rshell

rshell:
	if[! -d bin] thenmkdir bin; fi
		g++ $(CFLAGS) src/rshell.cpp -0 bin/rshell

