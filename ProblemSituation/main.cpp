#include <iostream>
#include <fstream> // leer el archivo
#include <sstream>// tokenizar el string de cada registro
#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

#include "LinkedList.h"
#include "BST.h"
#include "Servidor.h"

using namespace std;

//MENU functions
// void createServerBST(LinkedList<Servidor> &loadedList, BST<LinkedList<Servidor>> &tree){
//     int listLenMax = 3000; // Max servers per list
//     // int fullListLen = loadedList.length(); // Limit
//     srand(time(NULL)); // Initialize random number generator

//     LinkedList<int> checkList = LinkedList<int>();
//     int lenLL = rand()%listLenMax;
//     while (checkList.contains(lenLL)){
//         lenLL = rand()%listLenMax;
//     }
//     checkList.addFirst(lenLL);
    
//     while(!loadedList.is_empty()){
//         LinkedList<Servidor> aux = LinkedList<Servidor>(); // Small lists for tree
//         for (int i = 0; i < lenLL; i++){
//             aux.addLast(loadedList.pop); // Add element to aux from full list and remove from it
//         }
//         // tree.insert(aux);
//     }
// } 

// 1. Load file and create BST
void loadFile(string fileName){ 
    LinkedList<Servidor> serverFullLinkedList = LinkedList<Servidor>(); // Linked List to store servers read from file
    ifstream lector(fileName);
    if(lector.fail()){
        cout << "File name does not exist. Program terminated.";
    }
    string mes, hora, ip, errorReason;
    int dia;
    string linea;

        // int counter = 0;
        // Servidor server[counter];

    while(getline(lector, linea)){
        istringstream iss(linea);
        iss >> mes;
        iss >> dia;
        iss >> hora;
        iss >> ip;
        iss >> errorReason;
        

        Servidor server(mes, dia, hora, ip, errorReason);
        // serverFullLinkedList.addLast(server[counter]);
        serverFullLinkedList.addLast(server);

        /*
        Server server(mes, dia,.... );
        lista.addLast(server);
        */
    }
    lector.close();

    BST<LinkedList<Servidor>> tree = BST<LinkedList<Servidor>>();
    LinkedList<int> checkList = LinkedList<int>();
    int listLenMax = 3000; // Max servers per list
    srand(time(NULL)); // Initialize random number generator

    int lenLL = rand()%listLenMax;
    while(!serverFullLinkedList.is_empty()){
        while (checkList.contains(lenLL)){
            lenLL = rand()%listLenMax;
        }
        // cout << lenLL << endl;
        checkList.addFirst(lenLL);

        LinkedList<Servidor> aux = LinkedList<Servidor>(); // Small lists for tree
        for (int i = 0; i < lenLL; i++){
            aux.addLast(serverFullLinkedList.pop()); // Add element to aux from full list and remove from it
            if(serverFullLinkedList.is_empty()){
                break;
            }
        }
        cout << aux.length() << endl;
        // tree.insert(aux);
    }
} 

// void opcion02(/*BST<LinkedList<Server>>  & facebook*/){
// }

string userMenu;
string userFile;

int main() {

    cout << " ---- Menu ---- " << endl;
    cout << "Select an option." << endl;
    cout << "\t1. Load file." << endl;
    cout << "\t2. Print tree by level." << endl;
    cout << "\t3. Print tree by preorder." << endl;
    cout << "\t4. Print tree by postorder." << endl;
    cout << "\t5. Print tree by inorder." << endl;
    cout << "\t6. Search a server by using the IP." << endl;
    cout << "\t7. Print the percentage of infected servers or not intefected." << endl;
    cout << "\t8. Print the result given by BST methods." << endl;
    cout << "\t9. Exit program." << endl;;

    cin >> userMenu;
    while(userMenu != "1" && userMenu != "2" && userMenu != "3" && userMenu != "4" && userMenu != "5" && userMenu != "6" && userMenu != "7" && userMenu != "8" && userMenu != "9"){
        cout << "Invalidad input. Please try again." << endl;
        cout <<"Enter a valid option: ";
        cin >> userMenu;
    }
    if (userMenu == "1")
    {
        cout << "Enter the name of the file (e.g. 'bitacora.txt')" << endl;
        cin >> userFile;
        loadFile(userFile);
        cout << "File loaded sucessfully." << endl;
    }else if (userMenu == "2")
    {
        /* code */
    }else if (userMenu == "3")
    {
        /* code */
    }else if (userMenu == "4")
    {
        /* code */
    }else if (userMenu == "5")
    {
        /* code */
    }else if (userMenu == "6")
    {
        /* code */
    }else if (userMenu == "7")
    {
        /* code */
    }else if (userMenu == "8")
    {
        /* code */
    }else if (userMenu == "9")
    {
        /* code */
    }
    
    return 0;
}