
import unittest
import os
from unittest.mock import patch
from task6 import *

class Test6(unittest.TestCase):
    def setUp(self) -> None:
        return super().setUp()
    
    def test1(self):
        url = 'https://www.python.org/static/community_logos/python-logo-master-v3-TM.png'
        path = 'qwe'

        res, file_name = download_file(url)
    
        self.assertEqual(file_name, "python-logo-master-v3-TM.png")
        self.assertTrue(res != None)
        

    def test2(self):
        url = 'https://www.python.org/static/community_logos/python-logo-master-v3-TM.png'
        path = 'qwe'

        res, file_name = download_file(url)
        save_file(res, file_name, path)

        self.assertTrue(os.path.exists(os.path.join(path , file_name)))

    @patch('requests.get')
    def test_download_file(self, mock_get):
        mock_response = mock_get.return_value
        mock_response.status_code = 200
        mock_response.url = 'https://www.example.com/test.txt'
        mock_response.content = b'This is a test'

        content, file_name = download_file('https://www.example.com/test.txt')

        self.assertEqual(file_name, 'test.txt')
        self.assertEqual(content, b'This is a test')

    @patch('requests.get')
    @patch('os.path.join')
    @patch('builtins.open', create=True)
    def test_save_file(self, mock_open, mock_os_path_join, mock_get):
        mock_response = mock_get.return_value
        mock_response.status_code = 200
        mock_response.url = 'https://www.example.com/test.txt'
        mock_response.content = b'This is a test'

        mock_os_path_join.return_value = 'output_dir/test.txt'

        save_file(b'This is a test', 'test.txt', 'output_dir')

        mock_open.assert_called_once_with('output_dir/test.txt', 'wb')
        #mock_open.return_value.write.assert_called_once_with(b'This is a test')


if __name__ == "__main__":
  unittest.main()