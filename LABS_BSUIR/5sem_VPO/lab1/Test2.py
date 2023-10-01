import unittest
import io
import sys
from task2 import print_people_list, calculate_age_statistics, input_people_data
from unittest.mock import patch, MagicMock
from io import StringIO


class TestPrintPeopleListAndCalculateAgeStatistics(unittest.TestCase):

    def test_print_people_list(self):
        people = [("John", "Doe", 25), ("Alice", "Smith", 30), ("Bob", "Johnson", 40)]

        with patch('sys.stdout', new_callable=StringIO) as mock_stdout:
            print_people_list(people)
            printed_output = mock_stdout.getvalue()

        expected_output = "Список людей:\nDoe John 25\nSmith Alice 30\nJohnson Bob 40\n"
        self.assertEqual(printed_output, expected_output)

    def test_calculate_age_statistics(self):
        people = [("John", "Doe", 25), ("Alice", "Smith", 30), ("Bob", "Johnson", 40)]

        result = calculate_age_statistics(people)

        expected_result = "Самый маленький возраст: 25 лет\nСамый большой возраст: 40 лет\nСредний возраст: 31.67 лет"
        self.assertEqual(result, expected_result)

    def test_calculate_age_statistics_no_data(self):
        people = []

        result = calculate_age_statistics(people)

        expected_result = "Нет данных о людях."
        self.assertEqual(result, expected_result)

    @patch('sys.stdout', new_callable=StringIO)
    @patch('builtins.input', side_effect=['John', 'Doe', '25', 'Alice', 'Smith', '30', ''])
    def test_input_people_data(self, mock_input, mock_stdout):
        with patch('builtins.print'):  # Игнорируем вывод print
            result = input_people_data()
            
        self.assertEqual(mock_input.call_count, 7)  # Проверяем, что input был вызван 7 раз
        self.assertEqual(result, [('John', 'Doe', 25), ('Alice', 'Smith', 30)])  # Проверяем результат функции


if __name__ == "__main__":
  unittest.main()