#include <iostream>

using namespace std;

template<typename T>
class NodoLista{
    private:
        T data;
        NodoLista<T>* next;
        NodoLista<T>* prev;
        template<typename U>
        friend class LinkedList;
    public:
        NodoLista(T data){
            this->data = data;//O(1)
            next = NULL;//O(1)
            prev = NULL;
        }
};

template<typename T>
class LinkedList;

template<typename T>
ostream & operator << (ostream &,const LinkedList<T> &);


template<typename T>
class LinkedList{
private:
    NodoLista<T> * head;
    NodoLista<T> * last;
        // O(n)
    int lengthRecursive(NodoLista<T> * h )
    {
    if (h == NULL) 
        return 0;
    else
        return 1 + lengthRecursive(h->next);
    }

public:
    LinkedList(){
    head = last = NULL;
    }

        // O(1)
    void addFirst(T dato){
    NodoLista<T> * nuevo = new NodoLista<T>(dato);
    if(head == NULL&&last == NULL){// si es vacía la lista
        head = last = nuevo;
    }else{ 
        nuevo->next = head;
        head->prev = nuevo;
        head = nuevo;
    }
    }
    
    // O(1)
    void addLast(T dato){
        NodoLista<T> * nuevo = new NodoLista<T>(dato);
        if(head == NULL){
            head= last = nuevo; //addFirst(dato)
        }
        else{ 
            last->next = nuevo;
            nuevo->prev = last;
            last = nuevo;
        }
    
    }

        // O(n)
    void reverse(){
    NodoLista<T> * auxiliar = last;
    while(auxiliar != NULL){
        cout << auxiliar->data << ":";
        auxiliar = auxiliar->prev;
    }
    cout << endl;

    }

        // O(1)
    int length (){
        return lengthRecursive(head);   
    }

        // O(1)
    T getFirst(){
    if(head != NULL){
        return head->data;
    }else{
        return T();
    }
    }

        // O(n)
    int size(){
    int count = 0;
        NodoLista<T> * temp = head;
        while(temp != NULL){
        temp = temp->next;
        count++;
        }  
    return count;
    }

        // O(1)
    bool is_empty(){
    return head == NULL;
    }

        // O(1)
    T remove_front(){
    if(is_empty()){
        throw -1;
    }else if(head == last){
        // 1 NodoLista
        T dato = head->data;// sacar dato
        delete head;                    // borrar NodoLista
        head = last = NULL;
        return dato;
    }else{
        // minimo 2 NodoListas
        T dato = head->data;
        head = head->next;
        delete head->prev;
        head->prev = NULL;
        return dato;
    }
    }

        // O(1)
    T remove_last(){
    if(is_empty()){
        throw -1;
    }else if(head == last){
        // 1 NodoLista
        T dato = head->data;// sacar dato
        delete head;                    // borrar NodoLista
        head = last = NULL;
        return dato;
    }else{
        // minimo 2 NodoListas
        T dato = last->data;
        last = last->prev;
        delete last->next;
        last->next = NULL;
        return dato;
    }

    }

    friend ostream& operator<< <T> (ostream &, const LinkedList<T>&);

        // O(1)
    void push(T dato){
        addFirst(dato);
    }

        // O(n)
    T pop(){
    return remove_front();
    }

        // O(1)
    T peek(){
        if(is_empty()){
        throw -1;
        }else{
        return head->data;
        }
    }

        // O(1)
    void queue(T dato){
        addLast(dato);
    }

        // O(1)
    T dequeue(){
    return remove_front();
    }

        // O(n)
    T dequeueMax(){
    if(is_empty()){
        return T();
    }else if(head == last){
        T dato = head->data;
        delete head;
        head = last = NULL;
        return dato;
    }else{
        NodoLista<T> * temp = head;
        NodoLista<T> * aux = head;
        // T dato = temp->data;

        while(temp != NULL){
            if(temp->data > aux->data){
            aux = temp;
            }
        temp = temp->next;
        }

        T datoMax = aux->data;

        if(aux==last){
            return remove_last();
        }else if(aux == head){
            return remove_front();
        }else{
            NodoLista<T> * previous = aux->prev;
            NodoLista<T> * following = aux->next;
            
            delete previous->next;
            previous->next = NULL;

            previous->next = following;
            following->prev = aux->prev;
            return datoMax;
        }
    } 
    }

        // O(n)
    T dequeueMin(){
    if(is_empty()){
            return T();
        }else if(head == last){
            T dato = head->data;
            delete head;
            head = last = NULL;
            return dato;
        }else{
            NodoLista<T> * temp = head;
            NodoLista<T> * aux = head;
            // T dato = temp->data;

            while(temp != NULL){
                if(temp->data < aux->data){
                    aux = temp;
                }
                temp = temp->next;
            }

            T datoMin = aux->data;

                if(aux==last){
                    return remove_last();
                }else if(aux == head){
                    return remove_front();
                }else{
                    NodoLista<T> * previous = aux->prev;
                    NodoLista<T> * following = aux->next;
                
                delete previous->next;
                previous->next = NULL;

                previous->next = following;
                following->prev = aux->prev;
                return datoMin;
            }
        } 
    }

};

template<typename T>
ostream& operator<< (ostream & salida, const LinkedList<T>& lista){
    NodoLista<T> * auxiliar = lista.head;
    while(auxiliar != NULL){
        salida << auxiliar->data << ":";
        auxiliar = auxiliar->next;
    }
    return salida;

}