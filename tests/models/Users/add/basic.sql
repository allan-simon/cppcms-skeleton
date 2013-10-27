PRAGMA foreign_keys=OFF;
BEGIN;

DROP TABLE IF EXISTS users;
DROP TABLE IF EXISTS salt;
CREATE TABLE users (
    id INTEGER,
    username text not null unique,
    email text not null unique,
    permission integer not null,
    password text not null,
    since integer not null
);
CREATE TABLE salt (
    value text not null
);
INSERT INTO users VALUES(
    1,
    "old user",
    "old@example.com",
    0,
    -- sha1 of password_correct + abcdef (salt defined below)
    "120beb01da5fb02dadfae02a2811324e454d0217",
    datetime("NOW")
);
INSERT INTO salt VALUES("abcdef");
COMMIT;

