#pragma once

//   left
//   | 
//   v 
//   ********************
//   *                  *
//   *                  *
//   *                  *
//   ********************
//                      ^
//                      |
//                     right

class Rectangle
{

public:
	int left_x;
	int left_y;
	int right_x;
	int right_y;
	Rectangle(int lx, int ly, int rx, int ry)
		:left_x(lx)
		,left_y(ly)
		,right_x(rx)
		,right_y(ry)
	{
	}

	int get_height() const
	{
		return left_y - right_y;
	}
	int get_width() const
	{
		return left_x - right_x;
	}

	

};