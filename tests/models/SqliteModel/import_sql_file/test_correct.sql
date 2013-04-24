PRAGMA foreign_keys=OFF;
BEGIN;
-- some comments 
DROP TABLE IF EXISTS test;
CREATE TABLE test (
    foo INTEGER, -- here 
    bar TEXT
);
-- and there
INSERT INTO "test" VALUES(1,'toto');
INSERT INTO "test" VALUES(1,'test');
INSERT INTO "test" VALUES(1,'test');
INSERT INTO "test" VALUES(2,'foo');
COMMIT;

