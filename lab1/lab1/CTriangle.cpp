#include "CTriangle.h"
#include "CLineSegment.h"

CTriangle::CTriangle(const Point & firstPoint, const Point & secondPoint, const Point & thirdPoint)
{
	m_firstPoint = firstPoint;
	m_secondPoint = secondPoint;
	m_thirdPoint = thirdPoint;
}

std::string CTriangle::ToString() const
{
	std::pair<int, int> point1 = m_firstPoint;
	std::pair<int, int> point2 = m_secondPoint;
	std::pair<int, int> point3 = m_thirdPoint;

	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) <<
		"triangle <" <<
		point1.first << ", " <<
		point1.second << ">, " << "<" <<
		point2.first << ", " <<
		point2.second << ">, <" <<
		point3.first << ", " <<
		point3.second << ">, S = " <<
		GetArea() << ", P = " <<
		GetPerimeter();
	return ss.str();
}

CLongNumber CTriangle::GetArea() const
{
	std::vector<std::string> strs;
	strs.push_back(boost::lexical_cast<std::string>((m_secondPoint.first * m_firstPoint.second - m_firstPoint.first * m_secondPoint.second)));
	strs.push_back(boost::lexical_cast<std::string>(m_thirdPoint.first * m_secondPoint.second - m_secondPoint.first * m_thirdPoint.second));
	strs.push_back(boost::lexical_cast<std::string>(m_firstPoint.first * m_thirdPoint.second - m_thirdPoint.first * m_firstPoint.second));

	CLongNumber res = CLongNumber("0");
	std::vector<std::string> negative;
	for (size_t i = 0; i < strs.size(); ++i)
	{
		if (strs[i][0] != '-')
		{
			negative.push_back(strs[i]);
		}
		else
		{
			res = res + CLongNumber(strs[i]);
		}
	}
	for (size_t i = 0; i < negative.size(); ++i)
	{
		res = res - CLongNumber(negative[i]);
	}

	return res / CLongNumber("2");
}

CLongNumber CTriangle::GetPerimeter() const
{
	return 
		CLongNumber(boost::lexical_cast<std::string>(CLineSegment(m_firstPoint, m_secondPoint).GetLength())) + 
		CLongNumber(boost::lexical_cast<std::string>(CLineSegment(m_secondPoint, m_thirdPoint).GetLength())) +
		CLongNumber(boost::lexical_cast<std::string>(CLineSegment(m_firstPoint, m_thirdPoint).GetLength()));
}

std::array<Point, 3> CTriangle::GetPoints() const
{
	return{ m_firstPoint, m_secondPoint, m_thirdPoint };
}

void CVisitableShape::Accept(IShapeVisitor & visitor)
{
	//visitor.Visit(*this);
}