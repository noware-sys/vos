#pragma once

#include "dev.hxx"
#include <noware/net/node.cxx>

std::string const noware::smach::dev::grp_dft = "noware::smach::dev";
//const cln::nr noware::pmach::dev::token_size_dft = 16;

bool const noware::smach::dev::start (void)
{
	if (!net::node::start ())
		return false;
	
	if (!_node.join (grp_dft))
		return false;
	
	/*
	if (!node.join (grp_dft + std::string ("::nonfull"))) // Temporary: dynamically find when needed.
		return false;
	*/
	
	return true;
}

bool const/* success*/ noware::smach::dev::respond (zmq::msg &/* response*/, zmq::msg const &/* rx'd*/, zyre_event_t const * const/* (zyre) event*/, std::string const &/* event_type*/, std::string const &/* src*/, net::cast const &/* src_cast*/)
{
	std::cerr << "noware::smach::dev::respond()::called" << std::endl;
	
	return false;
}

/*
std::string const noware::pmach::dev::val (std::string const &)
{
	return "";
}
*/
