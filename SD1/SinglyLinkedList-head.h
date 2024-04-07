#pragma once
#include <iostream>
#include "List.h" 

using namespace std;

template<typename T>
class Node{ // Definicja klasy w�z�a
public:
    T value;  // Dane przechowywane w w�le
    Node* next; // Wska�nik na nast�pny w�ze� w li�cie
    // Konstruktor inicjalizuj�cy w�ze� warto�ci� i opcjonalnym wska�nikiem na nast�pny w�ze�
    Node(T val, Node* nxt = nullptr) : value(val), next(nxt) {
    }
};
template<typename T>
// Klasa dziedziczy po interfejsie List

class SinglyLinkedList_head : public List<T>{
private:
    Node<T>* head; // G�owa listy, czyli pierwszy w�ze�
    int listsize; // Rozmiar listy (liczba w�z��w)
    // Konstruktor domy�lny inicjalizuj�cy list� jako pust�
public:
    SinglyLinkedList_head() : head(nullptr), listsize(0){
    }
    // Destruktor zwalniaj�cy zasoby listy
    virtual ~SinglyLinkedList_head(){
        Node<T>* current = head; // Zaczyna od g�owy listy
        while (current != nullptr){ // Dop�ki istniej� w�z�y Zapami�tuje wska�nik na nast�pny w�ze�
// Usuwa bie��cy w�ze�
// Przechodzi do nast�pnego w�z�a
            Node<T>* next =current->next;
            delete current;
            current =next;
        }
    }
    // Metoda dodaj�ca element na ko�cu listy
    void push_back(T element){
        Node<T>* newNode = new Node<T>(element);
        if (head == nullptr){// Je�li lista jest pusta
            head =newNode;
        }
        else {// Je�li lista nie jest pusta
            Node<T>* t = head;
            while (t->next != nullptr){
                t = t->next;
            }
            t->next = newNode;
        }
        listsize++;
    }
    // Metoda dodaj�ca element na pocz�tku listy
    void push_front(T element){
        head = new Node<T>(element, head);
        listsize++;
    }
    // Metoda dodaj�ca element w wybranym miejscu listy
    void addElement(T element, int index){
        if (index < 0 or index > listsize){// Sprawdza poprawno�� indeksu
            cout << "zly index" << endl;
            return;
        }
        if (index == 0){// Je�li indeks r�wna si� 0, dodaje na pocz�tku
            push_front(element);
        }
        else{// W przeciwnym razie znajduje odpowiednie miejsce w li�cie
            Node<T>* t = head;
            for (int i = 1; i < index; i++){
                t = t->next;
            }
            t->next = new Node<T>(element, t->next);
            listsize++;
        }
    }
    // Metoda zwracaj�ca element na podanym indeksie
    T getElement(int index){
        if (index < 0 or index >= listsize){// Sprawdza poprawno�� indeksu
            cout<<"Index out of range"<<endl;
            return T{};// Zwraca domy�ln� warto�� typu T
        }
        Node<T>* t = head;
        for (int i = 0; i < index; i++){
            t = t->next;
        }
        return t->value;
    }
    // Metoda wyszukuj�ca element w li�cie i zwracaj�ca jego indeks (lub -1, je�li nie znaleziono)

    int findElement(T element) const{
        Node<T>* t = head;
        int index = 0;
        while (t != nullptr){
            if (t->value == element){// Je�li znajdzie element Zwraca jego indeks
                return index;
            }
            t = t->next;
            index++;
        }
        return -1; //nieznalaz�
    }
    // Metoda zwracaj�ca rozmiar listy
    int getSize() const{
        return listsize;
    }
    // Metoda sprawdzaj�ca, czy lista jest pusta
    bool isEmpty() const{
        return head == nullptr;
    }
};
