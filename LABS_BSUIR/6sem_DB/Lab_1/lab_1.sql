CREATE OR REPLACE FUNCTION CalculateAnnualCompensation(
    p_monthly_salary NUMBER,
    p_annual_bonus_percent NUMBER
) RETURN NUMBER IS
    v_annual_compensation NUMBER;
BEGIN
    IF p_monthly_salary <= 0 OR p_annual_bonus_percent < 0 THEN
        RAISE_APPLICATION_ERROR(-20001, 'Некорректные данные ввода');
    END IF;
    
    v_annual_compensation := (1 + p_annual_bonus_percent / 100) * 12 * p_monthly_salary;
    
    RETURN v_annual_compensation;
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Ошибка: ' || SQLERRM);
        RETURN NULL;
END CalculateAnnualCompensation;

BEGIN
    DBMS_OUTPUT.PUT_LINE(CalculateAnnualCompensation(3000, 10));
END;

CREATE OR REPLACE TRIGGER MyTable_DeleteTrigger
BEFORE DELETE ON MyTable
FOR EACH ROW
BEGIN
    DBMS_OUTPUT.PUT_LINE('Запись с ID ' || :OLD.id || ' будет удалена из таблицы MyTable.');
END;

EXEC InsertRecord(10001, 100);
SELECT * FROM mytable where id = 10001;
EXEC UpdateRecord(10001, 200);
SELECT * FROM mytable where id = 10001;
EXEC DeleteRecord(10001);
SELECT * FROM mytable where id = 10001;