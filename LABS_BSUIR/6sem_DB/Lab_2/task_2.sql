-- Триггер для проверки уникальности ID перед вставкой и обновлением записи в таблице STUDENTS
CREATE OR REPLACE TRIGGER Students_UniqueID
BEFORE INSERT OR UPDATE ON STUDENTS
FOR EACH ROW
DECLARE
    id_count NUMBER;
BEGIN
    IF :NEW.ID IS NOT NULL THEN
        -- Проверяем, меняется ли значение идентификатора в новой записи
        IF INSERTING OR (:OLD.ID <> :NEW.ID) THEN
            SELECT COUNT(*) INTO id_count FROM STUDENTS WHERE ID = :NEW.ID;
            IF id_count > 0 THEN
                RAISE_APPLICATION_ERROR(-20001, 'Код студента должен быть уникальным.');
            END IF;
        END IF;
    END IF;
END;

-- Триггер для генерации автоинкрементного ключа при вставке записи в таблицу STUDENTS
CREATE OR REPLACE TRIGGER Students_AutoIncrement
BEFORE INSERT ON STUDENTS
FOR EACH ROW
BEGIN
    IF :NEW.ID IS NULL THEN
        SELECT NVL(MAX(ID), 0) + 1 INTO :NEW.ID FROM STUDENTS;
    END IF;
END;


-- Триггер для проверки уникальности поля NAME перед вставкой и обновлением записи в таблице GROUPS
CREATE OR REPLACE TRIGGER Groups_UniqueName
BEFORE INSERT OR UPDATE ON GROUPS
FOR EACH ROW
DECLARE
    name_count NUMBER;
BEGIN
    IF :NEW.NAME IS NOT NULL THEN
        -- Проверяем, меняется ли значение имени в новой записи
        IF INSERTING OR (:OLD.NAME <> :NEW.NAME) THEN
            SELECT COUNT(*) INTO name_count FROM GROUPS WHERE NAME = :NEW.NAME;
            IF name_count > 0 THEN
                RAISE_APPLICATION_ERROR(-20002, 'Название группы должно быть уникальным.');
            END IF;
        END IF;
    END IF;
END;


-- Триггер для проверки уникальности ID перед вставкой и обновлением записи в таблице GROUPS
CREATE OR REPLACE TRIGGER Groups_UniqueID
BEFORE INSERT OR UPDATE ON GROUPS
FOR EACH ROW
DECLARE
    id_count NUMBER;
BEGIN
    IF :NEW.ID IS NOT NULL THEN
        -- Проверяем, меняется ли значение идентификатора в новой записи
        IF INSERTING OR (:OLD.ID <> :NEW.ID) THEN
            SELECT COUNT(*) INTO id_count FROM GROUPS WHERE ID = :NEW.ID;
            IF id_count > 0 THEN
                RAISE_APPLICATION_ERROR(-20002, 'Код группы должен быть уникальным.');
            END IF;
        END IF;
    END IF;
END;


-- Триггер для генерации автоинкрементного ключа при вставке записи в таблицу GROUPS
CREATE OR REPLACE TRIGGER Groups_AutoIncrement
BEFORE INSERT ON GROUPS
FOR EACH ROW
BEGIN
    IF :NEW.ID IS NULL THEN
        SELECT NVL(MAX(ID), 0) + 1 INTO :NEW.ID FROM GROUPS;
    END IF;
END;