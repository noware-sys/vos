#pragma once

/*
#include "screen.hxx"
#include "../serial.hxx"
#include <string>
#include <iostream>
*/

const std::string noware::mach::cmd::grp_dft = "noware::mach::cmd";

noware::mach::cmd::cmd (void)
{
	node.join (/*noware::mach::cmd::*/grp_dft);
}

noware::mach::cmd::~cmd (void)
{
}

const bool noware::mach::cmd::set (const std::string & value)
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

const std::string noware::mach::cmd::get (const char & delimiter)
{
	zmq::msg msg;
	std::map <std::string, std::string> xpr;
	std::string xpr_serial;
	
	xpr ["subject"] = "cin";
	xpr ["delimiter"] = delimiter;
	
	if (!noware::serialize <std::map <std::string, std::string>> (xpr_serial, xpr))
		return "";
	
	msg = xpr_serial;
	return locval (msg);
}

const bool/* success*/ noware::mach::cmd::respond (const zyre_event_t * event, const std::string & event_type, const zmq::msg & msg_request, zmq::msg & msg_response)
{
	std::map <std::string, std::string> request;
	
	if (!noware::deserialize <std::map <std::string, std::string>> (request, std::string (msg_request)))
		return false;
	
	if (request ["subject"] == "cout")
	{
		std::cout << request ["value"];
		msg_response = "1";
		//return true;
		return false;
	}
	else if (request ["subject"] == "cin")
	{
		std::string input;
		
		//std::cout << request ["value"];
		std::getline (std::cin, input, request ["delimiter"] [0]);
		
		msg_response = input;
		return true;
		//return false;
	}
	
	//msg_response = "0";
	return false;
}

const bool/* success*/ noware::mach::cmd::search (zmq::msg & msg_result, const zmq::msg & msg_response)
{
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

const bool/* success*/ noware::mach::cmd::search_local (zmq::msg & msg_response, const zmq::msg & msg_request)
{
	std::map <std::string, std::string> request;
	
	if (!noware::deserialize <std::map <std::string, std::string>> (request, std::string (msg_request)))
		return false;
	
	if (request ["subject"] == "cout")
	{
		std::cout << request ["value"];
		msg_response = "1";
		//return true;
		return false;
	}
	else if (request ["subject"] == "cin")
	{
		std::string input;
		
		//std::cout << request ["value"];
		std::getline (std::cin, input, request ["delimiter"] [0]);
		
		msg_response = input;
		return true;
		//return false;
	}
	
	//msg_response = "0";
	return false;
}
