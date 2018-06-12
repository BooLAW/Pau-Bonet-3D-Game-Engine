// ----------------------------------------------------
// Point class    -----------
// ----------------------------------------------------

#pragma once

struct iPoint
{
	iPoint(int px, int py)
		 {
		x = px; y = py;
		}
	
		iPoint() {}
	
		~iPoint() {}
	
		int x = -1;
		int y = -1;
};
struct fPoint
{
	fPoint(float px, float py)
	{
		x = px; y = py;
	}

	fPoint() {}

	~fPoint() {}

	float x = -1.0f;
	float y = -1.0f;
};