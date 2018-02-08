#pragma once

// data store
// storage space
// remembers memories

#include <noware/contnr/array.hxx>
#include "dev.hxx"
#include "../mmach/store.hxx"

namespace noware
{
	// Place in another project (kernel/os)?
	namespace cmach
	{
		class store
			: virtual public dev	// the server
			//: virtual public cluster::node	// the client
			//, public misc::iterator <noware::var>
			, virtual public contnr::array <std::string, std::string>
			//, virtual public misc::iterator <std::tuple <std::string, std::string, std::string>>
		{
			public:
				//#include ".store/.hxx"
				
				store (void);
				virtual ~store (void);
				
				//virtual const bool start (void);
				
				
				// Obtainers
				
				virtual bool const empty (void) const;
				virtual bool const full (void) const;
				//key const & get_key (const key &) const;
				
				// capac[ity]
				// total size (available + used) (in bits)
				//const unsigned int magnitude (void) const;
				//const noware::nr::natural magnitude (void) const;
				virtual cln::nr const capac (void) const;
				
				// occ[upied] use[d]
				// used size (in bits)
				virtual cln::nr const used (void) const;
				
				// free avail[able]
				// available size (in bits)
				virtual cln::nr const avail (void) const;
				
				// size mag[nitude] count
				// number of present elements
				virtual cln::nr const size (void) const;
				virtual cln::nr const size (std::string const &/* group*/) const;
				
				// existence presence
				// exist present
				//const bool exist (const noware::var &/* group*/, const noware::var &/* key*/) const;
				virtual bool const exist (std::string const &/* key*/) const;
				virtual bool const exist (std::string const &/* group*/, std::string const &/* key*/) const;
				//const bool exist_group (const noware::var &/* group*/) const;
				
				
				// Returns the nodes which have the specified key.
				//virtual std::map <unsigned int/* map (array) index*/, std::string/* peer.id*/> const owner (std::string const &/* key*/) const;
				//virtual std::map <unsigned int/* map (array) index*/, std::string/* peer.id*/> const owner (std::string const &/* group*/, std::string const &/* key*/) const;
				
				
				
				// obtain attain get
				virtual bool const/* success*/ get (std::string const &/* key*/, std::string &/* value*/) const;
				virtual bool const/* success*/ get (std::string const &/* group*/, std::string const &/* key*/, std::string &/* value*/) const;
				
				//const std::pair <std::string/*value*/, bool/*reference*/> get (const std::string &/* group*/, const std::string &/* key*/) const;
				//const std::pair <std::string/*value*/, bool/*reference*/> get (const std::string &/* key*/) const;
				
				
				// Modifiers
				
				// reinitialize reset clear flush clean
				virtual bool const/* success*/ clear (void);
				virtual bool const/* success*/ clear (std::string const &/* group*/);
				
				// delete remove unset
				virtual bool const/* success*/ remove (std::string const &/* key*/);
				virtual bool const/* success*/ remove (std::string const &/* group*/, std::string const &/* key*/);
				
				// assign associate map set
				virtual bool const/* success*/ set (std::string const &/* group*/, std::string const &/* key*/, std::string const &/* value*/);
				virtual bool const/* success*/ set (std::string const &/* key*/, std::string const &/* value*/);
				//const bool/* success*/ set (const std::string &/* group*/, const std::string &/* key*/, const std::string &/* content/value*/, const bool &/* reference*/ = false);
				//const bool/* success*/ set (const std::string &/* key*/, const std::string &/* content/value*/, const bool &/* reference*/ = false);
				
				//virtual bool const/* success*/ rename (std::string const &/* old_k*/, std::string const &/* new_k*/);
				// virtual std::string /* value*/ operator [] (std::string const &/* key*/);
				//virtual std::string &/* value*/ operator [] (std::nullptr_t const &/* null*/);
				
				
				// Transmit a message to one node.
				//const noware::var unicast (const noware::tree <> &/* message*/, const std::string &/* peer*/);
				
				// Transmit a message to multiple nodes.
				// Main usage: To request other nodes to do an action.
				//const noware::var multicast (noware::tree <> /* message*/, const std::string &/* group*/ = group_default);
				
				//using device::evaluate;
				//static const noware::var group_zmq_default;
				static std::string const grp_dft;
				//static bool const write_dft;
			//protected:
				//bool write;
			public:
				// content value data container
				//noware::list <> data;
				//noware::list <noware::list <>> data;
				//noware::array <noware::array <>> data;
				
				//std::map <std::string/*group*/, std::map <std::string/*key*/, std::string/*value*/>> data;
				//std::map <std::string/*group*/, std::map <std::string/*key*/, std::map <unsigned int/*index*/, std::string/*peer id*/>>> ref;
				////std::map <std::string/*group*/, std::map <std::string/*key*/, std::pair <bool/*reference*/, std::string/*value*/>>> data;
			protected:
				//virtual zmq::msg const/* result*/ aggregate (zmq::msg const &/* result*/, zmq::msg const &/* response*/, zmq::msg const &/* expression*/, cln::nr const &/* responses_count*//* number of peers who answered*/, std::string const &/* src*/, net::cast const &/* src_cast*/);
				//virtual bool const/* success*/ respond (zmq::msg &/* response*/, zmq::msg const &/* rx'd*/, zyre_event_t const * const/* (zyre) event*/, std::string const &/* event_type*/, std::string const &/* src*/, net::cast const &/* src_cast*/);
				virtual bool const/* success*/ search (zmq::msg &/* result*/, zmq::msg const &/* message/expression*/, cln::nr const &/* total, expected resonses count*/, cln::nr const &/* current count of peers who responded (so far)*/, std::string const &/* src*/, net::cast const &/* src_cast*/);// const
		};
	}
}
