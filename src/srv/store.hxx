#pragma once

// data store
// storage space
// remembers memories

#include <string>
#include <cln/nr.hxx>
#include <noware/var.hxx>
#include <noware/contnr/array.hxx>
#include "dev.hxx"
//#include "store.op.hxx"

namespace noware
{
	// Place in another project (kernel/os)?
	namespace vos
	{
		namespace srv
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
				: virtual public dev	//// the server
				//: virtual public cluster::node	//// the client
				//, public misc::iterator <noware::var>
				, virtual public contnr::array <val_t, key_t>
				//, virtual public misc::iterator <std::tuple <std::string, std::string, std::string>>
			{
				public:
					//#include ".store/.hxx"
					
					store (void);
					virtual ~store (void);
					
					virtual const bool start (void);
					
					
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
					virtual cln::nr const size (grp_t const &/* group*/) const;
					
					// existence presence
					// exist present
					//const bool exist (const noware::var &/* group*/, const noware::var &/* key*/) const;
					virtual bool const exist (grp_t const &/* group*/, key_t const &/* key*/) const;
				//	virtual bool const exist (key_t const &/* key*/) const;
					//const bool exist_group (const noware::var &/* group*/) const;
					
					
					// Returns the nodes which have the specified key.
					//virtual std::map <unsigned int/* map (array) index*/, std::string/* peer.id*/> const owner (std::string const &/* key*/) const;
					//virtual std::map <unsigned int/* map (array) index*/, std::string/* peer.id*/> const owner (std::string const &/* group*/, std::string const &/* key*/) const;
					
					
					
					// obtain attain get
					virtual bool const/* success*/ get (grp_t const &/* group*/, key_t const &/* key*/, val_t const * &/* value*/) const;
				//	virtual bool const/* success*/ get (key_t const &/* key*/, val_t const * &/* value*/) const;
					
					//const std::pair <std::string/*value*/, bool/*reference*/> get (const std::string &/* group*/, const std::string &/* key*/) const;
					//const std::pair <std::string/*value*/, bool/*reference*/> get (const std::string &/* key*/) const;
					
					
					// Modifiers
					
					// reinitialize reset clear flush clean
					virtual bool const/* success*/ clear (void);
					virtual bool const/* success*/ clear (grp_t const &/* group*/);
					
					// del[ete] remove/rm unset
					virtual bool const/* success*/ del (grp_t const &/* group*/, key_t const &/* key*/);
				//	virtual bool const/* success*/ remove (key_t const &/* key*/);
					
					// assign associate map set
					virtual bool const/* success*/ set (grp_t const &/* group*/, key_t const &/* key*/, val_t const &/* value*/);
				//	virtual bool const/* success*/ set (key_t const &/* key*/, val_t const &/* value*/);
					//const bool/* success*/ set (const std::string &/* group*/, const std::string &/* key*/, const std::string &/* content/value*/, const bool &/* reference*/ = false);
					//const bool/* success*/ set (const std::string &/* key*/, const std::string &/* content/value*/, const bool &/* reference*/ = false);
					
					//virtual bool const/* success*/ rename (std::string const &/* old_k*/, std::string const &/* new_k*/);
					//virtual std::string &/* value*/ operator [] (std::string const &/* key*/);
					//virtual std::string &/* value*/ operator [] (std::nullptr_t const &/* null*/);
					
					
					// Transmit a message to one node.
					//const noware::var unicast (const noware::tree <> &/* message*/, const std::string &/* peer*/);
					
					// Transmit a message to multiple nodes.
					// Main usage: To request other nodes to do an action.
					//const noware::var multicast (noware::tree <> /* message*/, const std::string &/* group*/ = group_default);
					
					//using device::evaluate;
					//static const noware::var group_zmq_default;
					
					static std::string const grp_dft;
					static bool const write_dft;
					
					typedef noware::var grp_t_dft;
				//protected:
					bool write;
				//private:
				public:
					// content value data container
					//noware::list <> data;
					//noware::list <noware::list <>> data;
					//noware::array <noware::array <>> data;
					
					std::map <grp_t/*group*/, std::map <key_t/*key*/, val_t/*value*/>> data;
					
					// 
					//std::map <std::string/*group*/, std::map <uint64_t/*key (64 bits)*/, uint8_t/*value (8 bits)*/>> data;
				//	std::map <std::string/*group*/, std::map <std::string/*key*/, std::map <unsigned int/*index*/, std::string/*peer id*/>>> ref;
					////std::map <std::string/*group*/, std::map <std::string/*key*/, std::pair <bool/*reference*/, std::string/*value*/>>> data;
				private:
				//protected:
					virtual bool const/* success*/ respond (zmq::msg &/* response*/, zmq::msg const &/* rx'd*/, zyre_event_t const * const/* (zyre) event*/, std::string const &/* event_type*/, std::string const &/* src*/, net::cast const &/* src_cast*/);
			};
		}
	}
}
