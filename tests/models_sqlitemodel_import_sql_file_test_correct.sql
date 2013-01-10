PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
DROP TABLE IF EXISTS test;
CREATE TABLE test (
    foo INTEGER,
    bar TEXT
);
INSERT INTO "test" VALUES(1,'toto');
INSERT INTO "test" VALUES(1,'test');
INSERT INTO "test" VALUES(1,'test');
INSERT INTO "test" VALUES(2,'foo');
COMMIT;
