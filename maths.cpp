#include "Maths.h"

namespace Maths
{
	Line::Line()
	{
	}
	Line::Line(sf::Vector2f point1, sf::Vector2f point2)
	{
		this->point1 = point1;
		this->point2 = point2;
	}

	void Line::setPoints(sf::Vector2f point1, sf::Vector2f point2)
	{
		this->point1 = point1;
		this->point2 = point2;
	}
	sf::Vector2f Line::getPoint1()
	{
		return point1;
	}
	sf::Vector2f Line::getPoint2()
	{
		return point2;
	}

	bool lineIntersect(float p0_x, float p0_y, float p1_x, float p1_y, float p2_x, float p2_y, float p3_x, float p3_y, float *i_x, float *i_y)
	{
		float s1_x = p1_x - p0_x;
		float s1_y = p1_y - p0_y;
		float s2_x = p3_x - p2_x;
		float s2_y = p3_y - p2_y;

		float s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
		float t = (s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);

		if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
		{
			if (i_x != nullptr)
				*i_x = p0_x + (t * s1_x);
			if (i_y != nullptr)
				*i_y = p0_y + (t * s1_y);
			return true;
		}
		return false;
	}
	bool lineIntersect(Line line1, Line line2, float* i_x, float* i_y)
	{
		return lineIntersect(line1.getPoint1().x, line1.getPoint1().y, line1.getPoint2().x, line1.getPoint2().y, line2.getPoint1().x, line2.getPoint1().y, line2.getPoint2().x, line2.getPoint2().y, i_x, i_x);
	}
}