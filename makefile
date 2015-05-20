all:
	g++ ./src/astrotime.cpp `pkg-config --cflags --libs gtk+-2.0` -o astrotime
	pdflatex ./docs/manual.tex

