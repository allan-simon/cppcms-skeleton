PRAGMA foreign_keys=OFF;
BEGIN;
-- some comments 
DROP TABLE IF EXISTS users;
CREATE TABLE users (
    id INTEGER, -- here 
    group_id INTEGER
);
-- and there
INSERT INTO users VALUES(1,1);
INSERT INTO users VALUES(2,2);
INSERT INTO users VALUES(3,1);
COMMIT;

