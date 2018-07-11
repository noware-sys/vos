#pragma once

#include <string>
#include <zmq/msg.hxx>
#include "../../cmach/dev.hxx"
#include "../../smach/cpu.hxx"

namespace noware
{
	namespace mach
	{
		namespace tool
		{
			class loader
				: virtual public cmach::dev
			{
				public:
					virtual bool const load_store_file (std::string const &/* file_name*/, std::string const &/* thread_id*/ = "");
					virtual bool const load_cpu_file (std::string const &/* file_name*/, std::string const &/* thread_id*/ = "");
					//virtual smach::cpu::x86_64::opr const operation_get (std::string const &/* operation*/) const;
					virtual smach::cpu::bbj::instr const instr_deserialize (std::string const &/* serialized instruction*/) const;
					
					
					// Store functionality
					
					virtual const std::string/* value*/ get (const std::string &/* group*/, const std::string &/* key*/) const;
					virtual const std::string/* value*/ get (const std::string &/* key*/) const;
					
					virtual const bool/* success*/ set (const std::string &/* group*/, const std::string &/* key*/, const std::string &/* content/value*/);
					virtual const bool/* success*/ set (const std::string &/* key*/, const std::string &/* content/value*/);
					
					
					// Queue functionality
					
					//virtual const bool enqueue (const cpu::x86_64::instr &);
					virtual bool const enqueue (std::string const &);
					
					
					// Device functionality
					
					virtual const bool/* success*/ search (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/, const cln::nr &/* total, expected resonses count*/, const cln::nr &/* current count of peers who responded (so far)*/, const std::string &/* src*/, const net::cast &/* src_cast*/);// const
			};
		}
	}
}
