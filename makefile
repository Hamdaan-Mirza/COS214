
all: TestingMain

TestingMain: Canvas.cpp ExportCanvas.cpp PNGExporter.cpp PDFExporter.cpp  Memento.cpp  CareTaker.cpp Shape.cpp Rectangle.cpp Square.cpp Textbox.cpp ShapeFactory.cpp RectangleFactory.cpp SquareFactory.cpp TextboxFactory.cpp
	g++ -o TestingMain TestingMain.cpp Canvas.cpp ExportCanvas.cpp PNGExporter.cpp PDFExporter.cpp CareTaker.cpp Memento.cpp Shape.cpp Rectangle.cpp Square.cpp Textbox.cpp ShapeFactory.cpp RectangleFactory.cpp SquareFactory.cpp TextboxFactory.cpp -std=c++11

clean: 
	rm -f TestingMain

run: TestingMain
	./TestingMain