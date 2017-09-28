#pragma once

#include ".screen/.cxx"

/*
#include "screen.hxx"
#include "../serial.hxx"
#include <string>
#include <iostream>
*/

const std::string noware::mach::screen::grp_dft = "noware::mach::screen";

noware::mach::screen::screen (void)
{
	node.join (/*noware::mach::screen::*/grp_dft);
}

noware::mach::screen::~screen (void)
{
}

const bool noware::mach::screen::size (const coord & size_new)
{
	zmq::msg msg;
	std::map <std::string, std::string> xpr;
	std::string xpr_serial;
	
	
	xpr ["subject"] = "size";
	
	xpr ["size.width"] = size_new.width;
	xpr ["size.height"] = size_new.height;
	
	
	if (!noware::serialize <std::map <std::string, std::string>> (xpr_serial, xpr))
		return false;
	
	msg = xpr_serial;
	return multival (msg, grp_dft) == "1";
}

const bool noware::mach::screen::set (const coord & location, const pixel & color)
{
	zmq::msg msg;
	std::map <std::string, std::string> xpr;
	std::string xpr_serial;
	
	
	xpr ["subject"] = "set";
	
	xpr ["location.width"] = location.width;
	xpr ["location.height"] = location.height;
	
	xpr ["color.red"] = color.red;
	xpr ["color.green"] = color.green;
	xpr ["color.blue"] = color.blue;
	
	
	if (!noware::serialize <std::map <std::string, std::string>> (xpr_serial, xpr))
		return false;
	
	msg = xpr_serial;
	return multival (msg, grp_dft) == "1";
}

const bool/* success*/ respond (const zyre_event_t * event, const std::string & event_type, const zmq::msg & msg_request, zmq::msg & msg_response)
{
	std::map <std::string, std::string> request;
	
	if (!noware::deserialize <std::map <std::string, std::string>> (request, std::string (msg_request)))
		return false;
	
	if (request ["subject"] == "set")
	{
		//std::cout << request ["value"];
		
		// update the local value
		area.area [noware::nr (request ["location.width"])] [noware::nr (request ["location.height"])] = pixel (noware::nr (request ["color.red"]), noware::nr (request ["color.green"]), noware::nr (request ["color.blue"]));
		
		// update the visual
		// TODO
		
		msg_response = "1";
		return true;
		//return false;
	}
	else if (request ["subject"] == "size")
	{
		if (area.size (coord (noware::nr (request ["size.width"]), noware::nr (request ["size.height"]))))
		{
			msg_response = "1";
			return true;
		}
		else
		{
			msg_response = "0";
			return false;
		}
	}
	
	msg_response = "0";
	return false;
}

const bool/* success*/ search (zmq::msg & msg_result, const zmq::msg & msg_response)
{
	std::map <std::string, std::string> response;
	
	if (!noware::deserialize <std::map <std::string, std::string>> (response, std::string (msg_response)))
		return false;
	
	if (response ["subject"] == "set")
	{
		//std::cout << request ["value"];
		msg_result = response ["value"];
		return msg_result == "1";
		//return false;
	}
	else if (response ["subject"] == "size")
	{
		//std::cout << request ["value"];
		msg_result = response ["value"];
		return msg_result == "1";
		//return false;
	}
	
	msg_result = "0";
	return false;
}

const bool/* success*/ search_local (zmq::msg & msg_response, const zmq::msg & msg_request)
{
	std::map <std::string, std::string> request;
	
	if (!noware::deserialize <std::map <std::string, std::string>> (request, std::string (msg_request)))
		return false;
	
	if (request ["subject"] == "set")
	{
		//std::cout << request ["value"];
		
		// update the local value
		area.area [noware::nr (request ["location.width"])] [noware::nr (request ["location.height"])] = pixel (noware::nr (request ["color.red"]), noware::nr (request ["color.green"]), noware::nr (request ["color.blue"]));
		
		// update the visual
		// TODO
		
		msg_response = "1";
		//return true;
		return false;
	}
	else if (request ["subject"] == "size")
	{
		if (area.size (coord (noware::nr (request ["size.width"]), noware::nr (request ["size.height"]))))
		{
			msg_response = "1";
			//return true;
			return false;
		}
		else
		{
			msg_response = "0";
			return false;
		}
	}
	
	msg_response = "0";
	return false;
}
