#pragma once

#include "dev.hxx"
#include <noware/net/node.cxx>

std::string const noware::vos::srv::dev::grp_dft = "noware::vos::srv::dev";
//const cln::nr noware::pmach::dev::token_size_dft = 16;

bool const noware::vos::srv::dev::start (void)
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

bool const/* success*/ noware::vos::srv::dev::respond (zmq::msg &/* response*/, zmq::msg const &/* rx'd*/, zyre_event_t const * const/* (zyre) event*/, std::string const &/* event_type*/, std::string const &/* src*/, net::cast const &/* src_cast*/)
{
	std::cerr << "noware::vos::srv::dev::respond()::called" << std::endl;
	
	return false;
}

bool const/* success*/ noware::vos::srv::dev::respond_post (zmq::msg const &/* response (read-only)*/, zmq::msg const &/* rx'd*/, zyre_event_t const * const/* (zyre) event*/, std::string const &/* event_type*/, std::string const &/* src*/, noware::net::cast const &/* src_cast*/, bool const &/* result*/)
{
	std::cerr << "noware::vos::srv::dev::respond_post()::called" << std::endl;
	
	return true;
}

/*
std::string const noware::pmach::dev::val (std::string const &)
{
	return "";
}
*/
