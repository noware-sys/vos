#pragma once

class bitmap
{
	public:
		#include ".bitmap/.hxx"
		
		bitmap (void);
		//virtual ~bitmap (void);
		
		// get the current value
		//virtual const dimension/* current value*/ size (void) const;
		// set a new value
		virtual const bool size (const coord &/* new value*/);
		//virtual const bool size (const noware::nr &/* width*/, const noware::nr &/* height*/);
		
		coord resolution;
		std::map <noware::nr, std::map <noware::nr, pixel>> area;
		bool visible;
};
