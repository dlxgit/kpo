#include "ShapeFactory.h"
#include "FileParser.h"
#include "ShapeConverter.h"


int main()
{
	std::vector<std::unique_ptr<IShape>> shapes = CFileParser::ReadShapes();
	CShapeConverter::SaveToFile(shapes);
	return 0;
}