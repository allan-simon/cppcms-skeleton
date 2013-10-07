pragma foreign_keys = off; -- required for import from C++ to work
begin;
    drop table if exists articles;
    drop table if exists users;
    drop table if exists articles_translations;
    drop table if exists deleted_articles;
    drop table if exists history;
    drop table if exists conflicts;
    drop table if exists salt;
    drop table if exists uploads;
    drop table if exists search;

    -- table representing a user
    CREATE TABLE users (
        "id"          integer primary key autoincrement not null , 
        "username"    text    not null unique,             -- his nickname 
        "email"       text    not null unique,             -- his email address
        "image"       text    not null default "unknown" , -- his personnal image 
        "password"    text    not null,                    -- his password hashed
        "since"       integer not null,                    -- his registering date
        "homepage"    text    default "",                  -- his personnal webpage/website
        "description" text    default ""                   -- his self-written description
    );
    CREATE INDEX users_username_idx ON users (username);

    -- table representing an article (i.e a page of the wiki)
    -- TODO maybe have something to do a more precise restriction (for example authorizing only some kind of users
    --      to edit a given pages (e.g only moderators/only admin)
    -- TODO same things for the visibility 
    create table articles (
        id integer primary key autoincrement not null,
        group_id  integer   not null default 0, 
        lang text not null,                            -- code iso 639-3 alpha 3 in which the articles is written
        slug text not null,                            -- "url" name of the article 
        title text not null,                           -- title of the article 
        content text not null,                         -- the content of the article itself
        locked boolean default false not null,         -- if the articles can be edited or not
        unique (lang,slug)                             -- in order to not have several articles on the same url
    );
    CREATE INDEX articles_group_id_idx ON articles(group_id);


    -- table to represent a deleted article
    -- we don't delete them totally in case we need to revert them back
    create table deleted_articles as select * from articles;
    create unique index if not exists unique_lang_slug_deleted_articles_idx ON deleted_articles(lang,slug);


    -- table to store the conflicts when someone has modified an article while
    -- someone else was already editing it
    create table conflicts (
        id integer primary key autoincrement not null,
        group_id  integer   not null default 0, 
        article_id integer not null default 0,
        lang text not null,                            -- code iso 639-3 alpha 3 in which the articles is written
        slug text not null,                            -- "url" name of the article 
        title text not null,                           -- title of the article 
        content text not null                          -- the content of the article itself
    );


    -- table storing the different version of the articles 
    create table history (
        article_id integer key not null default 0,                      -- id of the article
        version integer primary key autoincrement not null default 1, 
        lang text not null,
        slug text not null,
        title text not null,
        content text not null,
        user_id integer not null,
        edit_time timestamp default (strftime('%s', 'now')),-- when the edition has been made
        summary text not null                              -- text to explain what has been done

    );

    -- table to store information about the files uploaded
    -- on the server
    create table uploads (
        id integer primary key autoincrement not null,
        filename text not null,  -- name of the file (not path)
        created timestamp        -- when the file has been uploaded
    );

    -- table to store the salt used for the password encryption
    create table salt(
        value text not null 
    );

    -- table used for the search engine
    create virtual table search using fts4(
        slug ,
        title,
        content,
        lang,
        tokenize=porter
    );

    ---------------------------------------------
    --
    -- Triggers to keep the search table sync 
    -- with the articles tables
    --
    ---------------------------------------------
    
    -- when we update an article we delete the older one from 
    -- the search engine
    create trigger articles_bu before update on articles BEGIN
        delete from search where docid=old.id;
    end;

    -- after we've updated, we add the updated article to
    -- the search engine
    create trigger articles_au after update on articles begin
        insert into search(
            docid,
            slug,
            title,
            content,
            lang
        ) values (
            new.id,
            new.slug,
            new.title,
            new.content,
            new.lang
        );
    end;
    
    -- when delete in article, we also delete in the search engine
    create trigger articles_bd before delete on articles begin
        delete from search where docid=old.id;
    end;


    -- when we insert, we also insert in the search engine
    create trigger articles_ai after insert on articles begin
        insert into search(
            docid,
            slug,
            title,
            content,
            lang
        ) values (
            new.id,
            new.slug,
            new.title,
            new.content,
            new.lang
        );
    end;

Commit ;
