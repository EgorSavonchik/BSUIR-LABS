def input_people_data():
    people = []
    while True:
        first_name = input("Введите имя (или нажмите Enter для завершения ввода): ")
        if not first_name:
            break
        last_name = input("Введите фамилию: ")

        while True:
            age_str = input("Введите возраст: ")
            if age_str.isdigit():
                age = int(age_str)
                if age >= 0:
                    break
                else:
                    print("Возраст должен быть положительным числом.")
            else:
                print("Введите корректный возраст (целое положительное число).")

        # Добавляем информацию о человеке в список
        people.append((first_name, last_name, age))

    return people


def print_people_list(people):
    if people:
        # Выводим список всех людей в формате "Фамилия Имя Возраст"
        print("Список людей:")
        for person in people:
            print(f"{person[1]} {person[0]} {person[2]}")
    else:
        print("Нет данных о людях.")


def calculate_age_statistics(people):
    if not people:
        return "Нет данных о людях."

    # Вычисляем минимальный, максимальный и средний возраст
    ages = [person[2] for person in people]
    min_age = min(ages)
    max_age = max(ages)
    average_age = sum(ages) / len(ages)

    # Возвращаем статистику в виде строки
    return f"Самый маленький возраст: {min_age} лет\nСамый большой возраст: {max_age} лет\nСредний возраст: {average_age:.2f} лет"




if __name__ == "__main__":
    people = input_people_data()
    print_people_list(people)
    statistics = calculate_age_statistics(people)
    print(statistics)