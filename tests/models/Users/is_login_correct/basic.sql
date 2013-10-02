PRAGMA foreign_keys=OFF;
BEGIN;

DROP TABLE IF EXISTS users;
DROP TABLE IF EXISTS salt;
CREATE TABLE users (
    id INTEGER,
    username text not null unique,
    password text not null
);
CREATE TABLE salt (
    value text not null
);
INSERT INTO users VALUES(
    1,
    "username_which_exists",
    -- sha1 of password_correct + abcdef (salt defined below)
    "120beb01da5fb02dadfae02a2811324e454d0217"
);
INSERT INTO salt VALUES("abcdef");
COMMIT;

