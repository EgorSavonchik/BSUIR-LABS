CREATE OR REPLACE FUNCTION GenerateInsertCommand(
    p_id NUMBER
) RETURN VARCHAR2 IS
    v_val_value MyTable.val%TYPE;
    v_insert_command VARCHAR2(1000);
BEGIN
    SELECT val INTO v_val_value FROM MyTable WHERE id = p_id AND ROWNUM = 1;
    
    v_insert_command := 'INSERT INTO MyTable (id, val) VALUES (' || p_id || ', ' || v_val_value || ');';
    
    DBMS_OUTPUT.PUT_LINE('Сгенерированная команда:');
    DBMS_OUTPUT.PUT_LINE(v_insert_command);
    
    RETURN v_insert_command;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('Данные для указанного ID отсутствуют в таблице.');
        RETURN NULL;
END;

begin
dbms_output.put_line(GenerateInsertCommand(2));
end;