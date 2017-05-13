//#include "ShapePrinter.h"

#include <iostream>
#include <fstream>
#include "IShape.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CCircle.h"


//void VisitShape(IShape & shape)


void CShapePrinter::Visit(CRectangle & shape)
{
	std::ofstream outputFile("output.txt", std::fstream::app);
	outputFile << shape.ToString() << std::endl;
}

void CShapePrinter::Visit(CTriangle & shape)
{
	std::ofstream outputFile("output.txt", std::fstream::app);
	outputFile << shape.ToString() << std::endl;
}

void CShapePrinter::Visit(CCircle & shape)
{
	std::ofstream outputFile("output.txt", std::fstream::app);
	outputFile << shape.ToString() << std::endl;
}