import unittest
import io
import sys
from task5 import find_files_with_extension
import random


class Test5(unittest.TestCase):
    def setUp(self) -> None:
        return super().setUp()
    def test1(self):
        dir = 'C:\\Users\\HP\\Desktop\\labs\\LABS_BSUIR\\5sem_VPO\\lab1'
        ext = 'py'

        self.assertEqual(find_files_with_extension(dir, ext), [
                                                            'C:\\Users\\HP\\Desktop\\labs\\LABS_BSUIR\\5sem_VPO\\lab1\\task1.py', 
                                                            'C:\\Users\\HP\\Desktop\\labs\\LABS_BSUIR\\5sem_VPO\\lab1\\task2.py', 
                                                            'C:\\Users\\HP\\Desktop\\labs\\LABS_BSUIR\\5sem_VPO\\lab1\\task3.py', 
                                                            'C:\\Users\\HP\\Desktop\\labs\\LABS_BSUIR\\5sem_VPO\\lab1\\task4.py', 
                                                            'C:\\Users\\HP\\Desktop\\labs\\LABS_BSUIR\\5sem_VPO\\lab1\\task5.py', 
                                                            'C:\\Users\\HP\\Desktop\\labs\\LABS_BSUIR\\5sem_VPO\\lab1\\task6.py',
                                                            'C:\\Users\\HP\\Desktop\\labs\\LABS_BSUIR\\5sem_VPO\\lab1\\Test1.py', 
                                                            'C:\\Users\\HP\\Desktop\\labs\\LABS_BSUIR\\5sem_VPO\\lab1\\Test2.py', 
                                                            'C:\\Users\\HP\\Desktop\\labs\\LABS_BSUIR\\5sem_VPO\\lab1\\Test3.py', 
                                                            'C:\\Users\\HP\\Desktop\\labs\\LABS_BSUIR\\5sem_VPO\\lab1\\Test4.py', 
                                                            'C:\\Users\\HP\\Desktop\\labs\\LABS_BSUIR\\5sem_VPO\\lab1\\Test5.py', 
                                                            'C:\\Users\\HP\\Desktop\\labs\\LABS_BSUIR\\5sem_VPO\\lab1\\Test6.py'])

    def test2(self):
        dir = 'sggerge'
        ext = 'py'

        with self.assertRaises(Exception) as e:
            find_files_with_extension(dir, ext)

        self.assertEqual(str(e.exception), f"Указанный путь '{dir}' не является директорией.")

if __name__ == "__main__":
  unittest.main()