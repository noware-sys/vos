#pragma once

#include <string>
#include <zmq/msg.hxx>
#include "../usr/dev.hxx"
#include "../srv/cpu/x86_64.hxx"

namespace noware
{
	namespace vos
	{
		namespace tool
		{
			class loader
				: virtual public usr::dev
			{
				public:
					virtual bool const load_file_store (std::string const &/* file_name*/, int unsigned const &/* thread_id*/ = "");
				//	virtual bool const load_file_cpu (std::string const &/* file_name*/, std::string const &/* thread_id*/ = "");
					//virtual smach::cpu::x86_64::opr const operation_get (std::string const &/* operation*/) const;
				//	virtual smach::cpu::bbj::instr const instr_deserialize (std::string const &/* serialized instruction*/) const;
					
					
					// Store functionality
					virtual char unsigned const /* value*/ get (int unsigned const &/* group*/, uint64_t const &/* key*/) const;
					//virtual char unsigned const /* value*/ get (uint64_t const &/* key*/) const;
					
					virtual bool const/* success*/ set (int unsigned const &/* group*/, uint64_t const &/* key*/, char unsigned const &/* value*/);
					//virtual bool const/* success*/ set (uint64_t const &/* key*/, const std::string &/* content/value*/);
					
					
					// Queue functionality
					//virtual const bool enqueue (const cpu::x86_64::instr &);
					virtual bool const enqueue (std::string const &);
					
					
					// Device functionality
					virtual bool const/* success*/ aggregate_remote (zmq::msg &/* overall/final result. passed during each iteration*/, zmq::msg const &/* current response message/expression*/, cln::nr const &/* total, expected resonses count*/, cln::nr const &/* current count of peers who responded (so far)*/, std::string const &/* src*/, net::cast const &/* src_cast*/);
					virtual const bool/* success*/ search_remote (zmq::msg const &/* result*/, const zmq::msg &/* message/expression*/, const cln::nr &/* total, expected resonses count*/, const cln::nr &/* current count of peers who responded (so far)*/, const std::string &/* src*/, const net::cast &/* src_cast*/);// const
			};
		}
	}
}
