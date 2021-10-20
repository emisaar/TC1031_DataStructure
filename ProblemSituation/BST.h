#include <iostream>

using namespace std;

template<typename T>
class Nodo{
    private:
        T data;
        Nodo<T>* left;
        Nodo<T>* right;
        template<typename U>
        friend class BST;
    public:
        Nodo(T data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};


template<typename T>
class BST{
private:
    Nodo<T> * root;

    void insert(Nodo<T> * & nodo, T data){
        if(nodo== NULL){
            nodo = new Nodo<T>(data);
        }else{
            if(data < nodo->data){
            insert(nodo->left, data);
            }else if(data > nodo->data){
            insert(nodo->right, data);
            }   
        }
    }

        bool search(Nodo <T> * & nodo, T data){
            if(nodo == NULL){
                return false;
            }else if(nodo->data == data){
                return true;
            }else if (data < nodo->data){
                return search(nodo->left, data);
            }else{
                return search(nodo->right, data);
            }
        } 		

    void preOrden(Nodo<T> * & nodo){
    if(nodo == NULL)
        return;
        cout << nodo-> data << ":";
        preOrden(nodo->left);
        preOrden(nodo->right);
    
    }

    void postOrden(Nodo<T> * & nodo){
    if(nodo == NULL)
        return;
        postOrden(nodo->left);
        postOrden(nodo->right);
        cout << nodo-> data << ":";
    
    } 
    void inOrden(Nodo<T> * & nodo){
    if(nodo == NULL)
        return;
        inOrden(nodo->left);
        cout << nodo-> data << ":";
        inOrden(nodo->right);
    } 
    int lenght(Nodo<T> * &nodo){
    if(nodo == NULL){
        return 0;
    }else{
        return 1 + lenght(nodo->left) + lenght(nodo->right);
    }
    }

    T max(Nodo<T> * &nodo){
    if(nodo == NULL){
        throw -1;
    }
    Nodo<T> * auxiliar = nodo;
    while(auxiliar->right != NULL){
        auxiliar = auxiliar->right;
    }
    return auxiliar->data;
    }

    T min(Nodo<T> * &nodo){
    if(nodo == NULL){
        throw -1;
    }
    Nodo<T> * auxiliar = nodo;
    while(auxiliar->left != NULL){
        auxiliar = auxiliar->left;
    }
    return auxiliar->data;
    }

        // Villians
    void levels(Nodo<T> * nodo){
    LinkedList<Nodo<T>*> fila = LinkedList<Nodo<T>*>();
    fila.queue(nodo);

    while(!fila.is_empty()){
        Nodo<T> * auxiliar;
        auxiliar = fila.dequeue();
        cout << auxiliar -> data << ":";
        if(auxiliar -> left != NULL){
        fila.queue(auxiliar -> left);
        }
                if(auxiliar->right != NULL){
        fila.queue(auxiliar -> right);
        }
    }
    }

        // Missions
    T height(Nodo <T> * &nodo){
    int Izquierda;
    int Derecha;
    
    if(nodo == NULL){
        return 0;
    
    }else{
        Izquierda = height(nodo -> left);
        Derecha = height(nodo -> right);
        
        if(Izquierda > Derecha){
        return Izquierda + 1;
        
        }else{
        return Derecha + 1;
        }
    }
    }

        // Sequels
    void ancestors(Nodo<T> * nodo, T dato){
        if(nodo != NULL){
            if(dato < nodo->data){
                cout << nodo->data << ":";
                ancestors(nodo->left, dato);
            }else if (dato > nodo->data){
                cout << nodo->data << ":";
                ancestors(nodo->right, dato);
            }
        }
    }

        // Gadgets
    int level(Nodo<T> * &nodo, T dato){
    int count = 0;

    if (nodo == NULL){
                return 0;
            } else{
        Nodo<T> * auxiliar = nodo;

        while(auxiliar -> data != dato){
        if(dato < auxiliar -> data){
            auxiliar = auxiliar -> left;
        }else if(dato > auxiliar -> data){
            auxiliar = auxiliar -> right;
        }
        count ++; 
        }
        return count;
    }
    }

    void flatten(Nodo<T> * &nodo, LinkedList<T> &lista){
    if(nodo == NULL){
        return;
    } 

        lista.addLast(nodo->data);
        flatten(nodo->left, lista);
        flatten(nodo->right, lista);
    }
        

public:
    BST(){
    root = NULL;
    }

    void insert(T data){
    if(isEmpty()){
        root = new Nodo<T>(data);
    }else{
        insert(root, data);
    }
    }
    
        bool search(T data){
            return search(root, data);
        }
    
        bool isEmpty(){
    return root == NULL;
    }
    void preOrden(){
    preOrden(root);
    }

    void postOrden();
    void inOrden(){
    inOrden(root);
    }

    // 1. Escribe una funcion que regresa cuantos nodos hay en el BST.
    int lenght(){
    return lenght(root);
    }

    // 2. Escribe una funcion que regresa el elemento mayor del  BST.
    T max(){
    return max(root);
    }

    // 3. Escribe una funcion que regresa el elemento menor del  BST.
    T min(){
            return min(root);
        }

        // Villians
        void levels(){
    levels(root);
    }

        // Missions
    T height(){
    return height(root);
    }

        // Sequels
        void ancestors(T dato){
            return ancestors(root, dato);
        }

        // Gadgets
        int level(T dato){
            return level(root, dato);
        }

        // loves
    LinkedList<T> flatten() {
            LinkedList<T> lista;
            flatten(root, lista);
            return lista;
    }   
};