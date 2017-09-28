#pragma once

class pixel
{
	public:
		pixel (void);
		pixel (const pixel &/* other*/);
		pixel (const noware::nr &/* red*/, const noware::nr &/* green*/, const noware::nr &/* blue*/);
		
		virtual const pixel & operator = (const pixel &/* other*/);
		
		noware::nr red;
		noware::nr green;
		noware::nr blue;
};
