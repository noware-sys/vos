#pragma once

#include "dev.hxx"
//#include "../var.cxx"
//#include "../net/node.cxx"
//#include "../net/cast.hxx"
//#include <string>
//#include <zmq/msg.cxx>
//#include <zyre.h>
//#include <zyre.cxx>
#include <noware/net/node.cxx>
//#include <cln/nr.cxx>

std::string const noware::vos::man::dev::grp_dft = "noware::vos::man::dev";
//cln::nr const noware::vos::man::dev::token_size_dft = 16;

noware::vos::man::dev::dev (void)
{
	_node.sync = false;
}

bool const noware::vos::man::dev::start (void)
{
	if (!net::node::start ())
		return false;
	
	if (!_node.join (grp_dft))
		return false;
	
	return true;
}

bool const/* success*/ noware::vos::man::dev::respond (zmq::msg &/* response*/, zmq::msg const &/* rx'd*/, zyre_event_t const * const/* (zyre) event*/, std::string const &/* event_type*/, std::string const &/* src*/, net::cast const &/* src_cast*/)
{
	std::cerr << "noware::vos::man::dev::respond()::called" << std::endl;
	
	return false;
}

bool const/* success*/ noware::vos::man::dev::respond_post (zmq::msg const &/* response (read-only)*/, zmq::msg const &/* rx'd*/, zyre_event_t const * const/* (zyre) event*/, std::string const &/* event_type*/, std::string const &/* src*/, net::cast const &/* src_cast*/, bool const &/* result*/)
{
	std::cerr << "noware::vos::man::dev::respond_post()::called" << std::endl;
	
	return true;
}

bool const/* success*/ noware::vos::man::dev::search_remote (zmq::msg const &/* result*/, zmq::msg const &/* message/expression*/, cln::nr const &/* total, expected resonses count*/, cln::nr const &/* current count of peers who responded (so far)*/, std::string const &/* src*/, net::cast const &/* src_cast*/)// const
{
	std::cerr << "noware::vos::man::dev::search()::called" << std::endl;
	
	return false;
}
