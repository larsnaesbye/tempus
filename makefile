all:
	g++ ./src/astrotime.cpp `pkg-config --cflags --libs gtk+-2.0`
	pdflatex ./docs/manual.tex

