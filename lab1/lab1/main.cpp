#include "ShapeCreator.h"


int main()
{
	std::vector<std::unique_ptr<IShape>> shapes = ReadShapes();
	OutputResult(shapes);
	return 0;
}