import unittest
import io
import sys
import os
from task4 import write_html
import random
from io import StringIO
from unittest.mock import patch


class Test4(unittest.TestCase):
    def setUp(self) -> None:
        self.html = write_html()
        return super().setUp()
    
    def test_write_html_file(self):
        # Вызываем функцию для создания HTML-файла
        result = write_html()

        # Проверяем, что файл существует
        self.assertTrue(os.path.exists("gradient.html"))

        # Удаляем созданный файл после теста
        os.remove("gradient.html")
    
    @patch('sys.stdout', new_callable=StringIO)
    def test_write_html(self, mock_stdout):
        write_html()
        output = mock_stdout.getvalue().strip()
        expected_output = "HTML-файл с градиентом создан: gradient.html"
        self.assertEqual(output, expected_output)

if __name__ == "__main__":
  unittest.main()