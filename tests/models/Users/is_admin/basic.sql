PRAGMA foreign_keys=OFF;
BEGIN;

DROP TABLE IF EXISTS users;
DROP TABLE IF EXISTS salt;
CREATE TABLE users (
    id integer primary key autoincrement not null,
    username text not null unique,
    email text not null unique,
    group_id integer not null,
    password text not null,
    since integer not null
);
CREATE TABLE salt (
    value text not null
);
COMMIT;

