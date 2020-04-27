#include "Header.h"

ItemList::ItemList() {
    first = NULL;
    last = NULL;
}

int totaltime;
int sortingtime;
int readtime;

int calctime(int t)
{
    
    t =  clock() - t;
    t = t * 1.0 / CLOCKS_PER_SEC;
    return t;
    
}
void ItemList::top10() {
    sortingtime = clock();
    Node* current = first;
    int quantity[4070];
    string desc[4070];
    string code[4070];
    current = current->next;
    int temp;
    string codetemp, desctemp;
    int i = 0, a=0,b=0;
    
    while (current != NULL)
    {
        quantity[i] = current->quantity;
        desc[i] = current -> desc;
        code[i] = current->code;
        i++;
        current = current->next;
    }
    
    for (b = 0; b < 4070; b++)
    {
        for (a = b + 1; a < 4070; a++)
        {
            if (quantity[b] < quantity[a])
            {
                temp = quantity[b]; codetemp = code[b]; desctemp = desc[b];         
                quantity[b] = quantity[a]; code[b] = code[a]; desc[b] = desc[a];
                quantity[a] = temp;
                code[a] = codetemp;
                desc[a] = desctemp;
            }
        }
    }            
    system("CLS");
    cout << "ITEM STOCKCODE" << "\t\t"<< "ITEM QUANTITY" << "\t\t" << "ITEM DESCRIPTION" << endl;
    cout << endl;
    for (int x = 2; x < 12; x++) // print
    {
        cout << code[x] << "\t\t\t" << quantity[x] << "\t\t\t" << desc[x] << endl;
    }
    sortingtime = calctime(sortingtime);
    totaltime = calctime(totaltime);
    cout << "\n\n";
    cout << "Elapsed Time for Reading: " << readtime << endl;
    cout << "Elapsed Time for Sorting: " << sortingtime << endl;
    cout << "Elapsed Total Time: " << totaltime << endl;
}

void ItemList::read() {
    totaltime = clock();
    readtime = clock();
    ifstream ip;
    ip.open("OnlineRetail.csv");
    cout << "Reading from file...";
    string c, d, m, trash;
    int q;
    getline(ip, trash, '\n');
    while (ip) {
        getline(ip, trash, ';');
        getline(ip, c, ';');
        getline(ip, d, ';');
        getline(ip, m, ';');
        getline(ip, trash, ';');
        getline(ip, trash, ';');
        getline(ip, trash, ';');
        getline(ip, trash, '\n');
        trash.clear();
        q = stoi(m);
        Node* current = first;

        if (first == NULL)//First node +
        {
            Node* newNode = new Node;
            newNode->code = c;
            newNode->desc = d;
            newNode->quantity = q;

            first = newNode;
            last = newNode;
            first->next = NULL;
        }
        else
        {
            while (current->code != c)
            {
                //current = current->next;
                if (current->next == NULL) //Last olduðunu anlýyor
                {
                    Node* newNode = new Node;
                    newNode->code = c;
                    newNode->desc = d;
                    newNode->quantity = q;

                    last->next = newNode;
                    last = newNode;
                    newNode->next = NULL;
                }
                current = current->next;
            }
            if (current->code == c && current->next != NULL)
            {
                current->quantity = current->quantity + q;
            }
        }
    }
    readtime = calctime(readtime);
}