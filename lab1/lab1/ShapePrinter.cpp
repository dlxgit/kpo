#include "ShapePrinter.h"
#include <iostream>
#include <fstream>

void VisitShape(IShape & shape)
{
	std::ofstream outputFile("output.txt", std::fstream::app);
	outputFile << shape.ToString() << std::endl;
}

void CShapePrinter::Visit(CRectangle & shape)
{
	VisitShape(shape);
}

void CShapePrinter::Visit(CTriangle & shape)
{
	VisitShape(shape);
}

void CShapePrinter::Visit(CCircle & shape)
{
	VisitShape(shape);
}