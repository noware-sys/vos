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

std::string const noware::vos::usr::dev::grp_dft = "noware::vos::usr::dev";
//cln::nr const noware::vmach::dev::token_size_dft = 16;

bool const noware::vos::usr::dev::start (void)
{
	if (!net::node::start ())
		return false;
	
	if (!_node.join (grp_dft))
		return false;
	
	return true;
}

// Short-circuited (triggered by success).
bool const noware::vos::usr::dev::search_remote (zmq::msg const &/* result*/, const zmq::msg &/* message*/, const cln::nr &/* total, expected resonses count*/, const cln::nr &/* current count of peers who responded (so far)*/, const std::string &/* src*/, const net::cast &/* src_cast*/)// const
{
	std::cerr << "noware::vos::usr::dev::search()::called" << std::endl;
	
	return false;
}
