#pragma once

noware::mach::screen::bitmap::coord::coord (void)
{
	width = 0;
	height = 0;
}

noware::mach::screen::bitmap::coord::coord (const coord & other)
{
	width = other.width;
	height = other.height;
}

noware::mach::screen::bitmap::coord::coord (const noware::nr & w, const noware::nr & h)
{
	width = w;
	height = h;
}

const coord & noware::mach::screen::bitmap::coord::operator = (const coord & other)
{
	width = other.width;
	height = other.height;
	
	return *this;
}
