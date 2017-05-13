#include "ShapeConverter.h"
#include "ShapePrinter.h"
#include <fstream>

void CShapeConverter::SaveToFile(const std::vector<std::unique_ptr<IShape>> & data, const std::string & fileName)
{
	//std::ofstream outputFile("output.txt", std::fstream::app);
	std::remove("output.txt");
	//std::unique_ptr<CShapeVisitor> visitor = std::make_unique<CShapePrinter>();
	
	std::unique_ptr<IShapeVisitor> printer = std::make_unique<CShapePrinter>();
	
	
	for (size_t i = 0; i < data.size(); ++i)
	{
		data[i]->Accept(*printer.get());
		//outputFile << data[i]->ToString() << std::endl;
	}
}