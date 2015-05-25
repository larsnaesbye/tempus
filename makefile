all:
	g++ ./src/main.cpp `pkg-config --cflags --libs gtk+-2.0` -o tempus
	pdflatex ./docs/manual.tex

