# UniqueNames
 
## Задание:
Реализуйте объект NamesHolder, которых хранит мапинг \<id> (int) - \<name> (string). У него должны быть методы:
- CreateNew: выдает новый id и присваивает ему незанятое имя вида “ObjectXXX”, XXX - число.
- Rename(id, new_name) - переименовывает объект. Отказывает, если new_name уже занято.
- Erase(id) - удаляет объект
- Get(id) - возвращает name объекта по id

Если id не найден - генерировать исключение.
Нужен также итератор для обхода Holder-а.
 
## NamesHolder docs:
Класс хранит unordered_map, в котором ключи - id и значение - имя.
Также есть unordered_set который хранит только занятые имена (нужен для быстрого поиска имен).

```c++
std::size_t create();
// Создает имя и возвращает его id.

bool rename(std::size_t id, const std::string& new_name);
// Изменяет имя по данному id. Возвращает false если имя занято.

void erase(std::size_t id);
// Удаляет имя по id.

std::string get(std::size_t id) const;
// Возвращает имя с данным id.
```

codestyle: snake_case

## Запуск:

- `make` - сборка и прогон тестов
- `make build` - сборка проекта 
- `make run` - запуск демо 
- `make clean` - удаление временных файлов 