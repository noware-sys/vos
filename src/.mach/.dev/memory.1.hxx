/*
#pragma once
//#ifndef __MEMORY
//#define __MEMORY

#include <string>
//#include <map>
#include <mutex>

// Intel Treading Bulding Blocks:
//#include <tbb/tbb.h>

// Boost:
//#include <boost/any.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>	//
//#include <boost/thread/detail/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
*/
/*
#include <Poco/Net/TCPServer.h>
#include <Poco/Net/TCPServerParams.h>
#include <Poco/Net/TCPServerConnectionFactory.h>
#include <Poco/Net/TCPServerConnection.h>
#include <Poco/Net/Socket.h>
#include <Poco/Data/DataException.h>
#include <Poco/Util/Timer.h>
#include <Poco/Util/TimerTask.h>
#include <Poco/Util/TimerTaskAdapter.h>
*/
/*
#include "../../default.h++"
#include "../../mathematics.h++"
#include "../../containers/array.h++"
#include "../../containers/variable.h++"
#include "../../containers/entity.h++"
#include "../../communication/messaging.h++"
//#include "../network/peers.h++"
// #include "../../network/mpi.h++"
//#include "../network/ip.h++"
//#include "../threads.h++"
// #include "../../cluster/machine.h++"
#include "../../cluster/members.h++"
//#include "../device.h++"

//typedef std::string value, key;

//#include "../../containers/entity-pre.h++"
*/
/*
namespace LIB
{
	namespace machine
	{
		namespace device
		{
*/
			class memory : virtual public noware::container::memory, protected LIB::machine::device//, LIB::communication::messaging //, LIB::NTT <value, key>
			{
				public:
					//typedef std::string value, key;
					//typedef std::string key;
					//typedef boost::any value;
					//typedef std::string value;
					//typedef std::string value_cast;
					
					//typedef NTT registry, directory, folder;
					
					// friend class LIB::cluster::cluster;
					//friend class LIB::cluster::members;
					
//					typedef NTT registry, directory, folder;
					
					noware/*::machine*/::cluster cluster;
					//cluster cluster;
					
					
					using LIB::container::memory::database_name;
					using LIB::container::memory::size;
					using LIB::container::memory::size_group;
					using LIB::container::memory::clear;
					using LIB::container::memory::clear_group;
					using LIB::container::memory::empty;
					using LIB::container::memory::empty_group;
					using LIB::container::memory::full;
					using LIB::container::memory::exists;
					using LIB::container::memory::pop;
					using LIB::container::memory::key_group_integral_min;
					using LIB::container::memory::key_group_integral_max;
					using LIB::container::memory::key_name_integral_min;
					using LIB::container::memory::key_name_integral_max;
					using LIB::container::memory::enqueue;
					using LIB::container::memory::dequeue;
					using LIB::container::memory::beginning;
					using LIB::container::memory::ending;
					using LIB::container::memory::begin;
					using LIB::container::memory::end;
					using LIB::container::memory::sequence_group_next_available;
					using LIB::container::memory::sequence_group_next;
					using LIB::container::memory::sequence_name_next_available;
					using LIB::container::memory::sequence_name_next;
					using LIB::container::memory::list;
					using LIB::container::memory::refresh_list;
					//using LIB::container::memory::save;
					//using LIB::container::memory::load;
					//using LIB::container::memory::serialize;
					//using LIB::container::memory::deserialize;
					using LIB::container::memory::set;
					using LIB::container::memory::get;
					using LIB::container::memory::is_name_literal;
					using LIB::container::memory::is_content_literal;
					
					//friend class boost::serialization::access;
					
					//BOOST_SERIALIZATION_SPLIT_MEMBER ();
					
					//template <typename archive>
					//void serialize (archive &/* Archive (stream). */, const unsigned int &/* Version. */);
					
					//template <typename archive>
					//void save (archive &/* Archive (stream). */, const unsigned int &/* Version. */) const;
					
					//template <typename archive>
					//void load (archive &/* Archive (stream). */, const unsigned int &/* Version. */);
					
					
					const bool set (const LIB::container::memory::key &/* name*/, const LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::memory::value> &/* values*/, const LIB::container::memory::key &/* group*/ = default_group);
					const bool set (const LIB::container::memory::key &/* name*/, const LIB::container::memory::key &/* group*/ = default_group);	// Uses default values.
					
					const LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> get (const LIB::container::memory::key &/* name*/, const LIB::container::memory::key &/* group*/ = default_group) const;
					
					const LIB::mathematics::numbers::natural size (void) const;
					const LIB::mathematics::numbers::natural size_group (const LIB::container::memory::key &/* group*/ = default_group) const;
					const bool clear (void);
					const bool clear_group (const LIB::container::memory::key &/* group*/ = default_group);
					const bool empty (void) const;
					const bool empty_group (const LIB::container::memory::key &/* group*/ = default_group) const;
					const bool full (void) const;
					const bool exists (const LIB::container::memory::key &/* name*/, const LIB::container::memory::key &/* group*/ = default_group) const;
					const bool unset (const LIB::container::memory::key &/* name*/, const LIB::container::memory::key &/* group*/ = default_group);
					
					const bool is_name_literal (const LIB::container::memory::key &/* name*/, const LIB::container::memory::key &/* group*/ = default_group) const;
					const bool is_content_literal (const LIB::container::memory::key &/* name*/, const LIB::container::memory::key &/* group*/ = default_group) const;
					
					const bool add (const LIB::container::memory::key &, const LIB::container::memory::value & = LIB::container::memory::default_value);
					// This gives back the key which was used.
					const bool add (LIB::container::memory::key &/* used_group*/, const LIB::container::memory::key &/* name*/, const LIB::container::memory::value &/* content*/ = LIB::container::memory::default_value);
					//// This overwrites any existing keys with the provided values.
					//const bool add (const LIB::container::NAME_A <value, key> &);
					// const bool add (const memory &);
					
					// These are used as "add", as "enqueue", and as "push".
					const bool append (const LIB::container::memory::key &, const LIB::container::memory::value & = LIB::container::memory::default_value);
					// Gives back the key that was used.
					const bool append (LIB::container::memory::key &, const LIB::container::memory::key &, const LIB::container::memory::value & = LIB::container::memory::default_value);
					//// Uses new keys for any existing ones rather than the provided values.
					//const bool append (const NAME_A <value, key> &);
					// const bool append (const memory &);
					
					const LIB::mathematics::numbers::integer key_group_integral_min (void) const;
					const LIB::mathematics::numbers::integer key_group_integral_max (void) const;
					const LIB::mathematics::numbers::integer key_name_integral_min (const LIB::container::memory::key &/* group*/ = default_group) const;
					const LIB::mathematics::numbers::integer key_name_integral_max (const LIB::container::memory::key &/* group*/ = default_group) const;
					
					// Queue functionality:
					const bool enqueue (LIB::container::memory::key &, const LIB::container::memory::key &, const LIB::container::memory::value & = LIB::container::memory::default_value);
					const bool enqueue (const LIB::container::memory::key &, const LIB::container::memory::value & = LIB::container::memory::default_value);
					const bool dequeue (void);
				
					// Stack functionality:
					const bool push (LIB::container::memory::key &, const LIB::container::memory::key &, const LIB::container::memory::value & = LIB::container::memory::default_value);
					const bool push (const LIB::container::memory::key &, const LIB::container::memory::value & = LIB::container::memory::default_value);
					const bool pop (void);
					//const key top_key (void) const;
					//const value top (void) const;
					//const key bottom_key (void) const;
					//const value bottom (void) const;
				
					// Common functionality to queue and to stack.
					//const key front_key (void) const;
					const LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> beginning (void) const;
					//const key rear_key (void) const;
					const LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> ending (void) const;
				
					//// Is the type of the key numeric?
					//const bool integral_key (void) const;
					// Return the next available unique value in the sequence (ID).
					const LIB::mathematics::numbers::natural sequence_group_next_available (void) const;
					// Return the next greatest unique value in the sequence (ID).
					const LIB::mathematics::numbers::natural sequence_group_next (void) const;
					const LIB::mathematics::numbers::natural sequence_name_next_available (const LIB::container::memory::key &/* group*/ = default_group) const;
					const LIB::mathematics::numbers::natural sequence_name_next (const LIB::container::memory::key &/* group*/ = default_group) const;
					
					// For range-based (for) loop:
					/*
						Next:		++
						Previous:	--
					*/
					
					//void begin (void);
					//void end (void);
					const iterator begin (void) const;
					const iterator end (void) const;
					//const const_iterator & begin (void) const;
					//const const_iterator & end (void) const;
					// Allow external modifications:
					//const iterator begin (void);
					//const iterator end (void);
					
					// Prefix:
					//NAME_A <value, key> & operator ++ (void);
					//NAME_A <value, key> & operator -- (void);
					
					// Postfix / Suffix:
					//NAME_A <value, key> operator ++ (signed int);
					//NAME_A <value, key> operator -- (signed int);
					
					//signed int		operator	*	(void);
					//key & operator * (void) const;
					
					const std::string serialize (void) const;
					const bool deserialize (const std::string &);
					
					//// Serialize.
					//operator const std::string (void) const;
					//// Deserialize.
					//const memory & operator = (const std::string &);
					
					const bool refresh_list (void);
					
					// Get the container.
					LIB::container::db::sqlite & database (void);
				
					const std::string & database_name (void) const;
					
				protected:
					using LIB::machine::device::transmit;
					using LIB::machine::device::broadcast;
					
					using LIB::container::memory::initialize;
					//using LIB::container::memory::finalize;
					
					const bool initialize (const std::string &/* _database_name*/ = default_database_name);
					//const bool finalize (void);
					
					// The container.
					//LIB::NAME_A <value, key> variables;
					LIB::container::memory * container;
					
					////LIB::cluster::members members;
					//LIB::machine::cluster cluster;
					/*
						To do:
						
						Allow variables to be found when not all nodes are interconnected (re-broadcast).
					*/
					
					const bool finalize (void);
				//public:
					//typedef LIB::containers::NAME_V key, value;
					//typedef container value;

					//#include "entity.h++"
					/*
					class container
					{
						public:
							container (void);
							container (const container &);
							~container (void);

							bool reference;
							LIB::NAME_V value;
					};
					*/
					
					/*
					class iterator
					{
						public:
							iterator (void);
							iterator (const iterator &);
							//~iterator (void);

							const iterator & operator = (const iterator &);
							const bool operator == (const iterator &) const;
							const bool operator != (const iterator &) const;
							const iterator & operator ++ (void);
							const iterator & operator -- (void);
							const LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V>::package & operator * (void) const;

							//LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> list;
							//bool set;	// If "this -> list" is already populated/set.

							typename LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V>::iterator iter;
					};
					*/
					
					/*
					// Relations used when dealing with the self object.
					enum relation
					{
						self,	// Note that this value also considers the entity.
						sibbling,
						descendant,
						ancestor,
						// Special cases:
						root,
						other
					};
					*/
					//// This returns the relationship of the other object: what does the other represent to this?
					//// If another object than self is passed to this function, "relation::other" is returned.
					//const relation relate (const memory &/* other*/) const;

					// static const std::string default_database_name;

					// static const key default_group;
					//static const key default_previous_group = 0;
					//static const key default_name = "";
					// static const value default_value;

					//friend class boost::serialization::access;

					//template <typename archive>
					//void serialize (archive &/* Archive (stream). */, const unsigned int &/* Version. */);

				//	template <typename archive>
				//	void save (archive &/* Archive (stream). */, const unsigned int &/* Version. */) const;

				//	template <typename archive>
				//	void load (archive &/* Archive (stream). */, const unsigned int &/* Version. */);

					//BOOST_SERIALIZATION_SPLIT_MEMBER ();

					//memory (const LIB::databases::sqlite *& = NULL, const LIB::memory::key &/* current_group*/ = default_group, const LIB::memory::key &/* previous_group*/ = default_previous_group, const LIB::memory::key &/* previous_name*/ = default_name, const std::string &/* _database_name*/ = default_database_name);
					//memory (void);
				//	memory (void);
					//memory (const memory &/* other*/, const std::string &/* _database_name*/ = default_database_name);
				//	~memory (void);

					//const bool query (LIB::NAME_A <LIB::NAME_A <LIB::NAME_V, LIB::NAME_V>, LIB::NAME_V> &/* result*/, const std::string &/* the query*/, const LIB::NAME_A <LIB::NAME_V, LIB::NAME_V> &/* arguments*/ = NULL);

					// const bool operator == (const memory &) const;
					// const bool operator != (const memory &) const;
					//const bool operator == (const value &) const;
					//const bool operator != (const value &) const;
					// const memory & operator = (const memory &);
					//const memory & operator = (const value &);

					// const LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> list (void) const;

					//const bool set (const key &/* name*/, const value &);
					// Set a value.
					//const bool set (const key &/* group*/, const key &/* name*/, const key &/* new group*/, const key &/* new name*/, const value &/* name: type*/ = 0, const value &/* content: type*/ = 0, const value *&/* value*/ = NULL);
					// const bool set (const key &/* name*/, const LIB::containers::NAME_A <LIB::containers::NAME_V, value> &/* values*/, const key &/* group*/ = default_group);
					//const bool set (const LIB::containers::NAME_A <LIB::containers::NAME_V, value> &/* new values*/);
				//	const bool set (const LIB::containers::memory::key &/* name*/, const LIB::containers::memory::value &/* value*/, const LIB::containers::memory::key &/* group*/ = LIB::containers::memory::default_group);	// Uses default values.
					//const bool set_value (const key &/* group*/, const key &/* name*/, const value &/* name: type*/ = 0, const value &/* content: type*/ = 0, const value *&/* value*/ = & default_value);
					// const bool set/*_literal*/ (const memory &/* other*/);
					//// Set a undefined grouped value.
					//const bool set_group (void);
					// Set a defined, named grouped value.
					//const bool set_group (const key &/* name*//* = default_value*/);
					//const bool set_group (const key &/* name*//* = default_value*/, const key &);

					// Get the columns.
				//	const LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> get (const LIB::containers::memory::key &/* name*/, const LIB::containers::memory::key &/* group*/ = LIB::containers::memory::default_group) const;
					//// Get the value from the named group.
					//memory get (const key &/* name*/) const;
					//const memory & get (const key &/* name*/) const;

					// Getter.
					//operator const value/* &*/ (void) const;
					//operator const LIB::NAME_A <value, key>/* &*/ (void) const;

					// Getter and setter.
					//memory operator [] (const key &/* name*/);
					// Getter.
					//const memory & operator [] (const key &/* name*/) const;

					//const bool content_clear_literal (const key &/* name*/);
					//const bool content_clear_group (const key &/* name*/ = default_name);

				//	const LIB::mathematics::numbers::natural size (void) const;
				//	const LIB::mathematics::numbers::natural size_group (const LIB::containers::memory::key &/* group*/ = LIB::containers::memory::default_group) const;
				//	const bool clear (void);
				//	const bool clear_group (const LIB::containers::memory::key &/* group*/ = LIB::containers::memory::default_group);
				//	const bool empty (void) const;
				//	const bool empty_group (const LIB::containers::memory::key &/* group*/ = LIB::containers::memory::default_group) const;
				//	const bool full (void) const;
					//const bool exist (const key &/* name*/) const;
				//	const bool exists (const LIB::containers::memory::key &/* name*/, const LIB::containers::memory::key &/* group*/ = LIB::containers::memory::default_group) const;
					//const bool rename (const key &/* old_name*/, const key &/* new_name*/, const key &/* old_group*/ = default_group, const key &/* new_group*/ = default_group) const;
				//	const bool unset (const LIB::containers::memory::key &/* name*/, const LIB::containers::memory::key &/* group*/ = LIB::containers::memory::default_group);

					//const bool is_name_group (const key &/* name*/, const key &/* group*/ = default_group) const;
				//	const bool is_name_literal (const LIB::containers::memory::key &/* name*/, const LIB::containers::memory::key &/* group*/ = LIB::containers::memory::default_group) const;
					//const bool is_value_group (const key &/* name*/, const key &/* group*/ = default_group) const;
				//	const bool is_value_literal (const LIB::containers::memory::key &/* name*/, const LIB::containers::memory::key &/* group*/ = LIB::containers::memory::default_group) const;

					// These use "add ()":
					//const memory operator + (const value &) const;
					// const memory operator + (const memory &) const;
					//const memory & operator += (const value &);
					// const memory & operator += (const memory &);

				//	const bool add (const LIB::containers::memory::key &, const LIB::containers::memory::value & = LIB::containers::memory::default_value, const LIB::containers::memory::key & = LIB::containers::memory::default_group);
					// This gives back the key which was used.
				//	const bool add (LIB::containers::memory::key &/* used_group*/, const LIB::containers::memory::key &/* name*/, const LIB::containers::memory::value &/* content*/ = LIB::containers::memory::default_value);
					//// This overwrites any existing keys with the provided values.
					//const bool add (const LIB::containers::NAME_A <value, key> &);
					// const bool add (const memory &);

					// These are used as "add", as "enqueue", and as "push".
				//	const bool append (const LIB::containers::memory::key &, const LIB::containers::memory::value & = default_value);
					// Gives back the key that was used.
				//	const bool append (LIB::containers::memory::key &, const LIB::containers::memory::key &, const LIB::containers::memory::value & = LIB::containers::memory::default_value);
					//// Uses new keys for any existing ones rather than the provided values.
					//const bool append (const NAME_A <value, key> &);
					// const bool append (const memory &);

				//	const LIB::mathematics::numbers::integer key_group_integral_min (void) const;
				//	const LIB::mathematics::numbers::integer key_group_integral_max (void) const;
				//	const LIB::mathematics::numbers::integer key_name_integral_min (const LIB::containers::memory::key &/* group*/ = LIB::containers::memory::default_group) const;
				//	const LIB::mathematics::numbers::integer key_name_integral_max (const LIB::containers::memory::key &/* group*/ = LIB::containers::memory::default_group) const;
					
					// Queue functionality:
				//	const bool enqueue (LIB::containers::memory::key &, const LIB::containers::memory::key &, const LIB::containers::memory::value & = LIB::containers::memory::default_value);
				//	const bool enqueue (const LIB::containers::memory::key &, const LIB::containers::memory::value & = LIB::containers::memory::default_value);
				//	const bool dequeue (void);

					// Stack functionality:
				//	const bool push (LIB::containers::memory::key &, const LIB::containers::memory::key &, const LIB::containers::memory::value & = LIB::containers::memory::default_value);
				//	const bool push (const LIB::containers::memory::key &, const LIB::containers::memory::value & = LIB::containers::memory::default_value);
				//	const bool pop (void);
					//const key top_key (void) const;
					//const value top (void) const;
					//const key bottom_key (void) const;
					//const value bottom (void) const;

					// Common functionality to queue and to stack.
					//const key front_key (void) const;
				//	const LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> beginning (void) const;
					//const key rear_key (void) const;
				//	const LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> ending (void) const;

					//// Is the type of the key numeric?
					//const bool integral_key (void) const;
					// Return the next available unique value in the sequence (ID).
				//	const mathematics::numbers::natural sequence_group_next_available (void) const;
					// Return the next greatest unique value in the sequence (ID).
				//	const mathematics::numbers::natural sequence_group_next (void) const;
				//	const mathematics::numbers::natural sequence_name_next_available (const LIB::containers::memory::key &/* group*/ = default_group) const;
				//	const mathematics::numbers::natural sequence_name_next (const LIB::containers::memory::key &/* group*/ = default_group) const;
					
					// For range-based (for) loop:
					/*
						Next:		++
						Previous:	--
					*/

					//void begin (void);
					//void end (void);
				//	const iterator begin (void) const;
				//	const iterator end (void) const;
					//const const_iterator & begin (void) const;
					//const const_iterator & end (void) const;
					// Allow external modifications:
					//const iterator begin (void);
					//const iterator end (void);

					// Prefix:
					//NAME_A <value, key> & operator ++ (void);
					//NAME_A <value, key> & operator -- (void);

					// Postfix / Suffix:
					//NAME_A <value, key> operator ++ (signed int);
					//NAME_A <value, key> operator -- (signed int);

					//signed int		operator	*	(void);
					//key & operator * (void) const;

				//	const std::string serialize (void) const;
				//	const bool deserialize (const std::string &);

					//// Serialize.
					//operator const std::string (void) const;
					//// Deserialize.
					//const memory & operator = (const std::string &);

					//const bool refresh_list (void);

					// Get the container.
					//LIB::databases::sqlite & database (void);

					//const std::string & database_name (void) const;
				protected:
					//const bool initialize (const LIB::databases::sqlite *& = NULL, const LIB::memory::key &/* current_group*/ = default_group, const LIB::memory::key &/* previous_group*/ = default_previous_group, const LIB::memory::key &/* previous_name*/ = default_name, const std::string &/* _database_name*/ = default_database_name);
					//const bool initialize (const std::string &/* _database_name*/ = LIB::containers::memory::default_database_name);
				//	const bool _set (const LIB::containers::memory::key &, const LIB::containers::memory::key &, const LIB::containers::memory::value &);

					// The container.
					//LIB::databases::sqlite * db;

					//// The group in the table which is represented by the current instance of this object.
					//key group;
					//// The group and the name from the previous entity which were used to get to this entity.
					//key previous_name;
					//key previous_group;

					// The database which is used.
					//std::string _database_name;

					//LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> _list;
			};
/*		}
	}
}
*/

//#include "../../cluster.h++"

