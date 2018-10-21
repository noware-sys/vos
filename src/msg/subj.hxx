#pragma once

namespace noware
{
	namespace vos
	{
		namespace msg
		{
			enum subj
			{
				/*
				subj,	// meta/subj[ect]/title/topic/theme
				
				dir,	// dir[ection]
				req,	// req[uest]
				re,		// re[sponse]/re[ply]
				
				grp,
				key,
				val,
				ok,		// success
				//ret,	// returned value
				*/
				exist,
				get,
				set,
				del,
				dequeue,
				enqueue,
				next,
				next_dequeue,
				size,
				avail,
				used,
				capac,
				empty,
				full,
				clear,
				cout,
				cin,
				owner
			};
		}
	}
}
