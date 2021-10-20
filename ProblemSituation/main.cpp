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

void createServerBTS(LinkedList<Servidor> &loadedList, BST<LinkedList<Servidor>> &tree){
    int listLenMax = 1000; // Max servers per list
    int fullListLen = loadedList.length(); // Limit
    srand(time(NULL)); // Initialize random number generator

    while(!loadedList.is_empty()){
    LinkedList<Servidor> aux = LinkedList<Servidor>();
        aux.addLast(loadedList.remove_front());
        
    }
} 

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
        // cout << serverFullLinkedList.length() << endl;
}

// }
// void opcion02(/*BST<LinkedList<Server>>  & facebook*/){
// }

int userMenu;
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
    cout << "\t9. Exit program" << endl;;

    cin >> userMenu;
    if (userMenu == 1)
    {
        cout << "Enter the name of the file (e.g. 'bitacora.txt')" << endl;
        cin >> userFile;
        loadFile(userFile);
        cout << "File load sucessfully." << endl;
    }
    return 0;
}