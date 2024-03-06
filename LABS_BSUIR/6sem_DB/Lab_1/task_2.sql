DECLARE
    i NUMBER := 1;
BEGIN
    WHILE i <= 10000 LOOP
        INSERT INTO MyTable (id, val)
        VALUES (TRUNC(DBMS_RANDOM.VALUE(1, 100)), TRUNC(DBMS_RANDOM.VALUE(1, 100)));
        i := i + 1;
    END LOOP;
    COMMIT;
END;
