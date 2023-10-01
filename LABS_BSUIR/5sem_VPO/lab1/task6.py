import os
import requests
import sys


def download_file(url):
    response = requests.get(url, stream=True)

    if response.status_code != 200:
        raise Exception("Ошибка при скачивании файла: {0}".format(response.status_code))

    file_name = os.path.basename(response.url)

    return response.content, file_name

def save_file(file_data, file_name, output_dir):
    file_path = os.path.join(output_dir, file_name)

    with open(file_path, "wb") as f:
        f.write(file_data)

    print("Сохранение файла: {0}".format(file_path))

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("В терминале: python task6.py <url> <output_dir>")
        sys.exit(1)

    url = sys.argv[1]
    output_dir = sys.argv[2]

    save_file(*download_file(url), output_dir)