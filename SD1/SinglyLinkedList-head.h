#pragma once
#include <iostream>
#include "List.h" 

using namespace std;

template<typename T>
class Node{ // Definicja klasy wêz³a
public:
    T value;  // Dane przechowywane w wêŸle
    Node* next; // WskaŸnik na nastêpny wêze³ w liœcie
    // Konstruktor inicjalizuj¹cy wêze³ wartoœci¹ i opcjonalnym wskaŸnikiem na nastêpny wêze³
    Node(T val, Node* nxt = nullptr) : value(val), next(nxt) {
    }
};
template<typename T>
// Klasa dziedziczy po interfejsie List

class SinglyLinkedList_head : public List<T>{
private:
    Node<T>* head; // G³owa listy, czyli pierwszy wêze³
    int listsize; // Rozmiar listy (liczba wêz³ów)
    // Konstruktor domyœlny inicjalizuj¹cy listê jako pust¹
public:
    SinglyLinkedList_head() : head(nullptr), listsize(0){
    }
    // Destruktor zwalniaj¹cy zasoby listy
    virtual ~SinglyLinkedList_head(){
        Node<T>* current = head; // Zaczyna od g³owy listy
        while (current != nullptr){ // Dopóki istniej¹ wêz³y Zapamiêtuje wskaŸnik na nastêpny wêze³
// Usuwa bie¿¹cy wêze³
// Przechodzi do nastêpnego wêz³a
            Node<T>* next =current->next;
            delete current;
            current =next;
        }
    }
    // Metoda dodaj¹ca element na koñcu listy
    void push_back(T element){
        Node<T>* newNode = new Node<T>(element);
        if (head == nullptr){// Jeœli lista jest pusta
            head =newNode;
        }
        else {// Jeœli lista nie jest pusta
            Node<T>* t = head;
            while (t->next != nullptr){
                t = t->next;
            }
            t->next = newNode;
        }
        listsize++;
    }
    // Metoda dodaj¹ca element na pocz¹tku listy
    void push_front(T element){
        head = new Node<T>(element, head);
        listsize++;
    }
    // Metoda dodaj¹ca element w wybranym miejscu listy
    void addElement(T element, int index){
        if (index < 0 or index > listsize){// Sprawdza poprawnoœæ indeksu
            cout << "zly index" << endl;
            return;
        }
        if (index == 0){// Jeœli indeks równa siê 0, dodaje na pocz¹tku
            push_front(element);
        }
        else{// W przeciwnym razie znajduje odpowiednie miejsce w liœcie
            Node<T>* t = head;
            for (int i = 1; i < index; i++){
                t = t->next;
            }
            t->next = new Node<T>(element, t->next);
            listsize++;
        }
    }
    // Metoda zwracaj¹ca element na podanym indeksie
    T getElement(int index){
        if (index < 0 or index >= listsize){// Sprawdza poprawnoœæ indeksu
            cout<<"Index out of range"<<endl;
            return T{};// Zwraca domyœln¹ wartoœæ typu T
        }
        Node<T>* t = head;
        for (int i = 0; i < index; i++){
            t = t->next;
        }
        return t->value;
    }
    // Metoda wyszukuj¹ca element w liœcie i zwracaj¹ca jego indeks (lub -1, jeœli nie znaleziono)

    int findElement(T element) const{
        Node<T>* t = head;
        int index = 0;
        while (t != nullptr){
            if (t->value == element){// Jeœli znajdzie element Zwraca jego indeks
                return index;
            }
            t = t->next;
            index++;
        }
        return -1; //nieznalaz³
    }
    // Metoda zwracaj¹ca rozmiar listy
    int getSize() const{
        return listsize;
    }
    // Metoda sprawdzaj¹ca, czy lista jest pusta
    bool isEmpty() const{
        return head == nullptr;
    }
};
