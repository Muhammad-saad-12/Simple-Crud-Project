#include<iostream>
#include<string>
using namespace std;

int count=1;                        //Global variable

struct Item{                        //Structure
 string name;
 float price;
 int id;
};

const int max_item=100;             //indexes
Item items[max_item];               //Array of Structure
int itemNo=0;       

int menu(){
    system("CLS");
    int cho;
    cout << "\nMenu:\n";
    cout << "1. Add item\n";
    cout << "2. Show only item\n";
    cout << "3. Show all items\n";
    cout<<  "4. Update item\n";
    cout<<  "5. Delete item\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin>>cho;
    return cho;
}

void line(){
    for(int i=0;i<30;i++){
        cout<<"*";
    }
    cout<<endl;
}

void Note(){                       //A smiple Note When Data is not stored in indexes. 
  cout<<"NOTE:\"Any item is not stored in the Index\n Please first enter Item information\""<<endl;
}

void note(){                        //A simple note when the Id conditions are not going to Match.
    cout<<"Id not found"<<endl;
}

void add(){                         //Function to Store data in Indexes.
    string name;
    float price;
    int id;
    cout<<"Product number "<<itemNo+1<<endl;
    cout<<"Enter the id of the product: ";
     cin>>id;
    cout<<"Enter the price of the product: ";
     cin>>price;
    cout<<"Enter the name of the product: ";
     cin>>name;
    itemNo++;
    items[itemNo].id=id;
    items[itemNo].price=price;
    items[itemNo].name=name;
    cout<<"Items added successfully"<<endl;
}

void show_only(){                    //Function to show only data stored in the indexes.               
    if(itemNo==0){
     line();
     Note();
     line();
    }
    else{
      int id,find=0;
      cout<<"Enter the Id of the product: ";
        cin>>id;
      for(int i=1;i<=itemNo;i++){
         if(items[i].id==id){
             cout<<"showing the data of the product"<<endl;
             cout<<"Product Name: "<<items[i].name<<endl;
             cout<<"product Price: "<<items[i].price<<endl;
             find++;
            }
        }
     if(find==0){
         line();
         note();
         line();
        }
    }
}

void show_all(){                      //Function to show All data stored in the indexes.   
    if(itemNo==0){
     line();
     Note();
     line();
    }
    else{
     for (int i = 1; i<=itemNo; i++)
        {
         cout<<"showing the data of the product No "<<i<<endl;
         cout<<items[i].id<<" "<<items[i].name<<" "<<items[i].price;
         cout<<endl;
        }
    }
}

void update(){                      //Function to update the data stored in the indexes.
    if(itemNo==0){
     line();
     Note();
     line();
    }
    else{
    int id,find=0;
    string name;
    float price;
    cout<<"Enter id item to update: ";
    cin>>id;
    for(int i=1;i<=itemNo;i++){
        if(items[i].id==id){
           cout<<"Enter New item name: ";
           cin>>name;
           cout<<"Enter New item price: ";
           cin>>price;
           items[i].name=name;
           items[i].price=price;
           cout<<"Items updated successfully"<<endl;
           find++;
        }
    }
    if(find==0){
     line();
     note();
     line();
    }
    }
}

void Delete(){                    //Function to Delete the data stored in the indexes.
    if(itemNo==0){
     line();
     Note();
     line();
    }
    else{
     int id,find=0;
     cout << "Enter item id to delete: ";
      cin >> id;
      for (int i = 1; i <=itemNo; i++) {
          if (items[i].id == id) {
             for (int j=i; j<itemNo; j++) {
                 items[j] = items[j + 1];
                }
                itemNo--;
                cout << "Item deleted successfully.\n";
                find++;
            }                                                             
        }
      if(find==0){
         line();
         note();
         line();
        }
    }
}
int main()
{
    int choice;
    do{

     choice=menu();
     switch(choice){
      case 1:
          add();
          system("pause");
        break;
      case 2:
         show_only();
         system("pause");
        break;
      case 3:
         show_all();
         system("pause");
        break;
      case 4:
         update();
         system("pause");
        break;
      case 5:
         Delete();
         system("pause");
        break;
      case 6:
         cout<<"Hope to See you again"<<endl;
        break;
      default:
         cout<<"Invalid choice"<<endl;
         system("pause");
        break;
     }
    }while(choice!=6);
}