// class seq[uence][r]
class allocator : public device
{
	public:
		allocator (void);
		~allocator (void);
		
		//allocate ();
		//deallocate ();
		
		const noware::nr group_min (void) const;
		const noware::nr group_max (void) const;
		const noware::nr group_next (void) const;
		const noware::nr group_avail (void) const;
		
		const noware::nr key_min (const std::string &/* group*/ = noware::array::sqlite::group_default) const;
		const noware::nr key_max (const std::string &/* group*/ = noware::array::sqlite::group_default) const;
		const noware::nr key_next (const std::string &/* group*/ = noware::array::sqlite::group_default) const;
		const noware::nr key_avail (const std::string &/* group*/ = noware::array::sqlite::group_default) const;
		
		const noware::var group_default;
	protected:
		//allocations;
	public:
	//protected:
		const bool/* success*/ respond (const noware::tree <> &/* message*/, const zyre_event_t */* (zyre) event*/);
		const bool/* success*/ search (noware::var &/* result*/, const noware::tree <> &/* message*/);// const
		const bool/* success*/ search_local (noware::var &/* result*/, const noware::tree <> &/* message/expression*/);// const
		const noware::var/* result*/ aggregate (const noware::var &/* result*/, noware::nr::natural &/* responses_count*/, const noware::var &/* response*/, const noware::tree <> &/* expression*/);
};
