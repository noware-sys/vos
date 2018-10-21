#pragma once

// data store
// storage space
// remembers memories

#include "dev.hxx"
#include <string>
#include <noware/contnr/array.hxx>
#include <cln/nr.hxx>
#include <noware/var.hxx>
#include "../srv/store.hxx"

namespace noware
{
	// Place in another project (kernel/os)?
	namespace vos
	{
		namespace man
		{
			template
			<
				//typename val_t = contnr::array <val_t, key_t>::val_t_dft,
				typename val_t = var,
				//typename key_t = contnr::array <val_t, key_t>::key_t_dft,
				typename key_t = var,
				typename grp_t = var
			>
			class store
				: virtual public dev
				//: virtual public cluster::node	// the client
				//, public misc::iterator <noware::var>
				, virtual public contnr::array <val_t, key_t>
				//, virtual public misc::iterator <std::tuple <std::string, std::string, std::string>>
			{
				public:
					//#include ".store/.hxx"
					
					store (void);
					virtual ~store (void);
					
					virtual const bool start (void);
					
					//using device::evaluate;
					//static const noware::var group_zmq_default;
					static std::string const grp_dft;
					static bool const cache_dft;
				//protected:
					bool cache;
				public:
					// content value data container
					//noware::list <> data;
					//noware::list <noware::list <>> data;
					//noware::array <noware::array <>> data;
					
					//std::map <std::string/*group*/, std::map <std::string/*key*/, std::string/*value*/>> data;
					//std::map <std::string/*group*/, std::map <std::string/*key*/, std::map <unsigned int/*index*/, std::string/*peer id*/>>> ref;
					////std::map <std::string/*group*/, std::map <std::string/*key*/, std::pair <bool/*reference*/, std::string/*value*/>>> data;
				protected:
					// aggregate_local: not really needed
					virtual bool const/* success*/ respond (zmq::msg &/* response*/, zmq::msg const &/* rx'd*/, zyre_event_t const * const/* (zyre) event*/, std::string const &/* event_type*/, std::string const &/* src*/, net::cast const &/* src_cast*/);
					//virtual zmq::msg const/* result*/ aggregate_local (zmq::msg const &/* result*/, zmq::msg const &/* response*/, zmq::msg const &/* expression*/, cln::nr const &/* responses_count*//* number of peers who answered*/, std::string const &/* src*/, net::cast const &/* src_cast*/);
					virtual bool const/* success*/ aggregate_remote (zmq::msg &/* overall/final result. passed during each iteration*/, zmq::msg const &/* current response message/expression*/, cln::nr const &/* total, expected resonses count*/, cln::nr const &/* current count of peers who responded (so far)*/, std::string const &/* src*/, net::cast const &/* src_cast*/);
					virtual bool const/* success*/ search_remote (zmq::msg const &/* result*/, zmq::msg const &/* message/expression*/, cln::nr const &/* total, expected resonses count*/, cln::nr const &/* current count of peers who responded (so far)*/, std::string const &/* src*/, net::cast const &/* src_cast*/);// const
			};
		}
	}
}
