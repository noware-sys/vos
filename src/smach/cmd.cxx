#pragma once

#include "cmd.hxx"
#include "dev.cxx"
//#include "../serial.hxx"
#include <string>
#include <iostream>
#include <cln/nr.hxx>

std::string const noware::smach::cmd::grp_dft = "noware::smach::cmd";

noware::smach::cmd::cmd (void)
{
	//node.join (/*noware::mach::cmd::*/grp_dft);
}

noware::smach::cmd::~cmd (void)
{
}

bool const noware::smach::cmd::start (void)
{
	if (!dev::start ())
		return false;
	
	if (!_node.join (grp_dft))
		return false;
	
	return true;
}

const bool noware::smach::cmd::set (const std::string & value)
{
	zmq::msg msg;
	std::map <std::string, std::string> xpr;
	std::string xpr_serial;
	
	xpr ["subject"] = "cout";
	xpr ["value"] = value;
	
	if (!noware::serialize <std::map <std::string, std::string>> (xpr_serial, xpr))
		return false;
	
	msg = xpr_serial;
	return multival (msg, grp_dft) == "1";
}

const std::string noware::smach::cmd::get (const char & delimiter)
{
	/*
	zmq::msg msg;
	std::map <std::string, std::string> xpr;
	std::string xpr_serial;
	
	xpr ["subject"] = "cin";
	xpr ["delimiter"] = delimiter;
	
	if (!noware::serialize <std::map <std::string, std::string>> (xpr_serial, xpr))
		return "";
	
	msg = xpr_serial;
	return locval (msg);
	*/
	
	std::string input;
	
	if (!cin (input, delimiter))
		return "";
	
	return input;
}

const bool/* success*/ noware::smach::cmd::respond (zmq::msg & msg_response, const zmq::msg & msg_request, const zyre_event_t * event, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/)
{
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cmd::respond()" << std::endl;
	
	std::map <std::string, std::string> request;
	
	if (!noware::deserialize <std::map <std::string, std::string>> (request, std::string (msg_request)))
		return false;
	
	if (request ["subject"] == "cout")
	{
		//std::cout << request ["value"];
		//msg_response = "1";
		if (cout (request ["value"]))
			msg_response = "1";
		else
			msg_response = "0";
		return true;
		//return false;
	}
	else if (request ["subject"] == "cin")
	{
		std::string input;
		
		//std::cout << request ["value"];
		//std::getline (std::cin, input, request ["delimiter"] [0]);
		if (!cin (input, request ["delimiter"] [0]))
			return false;
		
		msg_response = input;
		return true;
		//return false;
	}
	
	//msg_response = "0";
	return false;
}

const bool/* success*/ noware::smach::cmd::search (zmq::msg & msg_result, const zmq::msg & msg_response, const cln::nr &/* total, expected resonses count*/, const cln::nr &/* current count of peers who responded (so far)*/, const std::string &/* src*/, const net::cast &/* src_cast*/)// const
{
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cmd::search()" << std::endl;
	
	std::map <std::string, std::string> response;
	
	if (!noware::deserialize <std::map <std::string, std::string>> (response, std::string (msg_response)))
		return false;
	
	if (response ["subject"] == "cout")
	{
		//std::cout << request ["value"];
		msg_result = response ["value"];
		//return msg_result == "1";
		return false;
	}
	else if (response ["subject"] == "cin")
	{
		//std::cout << request ["value"];
		msg_result = response ["value"];
		//return msg_result == "1";
		return true;
	}
	
	//msg_result = "0";
	return false;
}

//const bool/* success*/ noware::mach::cmd::search_local (zmq::msg & msg_response, const zmq::msg & msg_request)
const bool/* success*/ noware::smach::cmd::search_local (zmq::msg & msg_response, const zmq::msg & msg_request, const std::string &/* src*/, const net::cast &/* src_cast*/)// const
{
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cmd::search_local()" << std::endl;
	
	std::map <std::string, std::string> request;
	
	if (!noware::deserialize <std::map <std::string, std::string>> (request, std::string (msg_request)))
		return false;
	
	if (request ["subject"] == "cout")
	{
		//std::cout << request ["value"];
		if (cout (request ["value"]))
			msg_response = "1";
		else
			msg_response = "0";
		//return true;
		return false;
	}
	else if (request ["subject"] == "cin")
	{
		std::string input;
		
		//std::getline (std::cin, input, request ["delimiter"] [0]);
		if (!cin (input, request ["delimiter"] [0]))
			return false;
		
		msg_response = input;
		return true;
		//return false;
	}
	
	//msg_response = "0";
	return false;
}

bool const noware::smach::cmd::cout (std::string const & value)
{
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cmd::cout[" << value << "]" << std::endl;
	
	cln::nr out_val;
	
	out_val = value;
	
	std::cout << (char) (out_val.operator unsigned long int const ());
	//std::cout << value;
	
	/*
	// space
	if (value == "\\_")
	{
		//std::cout << "TWO";
		std::cout << ' ';
	}
	*/
	/*
	// back slash
	else if (inst.arg ["2"] == "\\")
	{
		//std::cout << "TWO";
		std::cout << ;
	}
	*/
	// new line
	/*else */
	
	/*
	if (value == "\\n")
	{
		//std::cout << "TWO";
		std::cout << std::endl;
	}
	else
	{
		//std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::cout[" << inst.arg ["2"] << "]" << std::endl;
		std::cout << value;
	}
	*/
	
	return true;
}

bool const noware::smach::cmd::cin (std::string & val, char const & delim)
{
	std::getline (std::cin, val, delim);
	
	return true;
}
