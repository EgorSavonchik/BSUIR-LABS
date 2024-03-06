CREATE OR REPLACE PROCEDURE Restore_Students_Info_By_Date (date_time IN TIMESTAMP)
AS
    cur_date TIMESTAMP := SYSDATE;
BEGIN
    DELETE FROM students;
    DELETE FROM students_log WHERE date_of_action >= cur_date;
    
    FOR stud IN (SELECT * FROM students_log WHERE date_of_action <= date_time ORDER BY date_of_action ASC) LOOP
        IF stud.operation = 'INSERT' THEN
            INSERT INTO students (id, name, group_id) VALUES (stud.stud_id, stud.stud_name, stud.stud_group_id);
        ELSIF stud.operation = 'UPDATE' THEN
            UPDATE students SET group_id = stud.stud_group_id, name = stud.stud_name WHERE stud.stud_id = id;
        ELSIF stud.operation = 'DELETE' THEN
            DELETE FROM students WHERE stud.stud_id = id;
        END IF;
    END LOOP;

    DELETE FROM students_log WHERE date_of_action >= cur_date;
END;


CREATE OR REPLACE PROCEDURE Restore_Students_Info_By_Offset (date_time IN INTERVAL DAY TO SECOND)
AS
    cur_date TIMESTAMP := SYSDATE;
BEGIN
    DELETE FROM students;
    DELETE FROM students_log WHERE date_of_action >= cur_date;
    FOR stud IN (SELECT * FROM students_log WHERE date_of_action <= cur_date - date_time ORDER BY date_of_action ASC) LOOP
        IF stud.operation = 'INSERT' THEN
            INSERT INTO students (id, name, group_id) VALUES (stud.stud_id, stud.stud_name, stud.stud_group_id);
        ELSIF stud.operation = 'UPDATE' THEN
            UPDATE students SET group_id = stud.stud_group_id, name = stud.stud_name WHERE stud.stud_id = id;
        ELSIF stud.operation = 'DELETE' THEN
            DELETE FROM students WHERE stud.stud_id = id;
        END IF;
    END LOOP;

    DELETE FROM students_log WHERE date_of_action >= cur_date;
END;


CALL Restore_Students_Info_By_Date('28.02.2024 18:00:00');
CALL Restore_Students_Info_By_Offset('0 00:01:00')

SELECT * FROM STUDENTS;
SELECT * FROM STUDENTS_LOG;
DELETE FROM STUDENTS_LOG;
ALTER SESSION SET NLS_DATE_FORMAT = 'DD-MM-YYYY HH24:MI:SS';