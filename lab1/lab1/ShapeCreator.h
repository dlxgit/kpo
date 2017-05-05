#pragma once

#pragma once
#include <boost/algorithm/algorithm.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/math/constants/constants.hpp>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include "IShape.h"
#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"

std::unique_ptr<IShape> AddNewShape(const std::vector<std::string> & inputParts);

std::vector<std::unique_ptr<IShape>> ReadShapes();

void OutputResult(const std::vector<std::unique_ptr<IShape>> & shapes);