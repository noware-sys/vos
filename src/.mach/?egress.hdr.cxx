class sqlite : public device
{
	public:
		sqlite (void);
		~sqlite (void);
		
		// Getters.
		//const bool empty (void) const;
		//const bool full (void) const;
		//const noware::number::natural magnitude (void) const;
		const noware::number magnitude (void) const;	// size magnitude
		//const unsigned int magnitude (void) const;
		
		// existence presence
		// exist present
		const bool/* success*/ present (const noware::var &/* group*/, const noware::var &/* key*/) const;
		const bool/* success*/ present (const noware::var &/* key*/) const;
		
		const noware::var/* value*/ get (const noware::var &/* group*/, const noware::var &/* key*/) const;
		const noware::var/* value*/ get (const noware::var &/* key*/) const;
		
		// Modifiers.
		const bool/* success*/ reset (void);	// reinitialize reset clear flush clean
		const bool/* success*/ remove (const noware::var &/* group*/, const noware::var &/* key*/);
		const bool/* success*/ remove (const noware::var &/* key*/);
		const bool/* success*/ set (const noware::var &/* group*/, const noware::var &/* key*/, const noware::var &/* value*/);
		const bool/* success*/ set (const noware::var &/* key*/, const noware::var &/* value*/);
		
		// Transmit a message to one node.
		//const noware::var unicast (const noware::tree <> &/* message*/, const std::string &/* peer*/);
		
		// Transmit a message to multiple nodes.
		// Main usage: To request other nodes to do an action.
		//const noware::var multicast (noware::tree <> /* message*/, const std::string &/* group*/ = group_default);
		
		//using device::evaluate;
		static const noware::var group_default;
		//static const noware::var group_sql_default;
		//static const std::string query_sql_initial;
	protected:
		noware::container::list::sqlite data;
	public:
	//protected:
		const bool/* success*/ respond (const noware::tree <> &/* message*/, const zyre_event_t */* (zyre) event*/);
		const bool/* success*/ search (noware::var &/* result*/, const noware::tree <> &/* message*/);// const
		const bool/* success*/ search_local (noware::var &/* result*/, const noware::tree <> &/* message/expression*/);// const
		const noware::var/* result*/ aggregate (const noware::var &/* result*/, const noware::var &/* response*/, const noware::tree <> &/* expression*/);
};
