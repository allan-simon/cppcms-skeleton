pragma foreign_keys = off; -- required for import from C++ to work
begin;
    drop table if exists articles;

    -- table representing an article (i.e a page of the wiki)
    -- TODO maybe have something to do a more precise restriction (for example authorizing only some kind of users
    --      to edit a given pages (e.g only moderators/only admin)
    -- TODO same things for the visibility 
    create table articles (
        id integer primary key autoincrement not null,
        lang text not null,                            -- code iso 639-3 alpha 3 in which the articles is written
        slug text not null,                            -- "url" name of the article 
        title text not null,                           -- title of the article 
        content text not null,                         -- the content of the article itself
        locked boolean,                                -- if the articles can be edited or not
        unique (lang,slug)                             -- in order to not have several articles on the same url
    );





commit ;

