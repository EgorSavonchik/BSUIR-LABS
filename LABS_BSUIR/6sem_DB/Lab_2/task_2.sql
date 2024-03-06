-- ������� ��� �������� ������������ ID ����� �������� � ����������� ������ � ������� STUDENTS
CREATE OR REPLACE TRIGGER Students_UniqueID
BEFORE INSERT OR UPDATE ON STUDENTS
FOR EACH ROW
DECLARE
    id_count NUMBER;
BEGIN
    IF :NEW.ID IS NOT NULL THEN
        -- ���������, �������� �� �������� �������������� � ����� ������
        IF INSERTING OR (:OLD.ID <> :NEW.ID) THEN
            SELECT COUNT(*) INTO id_count FROM STUDENTS WHERE ID = :NEW.ID;
            IF id_count > 0 THEN
                RAISE_APPLICATION_ERROR(-20001, '��� �������� ������ ���� ����������.');
            END IF;
        END IF;
    END IF;
END;

-- ������� ��� ��������� ����������������� ����� ��� ������� ������ � ������� STUDENTS
CREATE OR REPLACE TRIGGER Students_AutoIncrement
BEFORE INSERT ON STUDENTS
FOR EACH ROW
BEGIN
    IF :NEW.ID IS NULL THEN
        SELECT NVL(MAX(ID), 0) + 1 INTO :NEW.ID FROM STUDENTS;
    END IF;
END;


-- ������� ��� �������� ������������ ���� NAME ����� �������� � ����������� ������ � ������� GROUPS
CREATE OR REPLACE TRIGGER Groups_UniqueName
BEFORE INSERT OR UPDATE ON GROUPS
FOR EACH ROW
DECLARE
    name_count NUMBER;
BEGIN
    IF :NEW.NAME IS NOT NULL THEN
        -- ���������, �������� �� �������� ����� � ����� ������
        IF INSERTING OR (:OLD.NAME <> :NEW.NAME) THEN
            SELECT COUNT(*) INTO name_count FROM GROUPS WHERE NAME = :NEW.NAME;
            IF name_count > 0 THEN
                RAISE_APPLICATION_ERROR(-20002, '�������� ������ ������ ���� ����������.');
            END IF;
        END IF;
    END IF;
END;


-- ������� ��� �������� ������������ ID ����� �������� � ����������� ������ � ������� GROUPS
CREATE OR REPLACE TRIGGER Groups_UniqueID
BEFORE INSERT OR UPDATE ON GROUPS
FOR EACH ROW
DECLARE
    id_count NUMBER;
BEGIN
    IF :NEW.ID IS NOT NULL THEN
        -- ���������, �������� �� �������� �������������� � ����� ������
        IF INSERTING OR (:OLD.ID <> :NEW.ID) THEN
            SELECT COUNT(*) INTO id_count FROM GROUPS WHERE ID = :NEW.ID;
            IF id_count > 0 THEN
                RAISE_APPLICATION_ERROR(-20002, '��� ������ ������ ���� ����������.');
            END IF;
        END IF;
    END IF;
END;


-- ������� ��� ��������� ����������������� ����� ��� ������� ������ � ������� GROUPS
CREATE OR REPLACE TRIGGER Groups_AutoIncrement
BEFORE INSERT ON GROUPS
FOR EACH ROW
BEGIN
    IF :NEW.ID IS NULL THEN
        SELECT NVL(MAX(ID), 0) + 1 INTO :NEW.ID FROM GROUPS;
    END IF;
END;