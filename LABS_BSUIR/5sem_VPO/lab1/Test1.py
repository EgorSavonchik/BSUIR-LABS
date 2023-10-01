import unittest
import io
import sys
from task1 import func

class Test1(unittest.TestCase):
    def setUp(self):
        self.capturedOutput = io.StringIO()
        sys.stdout = self.capturedOutput 
        func()  
        sys.stdout = sys.__stdout__
        self.out_lst = self.capturedOutput.getvalue().split('\n')
    def test_1(self):
        self.assertEqual(len(self.out_lst) - 1, 3)
    def test_2(self):
        self.assertEqual(self.out_lst[0],"Hello, world!")
    def test_3(self):
        self.assertEqual(self.out_lst[1], "Andhiagain!")
    def test_4(self):
        self.assertEqual(self.out_lst[2].count('!'), len(self.out_lst[2]))
    def test_5(self):
        self.assertGreaterEqual(self.out_lst[2].count('!'), 5)
    def test_6(self):
        self.assertLessEqual(self.out_lst[2].count('!'), 50)

if __name__ == "__main__":
  unittest.main()