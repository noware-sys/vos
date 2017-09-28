begin transaction;

-- drop table if exists entity;
create table if not exists entity
(
		"group" 						none null default null,	-- group id
		
	"key.type" 		none null default null,
		key 						none null default null,	-- name key
		
	"value.type"		none null default null,
		value 					none null default null	-- content value
);

-- (compound key) id[entification] uni[queness] element/entry/row /entity
-- drop index if exists "entity.id";
create unique index if not exists "entity.id" on entity ("group", key);

commit transaction;
