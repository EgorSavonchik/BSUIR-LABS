CREATE OR REPLACE FUNCTION CheckEvenOddCount RETURN VARCHAR2 IS
    even_count NUMBER := 0;
    odd_count NUMBER := 0;
BEGIN
    SELECT COUNT(CASE WHEN MOD(val, 2) = 0 THEN 1 END),
           COUNT(CASE WHEN MOD(val, 2) != 0 THEN 1 END)
    INTO even_count, odd_count
    FROM MyTable;

    IF even_count > odd_count THEN
        RETURN 'TRUE';
    ELSIF even_count < odd_count THEN
        RETURN 'FALSE';
    ELSE
        RETURN 'EQUAL';
    END IF;
END;

begin
dbms_output.put_line(checkevenoddcount());
end;