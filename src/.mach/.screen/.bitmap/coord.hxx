#pragma once

class coord
{
	public:
		coord (void);
		coord (const coord &/* other*/);
		coord (const noware::nr &/* width*/, const noware::nr &/* height*/);
		
		virtual const coord & operator = (const coord &/* other*/);
		
		noware::nr width;
		noware::nr height;
};
