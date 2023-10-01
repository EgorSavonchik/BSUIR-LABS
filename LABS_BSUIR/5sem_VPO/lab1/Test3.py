import unittest
import io
import sys
from task3 import square


class Test3(unittest.TestCase):
    def setUp(self) -> None:
        return super().setUp()
    def test1(self):
        self.assertEqual(square(12,13), 156)
    def test2(self):
        self.assertEqual(square(12,0), 0)
    def test3(self):
        self.assertEqual(square(12.45,78.3), 974.835)
    def test4(self):
        with self.assertRaises(Exception) as e:
            square(12, -13)
        self.assertEqual(str(e.exception), 'Negative height')
    def test5(self):
        with self.assertRaises(Exception) as e:
            square(-12, 13)
        self.assertEqual(str(e.exception), 'Negative width')
    def test6(self):
        with self.assertRaises(Exception) as e:
            square(-12, -13)
        self.assertEqual(str(e.exception), 'Negative width')
    def test7(self):
        with self.assertRaises(Exception) as e:
            square('-12', -13)
        self.assertEqual(str(e.exception), 'Incorrect width')
    def test8(self):
        with self.assertRaises(Exception) as e:
            square(-12, '-13')
        self.assertEqual(str(e.exception), 'Incorrect height')
    def test9(self):
        with self.assertRaises(Exception) as e:
            square('-12', '-13')
        self.assertEqual(str(e.exception), 'Incorrect width')
    def test10(self):
        with self.assertRaises(Exception) as e:
            square('asd', -13)
        self.assertEqual(str(e.exception), 'Incorrect width')
    def test11(self):
        with self.assertRaises(Exception) as e:
            square(-12, 'asd')
        self.assertEqual(str(e.exception), 'Incorrect height')
    def test12(self):
        with self.assertRaises(Exception) as e:
            square('asd', 'asd')
        self.assertEqual(str(e.exception), 'Incorrect width')

if __name__ == "__main__":
  unittest.main()