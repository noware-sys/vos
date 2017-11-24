#pragma once

class x86_64
	//: virtual public noware::serial
{
	public:
		#include ".x86_64/.hxx"
		
		//x86_64 (void);
		//x86_64 (std::string const &/* other*/);
		//virtual ~x86_64 (void);
		
		//virtual x86_64 const & operator = (x86_64 const &/* other*/);
		//virtual std::string const & operator = (std::string const &/* other*/);
		//virtual operator std::string const (void) const;
		
		//#include ".cpu/.x86_64/opr.hxx"
		
		//opr _opr;	// OPeRation
		//opr oprn;	// Optional.
		//dev device;
		
	//	std::map <reg/* key*/, unsigned int/* value*/> _reg;
		
		// evaluate
		//val () const;
		
		//friend class boost::serialization::access;
		//
		//template <typename archive>
		//void serialize (archive &, unsigned int const &/* version*/);
	public:
		// TODO
		// 
		// also inherit
		// these two functions
		// from noware::serial
		// (do not reimplement)
		//virtual std::string const serialize (void) const;
		//virtual bool const deserialize (std::string const &/* serial*/);
		//
		//virtual void dump (void) const;
};
