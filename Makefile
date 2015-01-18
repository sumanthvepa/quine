
.PHONY: all clean

all: quine

reproduce: quine.cc
	g++ -I /opt/local/include -g3 -o quine quine.cc

clean:
	rm -f quine
