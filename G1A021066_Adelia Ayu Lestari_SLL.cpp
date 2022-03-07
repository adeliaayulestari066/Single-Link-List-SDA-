#include<iostream>

using namespace std;

struct node
{
    int info;
    struct node *next;
}*start;
 

class single_linkedlist
{
    public:
        node* create_node(int);
        void insert_first();
        void insert_pos();
        void insert_last(); 
        void delete_pos();
        void search();
        void display();
        single_linkedlist() 
        {
            start = NULL;
        }
};
 

main()
{
    int choice, nodes, element, position, i;
    single_linkedlist sl;
    start = NULL;
    while (1)
    {
        cout<<endl<<"----Projek single linked list----"<<endl;
        cout<<endl<<"----------------------------------"<<endl;
        cout<<"1.Insert first"<<endl;
        cout<<"2.Insert last"<<endl;
        cout<<"3.Insert after"<<endl;
        cout<<"4.Delete a Particular Node"<<endl;
        cout<<"5.Search Element/pencarian"<<endl;
        cout<<"6.Tampilkan list"<<endl;
        cout<<"7.Exit "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"<Masukkan di bagian awal: "<<endl;
            sl.insert_first();
            cout<<endl;
            break;
        case 2:
            cout<<"Masukkka di bagian akhir: "<<endl;
            sl.insert_last();
            cout<<endl;
            break;
        case 3:
            cout<<"Masukkan di posisi tertentu:"<<endl;
            sl.insert_pos();
            cout<<endl;
            break;
        case 4:
            cout<<"Delete sebuah partilkular node: "<<endl;
            sl.delete_pos();
            break;
        case 5:
            cout<<"Search element di Linked list "<<endl;
            sl.search();
            cout<<endl;
            break;
        case 6:
            cout<<"Display/tampilkan elemen pada link list"<<endl;
            sl.display();
            cout<<endl;
            break;
        case 7:
            cout<<"Kemali..."<<endl;
            exit(1);
            break;  
        default:
            cout<<"jawaban salah"<<endl;
        }
    }
}
 

node *single_linkedlist::create_node(int value)
{
    struct node *temp, *s;
    temp = new(struct node); 
    if (temp == NULL)
    {
        cout<<"Memori tidak di alokasikan "<<endl;
        return 0;
    }
    else
    {
        temp->info = value;
        temp->next = NULL;     
        return temp;
    }
}
 

void single_linkedlist::insert_first()
{
    int value;
    cout<<"Masukkan nilai untuk di masukkan: ";
    cin>>value;
    struct node *temp, *p;
    temp = create_node(value);
    if (start == NULL)
    {
        start = temp;
        start->next = NULL;          
    } 
    else
    {
        p = start;
        start = temp;
        start->next = p;
    }
    cout<<"Elemen dimasukkan di awal"<<endl;
}
 

void single_linkedlist::insert_last()
{
    int value;
    cout<<"Masukkan nilai untuk di masukkan di akhir: ";
    cin>>value;
    struct node *temp, *s;
    temp = create_node(value);
    s = start;
    while (s->next != NULL)
    {         
        s = s->next;        
    }
    temp->next = NULL;
    s->next = temp;
    cout<<"Elemen dimasukkan di akhir"<<endl;  
}
 

void single_linkedlist::insert_pos()
{
    int value, pos, counter = 0; 
    cout<<"Masukkan nilai untuk di masukkkan: ";
    cin>>value;
    struct node *temp, *s, *ptr;
    temp = create_node(value);
    cout<<"Masukkan posisi untuk node untuk di masukkan: ";
    cin>>pos;
    int i;
    s = start;
    while (s != NULL)
    {
        s = s->next;
        counter++;
    }
    if (pos == 1)
    {
        if (start == NULL)
        {
            start = temp;
            start->next = NULL;
        }
        else
        {
            ptr = start;
            start = temp;
            start->next = ptr;
        }
    }
    else if (pos > 1  && pos <= counter)
    {
        s = start;
        for (i = 1; i < pos; i++)
        {
            ptr = s;
            s = s->next;
        }
        ptr->next = temp;
        temp->next = s;
    }
    else
    {
        cout<<"Posisi melebihi range"<<endl;
    }
}
 
void single_linkedlist::delete_pos()
{
    int pos, i, counter = 0;
    if (start == NULL)
    {
        cout<<"List kosong"<<endl;
        return;
    }
    cout<<"Masukkan posisi nilai yang akan di hapus: ";
    cin>>pos;
    struct node *s, *ptr;
    s = start;
    if (pos == 1)
    {
        start = s->next;
    }
    else
    {
        while (s != NULL)
        {
            s = s->next;
            counter++;  
        }
        if (pos > 0 && pos <= counter)
        {
            s = start;
            for (i = 1;i < pos;i++)
            {
                ptr = s;
                s = s->next;
            }
            ptr->next = s->next;
        }
        else
        {
            cout<<"Posisi di luar range"<<endl;
        }
        cout<<"Element Dihapus"<<endl;
    }
}
 
void single_linkedlist::search()
{
    int value, pos = 0;
    bool flag = false;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the value to be searched: ";
    cin>>value;
    struct node *s;
    s = start;
    while (s != NULL)
    {
        pos++;
        if (s->info == value)
        {
            flag = true;
            cout<<"Elemen "<<value<<" ditemukan pada posisi "<<pos<<endl;
        }
        s = s->next;
    }
    if (!flag)
        cout<<"Elemen "<<value<<" tidak ditemukan pada list"<<endl;  
}
 
void single_linkedlist::display()
{
    struct node *temp;
    if (start == NULL)
    {
        cout<<"Lisynya kosong"<<endl;
        return;
    }
    temp = start;
    cout<<"Elemen elemen dari list adalah: "<<endl;
    while (temp != NULL)
    {
        cout<<temp->info<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
