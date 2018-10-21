#pragma once

class term
	: virtual public noware::serial
{
	public:
		// a[n optional] factor for the value
		unsigned short int factor;
		
		// memory reference
		//bool ref;
		unsigned short int ref;
		
		std::string val;
		
		
		friend class boost::serialization::access;
		
		template <typename archive>
		void serialize (archive &, unsigned int const &/* version*/);
};
