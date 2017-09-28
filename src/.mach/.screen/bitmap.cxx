#pragma once

#include ".bitmap/.cxx"

noware::mach::screen::bitmap::bitmap (void)
{
	visible = true;
}

const bool noware::mach::screen::bitmap::size (const coord & other)
{
	resolution = other;
	
	return true;
}
