#include<bits/stdc++.h>
using namespace std;
class Book_store{
    public:
    void control_panel();
    void add_book();
    void show_books();
    void update_book();
    void del_book(); 
};
void Book_store::control_panel() {
    cout<<"1.\tADD THE BOOK\n";
    cout<<"2.\tDISPLAY THE BOOKS\n";
    cout<<"3.\tUPDATE THE BOOK\n";
    cout<<"4.\tDELETE THE BOOK\n";
    cout<<"5.\tCHECKING THE BOOK\n";
    cout<<"\n";
    return;
}
void Book_store::add_book(){
    fstream f;
    int b_id,no_bs;
    string b_name,aut_book;
    cout<<"\n\n\t\t\t\tADDING THE BOOK\n";
    cout<<"\n\tBook Name : ";
    cin>>b_name;
    cout<<"\n\tAuthor of the Book : ";
    cin>>aut_book;
    cout<<"\n\tBook ID number : ";
    cin>>b_id;
    cout<<"\n\tNumber of Books : ";
    cin>>no_bs;
    f.open("C:\\Users\\suren\\Documents\\book.txt",ios::out | ios::app);
    f<<" "<<b_name<<" "<<b_id<<" "<<aut_book<<" "<<no_bs<<"\n";
    f.close();

}
void Book_store::show_books(){
    fstream f;
    int b_id,no_bs;
    string b_name,aut_books;
    cout<<"\n\n\t\t\t\tDISPLAY THE BOOKS\n";
    f.open("C:\\Users\\suren\\Documents\\book.txt",ios::in);
    if(!f){
        cout<<"\n file opening error\n";
    }
    else{
        cout<<"\n\t\tNAME\t\t\tID\t\t\tAUTHOR\t\t\tTOTAL\n";
        f>>b_name>>b_id;
        f>>aut_books>>no_bs;
        while(!f.eof()){
            cout<<"\t\t"<<b_name<<"\t\t\t"<<b_id<<"\t\t\t"<<aut_books<<"\t\t\t"<<no_bs<<"\n";
            f>>b_name>>b_id;
            f>>aut_books>>no_bs;
        }
        system("pause");
        f.close();
    }

}
void Book_store::update_book(){
    fstream f1,f;
    int b_id,no_bs;
    string b_name,aut_books;
    string up_name,up_aut;
    int up_id,up_no,count = 0;
    f.open("C:\\Users\\suren\\Documents\\book.txt",ios::in);
    f1.open("C:\\Users\\suren\\Documents\\book1.txt",ios::out | ios::app);
    if(!f1 or !f){
        cout<<"\nFile Opening Error";
    }
    else{
        cout<<"\n\tEnter the Updating id of book : ";
        cin>>up_id;
        f>>b_name>>b_id;
        f>>aut_books>>no_bs;
        while(!f.eof()){
            if(up_id == b_id){
                cout<<"\n\tEnter the updating name for Book : ";
                cin>>up_name;
                cout<<"\n\tEnter the Author name : ";
                cin>>up_aut;
                cout<<"\n\tEnter the no of Books : ";
                cin>>up_no;
                count++;
                f1<<" "<<up_name<<" "<<b_id<<" "<<up_aut<<" "<<up_no<<"\n";
            }
            else{
                f1<<" "<<b_name<<" "<<b_id<<" "<<aut_books<<" "<<no_bs<<"\n";
            }
            f>>b_name>>b_id;
            f>>aut_books>>no_bs;
        }
        f.close();
        f1.close();
    }
    if(count==0){
        cout<<"\n\nThere is no books with that id.";
    }
    remove("C:\\Users\\suren\\Documents\\book.txt");
    rename("C:\\Users\\suren\\Documents\\book1.txt","C:\\Users\\suren\\Documents\\book.txt");
    return;
}
void Book_store::del_book(){
    fstream f1,f;
    int b_id,no_bs;
    string b_name,aut_books;
    int up_id,count = 0;
    f.open("C:\\Users\\suren\\Documents\\book.txt",ios::in);
    f1.open("C:\\Users\\suren\\Documents\\book1.txt",ios::out | ios::app);
    if(!f1 or !f){
        cout<<"\nFile Opening Error";
    }
    else{
        cout<<"\n\tEnter the Deleting id of book : ";
        cin>>up_id;
        f>>b_name>>b_id;
        f>>aut_books>>no_bs;
        while(!f.eof()){
            if(up_id == b_id){
                cout<<"\nDeletion of the book named "<<b_name<<" with id : "<<b_id<<" is deleted.";
                count++;
            }
            else{
                f1<<" "<<b_name<<" "<<b_id<<" "<<aut_books<<" "<<no_bs<<"\n";
            }
        }
        f.close();
        f1.close();
    }
    if(count==0){
        cout<<"\n\nThere is no books with that id.";
    }
    remove("C:\\Users\\suren\\Documents\\book.txt");
    rename("C:\\Users\\suren\\Documents\\book1.txt","C:\\Users\\suren\\Documents\\book.txt");
    return;
}
void Book_shop_system(){
    int ch;
    char x;
    Book_store b;
    while(1){
        b.control_panel();
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch){
            case 1:
            do{
                b.add_book();
                cout<<"\n\tDo you want to add another book ?(y/n)\n";
                cin>>x;
            }while(x=='y');
            break;
            case 2:
            b.show_books();
            break;
            case 3:
            b.update_book();
            break;
            case 4:
            b.del_book();
            break;
            case 5:
            exit(0);
            break;
            default:
            cout<<"\n\nINVALID CHOLCE\n";
        }
    }
}
int main(){
    Book_shop_system();
    return 0;
}