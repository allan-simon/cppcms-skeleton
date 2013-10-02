PRAGMA foreign_keys=OFF;
BEGIN;

DROP TABLE IF EXISTS users;
CREATE TABLE users (
    id INTEGER, -- here 
    email text not null unique
);
-- and there

INSERT INTO users VALUES(1,"username.exists@example.com");
COMMIT;

