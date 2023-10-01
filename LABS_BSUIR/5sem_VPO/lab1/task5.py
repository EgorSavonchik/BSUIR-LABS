import os
import sys

def find_files_with_extension(directory, target_extension):
    if not os.path.isdir(directory):
        raise Exception(f"Указанный путь '{directory}' не является директорией.")
        #print

    out_lst = list()

    for root, _, files in os.walk(directory):
        for file in files:
            if file.endswith(target_extension):
                file_path = os.path.join(root, file)
                #print(file_path)
                out_lst.append(file_path)

    return out_lst

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Использование: python search_files.py <путь_к_папке> <расширение>")
    else:
        directory = sys.argv[1]
        target_extension = sys.argv[2]
        print(find_files_with_extension(directory, target_extension))