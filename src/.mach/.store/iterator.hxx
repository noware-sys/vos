#pragma once

// iterat[or]
class iterator : public device//, public misc::iterator <noware::var>
{
	public:
		//iterator (void);
		//~iterator (void);
		
		const bool/* success*/ respond (const noware::tree <> &/* message*/, const zyre_event_t */* (zyre) event*/);
		const bool/* success*/ search (noware::var &/* result*/, const noware::tree <> &/* message*/);// const
		const bool/* success*/ search_local (noware::var &/* result*/, const noware::tree <> &/* message/expression*/);// const
		const noware::var/* result*/ aggregate (const noware::var &/* result*/, noware::nr::natural &/* responses_count*/, const noware::var &/* response*/, const noware::tree <> &/* expression*/);
};
