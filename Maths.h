#ifndef MATHS_H
#define MATHS_H

#include <SFML\System\Vector2.hpp>

namespace Maths
{
	class Line
	{
	private:
		sf::Vector2f point1;
		sf::Vector2f point2;
	public:
		Line();
		Line(sf::Vector2f point1, sf::Vector2f point2);
		void setPoints(sf::Vector2f point1, sf::Vector2f point2);
		sf::Vector2f getPoint1();
		sf::Vector2f getPoint2();
	};

	bool lineIntersect(float p0_x, float p0_y, float p1_x, float p1_y, float p2_x, float p2_y, float p3_x, float p3_y, float *i_x, float *i_y);
	bool lineIntersect(Line line1, Line line2, float *i_x, float *i_y);
}

#endif