#include <iostream>
#include <memory>

/// U can use `enter` macro instead of writing std::cout << '\n';
#define enter cout << '\n';
//// ТЗ: функции для работы со связными списками.
//// 1. Добавление элемента. (n, value), н - необязательный парам. +
//// 2, Удаление элемента (n) если n не  подается, то удаляет ласт, возвращает удаленный элем. +
//// 3. Получение элемента. (n) - возвращает элем. if None -> Exception (ошибка доступа, почитать про exceptions) +
//// 4. Изменение элемента (n, value) - возвращает сам измененный элемент +
////
//// 1. Инвертирование
//// 2. Сортировка
//// 3. Поиск +
//// 4. конкатенация списков
//// 5. Поиск мин, макс

using std::shared_ptr;
using std::make_shared;

template<typename T>
struct Node {
    T value;
    shared_ptr<Node> next;

    Node(T value) : value(value) {};
};

template<typename T>
struct List {

    int length;
    shared_ptr<Node<T>> head;

    List() : head(nullptr), length(0) {};

    /** insert value in n position
    * @param value what insert
    * @param n in what pos need to insert leave nothing for insert in end
    **/
    shared_ptr<Node<T>> insert(T value, int n) {
        auto currentNode = head;

        if (length == 0) {
            head = make_shared<Node<T>>(value);
            length++;
            return head;
        }
        if (n < length) {
            for (int i = 0; i < n; ++i) {
                currentNode = currentNode->next;
            }
            auto newNode = currentNode->next;
            currentNode->next = make_shared<Node<T>>(value);
            currentNode->next->next = newNode;
        } else {
            for (int i = 0; i < length - 1; ++i) {
                currentNode = currentNode->next;
            }
            currentNode->next = make_shared<Node<T>>(value);
            length++;
        }
        return currentNode->next;
    }

    /** append elem in back
   * @param value to insert in end
   **/
    shared_ptr<Node<T>> append(T value) {
        return insert(value, length);
    }

    /** remove node from n position
       * @param n in what pos need to remove elem, leave nothing to remove from end
       **/
    shared_ptr<Node<T>> removeAt(int n = -1) {
        auto currentNode = head;

        if (n == -1)
            n = length;

        if (length == 0)
            return nullptr;

        if (n <= length) {
            for (int i = 0; i < n - 1; ++i)
                currentNode = currentNode->next;
            auto newNode = currentNode->next->next;
            currentNode->next = newNode;
        } else {
            for (int i = 0; i < length - 1; ++i)
                currentNode = currentNode->next;
            currentNode->next = nullptr;
        }

        length--;
        return nullptr;
    }

    /** return element that placed in position
   * @param pos element position
   **/
    int findByIndex(int pos) {
        auto currentNode = head;
        if (length == 0)
            return -1;

        if (pos <= length) {
            for (int i = 0; i < pos - 1; ++i)
                currentNode = currentNode->next;
        } else {
            for (int i = 0; i < length - 1; ++i)
                currentNode = currentNode->next;
        }
        return currentNode->value;
    }

    /** print all elements in list
    **/
    void printAll() {
        auto currentNode = head;

        for (int i = 0; i < length; ++i) {
            std::cout << currentNode->value << ' ';
            currentNode = currentNode->next;
        }
    }

    /** set element by index to new elem
   * @param value to emplace
   * @param pos emplacing index
   **/
    shared_ptr<Node<T>> setElem(int value, int pos) {
        auto currentNode = head;

        if (length == 0)
            return nullptr;

        if (pos <= length) {
            for (int i = 0; i < pos - 1; ++i)
                currentNode = currentNode->next;
        } else {
            for (int i = 0; i < length - 1; ++i)
                currentNode = currentNode->next;
        }
        currentNode->next->value = value;
        return currentNode->next;
    }
};

int main() {
    using namespace std;

    return 0;
}