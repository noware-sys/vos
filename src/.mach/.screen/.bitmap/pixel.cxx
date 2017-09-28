#pragma once

noware::mach::screen::bitmap::pixel::pixel (void)
{
	red = 0;
	green = 0;
	blue = 0;
}

noware::mach::screen::bitmap::pixel::pixel (const pixel & other)
{
	red = other.red;
	green = other.green;
	blue = other.blue;
}

noware::mach::screen::bitmap::pixel::pixel (const noware::nr & r, const noware::nr & g, const noware::nr & b)
{
	red = r;
	green = g;
	blue = b;
}

const pixel & noware::mach::screen::bitmap::pixel::operator = (const pixel & other)
{
	red = other.red;
	green = other.green;
	blue = other.blue;
	
	return *this;
}
