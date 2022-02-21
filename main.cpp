/*
Assalamu Alaikum ,

Presenting Hotel Management System Version 6.0

Contributed by -
          1) Farhan Faiaz, Id-C211007, Section-2AM
          2) Rashedul Arefin Ifty, Id- C211032, Section-2AM

Features-
          1) Multiple owners can login.
          2) Owner informations will be recorded in a file.
          3) Owner can make food menu.
          5) Owner can edit existing food menu.
          4) Owner can delete from food menu.
          5) Owner can see previous billing records.
          6) Billing information will be recorded in a file.
          7) Multiple customers can login.
          8) Customer informations will be recorded in a file.
*/

#include <bits/stdc++.h>
using namespace std;

#define RESET "\033[0m"                             ///for coloring the consol
#define RED "\033[31m"    /* Red */
#define GREEN "\033[32m"  /* Green */              
#define YELLOW "\033[33m" /* Yellow */
#define BLUE "\033[34m"   /* Blue */

#define fastio()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl '\n'

class Resturent
{
private:
    string item_name;
    int item_price;
    int item_amount;

public:
    // Function for Set Food Value in Array
    void SetValueFood(string Name, int Price, int Amount)
    {
        item_name = Name;
        item_price = Price;
        item_amount = Amount;
    }
    // Function for Show Food Menu
    void show()
    {
        cout << BLUE;
        cout << "\tName : " << item_name << endl;
        cout << "\tPrice : " << item_price << endl;
        cout << "\tAmount : " << item_amount << endl;
        cout << endl;
        cout << RESET;
    }

    // Function to Access Private Variable
    void change_name(string name)
    {
        item_name = name;
    }
    void change_price(int price)
    {
        item_price = price;
    }
    void change_amount(int amount)
    {
        item_amount = amount;
    }

    // Function For Show Bill
    void Bill(int n)
    {
        cout << YELLOW;
        cout << "\t\t\t\t\tName : " << item_name << endl;
        cout << "\t\t\t\t\tQuantity : " << n << endl;
        cout << "\t\t\t\t\tTotal bill : " << item_price * n << endl;
        cout << "\t\t\t\t\tThank you for choosing us...." << endl;
        cout << "\n\t\t\t\t******************************************\n"
             << endl;
        cout << RESET;
        item_amount -= n;
    }

    // Function For to Check Amount
    bool Amount(int A)
    {
        if ((item_amount - A) >= 0)
            return true;
        else
            return false;
    }

    // Food Array --> data --> Food File
    void add_file()
    {
        ofstream food_menu;
        food_menu.open("food_info.txt", ios::app);
        food_menu << item_name << endl;
        food_menu << item_price << endl;
        food_menu << item_amount << endl;
        food_menu.close();
    }


    ///for making bill file
    void filebill(int q)
    {

        ///file for showing bill
        ofstream file;
        file.open("bill.txt", ios::out | ios::app);

        file << "Name: " << item_name << endl;

        file << "Quantity : " << q << endl;

        file << "Total bill: " << item_price * q << endl
             << endl;

        cout << endl;

        file.close();
    }
};

class Owner
{
    string name;

public:
    string user_Name;
    int PASSWORD;

    // Function for Set Owner Value in Array
    void SetValueOwner(string UName, string Name, int Pass)
    {
        user_Name = UName;
        name = Name;
        PASSWORD = Pass;
    }

    // Function for Show Owner List
    void show_owner()
    {
        cout << BLUE;
        cout << "User Name  : " << user_Name << endl;
        cout << "Name       : " << name << endl;
        cout << "Password   : " << PASSWORD << endl
             << endl;
             cout << RESET;
    }
};

class Customer
{
    string name;

public:
    string user_Name;
    int PASSWORD;

    // Function for Set Customer Value in Array
    void SetValueCustomer(string UName, string Name, int Pass)
    {
        user_Name = UName;
        name = Name;
        PASSWORD = Pass;
    }

    // Function for Show Customer List
    void show_customer()
    {
        cout << BLUE;
        cout << "User Name  : " << user_Name << endl;
        cout << "Name       : " << name << endl;
        cout << "Password   : " << PASSWORD << endl
             << endl;
             cout << RESET;
    }
};

int main()
{

    // fastio();

    int flag = 0; ///for accesing food option for owner

    /// owner log in and file making part start

    vector<Owner> arr;
    Owner own;
    arr.push_back(own);

    // Owner File --> data --> Owner Array
    ifstream owner;
    owner.open("owner.txt", ios::in);
    string uname, name, pass;
    string temp;
    int count = 0, count2 = 1;
    string str2;
    int pass2;

    //Transfer data ---> object array (from file)
    while (getline(owner, temp))
    {
        if (count2 == 1)
            uname = temp;
        if (count2 == 2)
            name = temp;
        if (count2 == 3)
        {
            pass = temp;
            count2 = 0;
            Owner temp1;
            temp1.SetValueOwner(uname, name, stoi(pass));
            arr.push_back(temp1);
            count++;
        }
        count2++;
    }

    //App login
    cout << YELLOW;
    cout << "\t\t\t\t\t******************Welcome*****************" << endl;
    cout << "\n\t\t\t\t\t\t         Hi there!!" << endl;
    cout << RESET;

    while (1)
    {
        string MainPass = "1011";
        string pass;
        cout << "\nContinue by using App Login Password : ";
        cin >> pass;
        bool logIn = false;
        if (pass == MainPass)
        {
            bool logIn = true;
            cout << GREEN;
            cout << "\n\t\t\t\t\t******************************************\n"
                 << endl;
            cout << "\t\t\t\t\t\t     Access Granted!!\n";
            cout << "\n\t\t\t\t\t******************************************" << endl;
            cout << RESET;

            cout << YELLOW;
            cout << "Choose " << endl;
            cout << "1.Login as Owner" << endl;
            cout << "2.Login as Customer" << endl;
            cout << RESET;

            int a;
            cin >> a;

            while (a == 1)
            {
                cout << YELLOW;
                cout << "\nSelect : \n";
                cout << "1. Add a New Owner" << endl;
                cout << "2. Owners' List" << endl;
                cout << "3. Login" << endl;
                cout << RESET;

                int select;
                cin >> select;
                if (select == 1)
                {

                    ofstream owner;
                    owner.open("owner.txt", ios::out | ios::app);
                    //Store owner data--->file (New Added Owner)

                    cout << "\tHow many owner you add : ";
                    int new_own;
                    cin >> new_own;

                    for (int i = 0; i < new_own; i++)
                    {

                        string str, str1;
                        int pass1;

                        cout << "\tUser Name : ";
                        cin >> str;
                        owner << str << endl;
                        cout << "\tName : ";
                        cin.ignore();
                        getline(cin, str1);
                        owner << str1 << endl;

                        cout << "\tPassword : ";
                        cin >> pass1;
                        cout << endl; /// for spacing
                        owner << pass1 << endl;

                        Owner temp;
                        temp.SetValueOwner(str, str1, pass1);

                        arr.push_back(temp);
                    }
                    owner.close();
                    count += new_own;
                }

                ///for showing owner list
                else if (select == 2)
                {
                    for (int i = 1; i <= count; i++)
                    {
                        cout << endl << BLUE 
                             << "#" << i << RESET << endl;
                        arr[i].show_owner();
                    }
                }

                //Owner Login
                else if (select == 3)
                {
                    bool cstmr = false;
                    cout << endl
                         << "\tEnter User Name : ";
                    cin >> str2;
                    cout << "\tEnter Password : ";
                    cin >> pass2;
                    //Username+Password Checking
                    for (int i = 1; i <= count; i++)
                    {
                        if (arr[i].user_Name == str2 && arr[i].PASSWORD == pass2)
                        {
                            cstmr = true;
                            break;
                        }
                    }
                    if (cstmr == true) //If username+password matched
                    {
                        cout << GREEN;
                        cout << "\n\t\t\t\t\t******************************************\n"
                             << endl;
                        cout << "\t\t\t\t\t           Logged in as " << str2 << endl;
                        cout << "\n\t\t\t\t\t******************************************" << endl;
                        cout << RESET;

                        flag = 1; ///for accessing food part as owner
                        break;
                    }
                    else //If username+password did not match
                    {
                        cout << RED;
                        cout << "\n\t\t\t\t\t******************************************\n"
                             << endl;
                        cout << "\t\t\t\t\t        Access denied..Try again..\n";
                        cout << "\n\t\t\t\t\t******************************************" << endl;
                        cout << RESET;
                    }
                }
            }
             ///owner log in and file making part finished

           
           
            ///food menu making part start

            bool cstmr = false;
            int cnt = 0, cnt2 = 1;     

            vector<Resturent> food;
            Resturent tfood;
            food.push_back(tfood);

            
            ifstream food_menu;
            food_menu.open("food_info.txt", ios::in);
            string item_n, item_p, item_a;
            string str3;
            

            while (getline(food_menu, str3))
            {
                if (cnt2 == 1)
                    item_n = str3;
                if (cnt2 == 2)
                    item_p = str3;
                if (cnt2 == 3)
                {
                    item_a = str3;
                    cnt2 = 0;
                    Resturent temp3;
                    temp3.SetValueFood(item_n, stoi(item_p), stoi(item_a));
                    food.push_back(temp3);
                    cnt++;
                }
                cnt2++;
            }
            food_menu.close();
            remove("food_info.txt");

            if (flag == 1)
            {

                 for (int j = 1; j >= 0; j++)
                {
                    cout << YELLOW;
                    int select2;
                    cout << "1.Add New Items" << endl;
                    cout << "2.Edit Existing Items" << endl;
                    cout << "3.See Menu" << endl;
                    cout << "4.See Previous Orders" << endl;
                    cout << "5.Delete Item" << endl;
                    cout << "6.Menu Setting Complete" << endl;
                    cout << RESET;
                    cin >> select2;
                    if (select2 == 6)
                    {
                        cstmr = true;
                        break;
                    }
                    else if (select2 == 1)
                    {
                        int n;
                        cout << "\tHow many items do you want to add? : ";
                        cin >> n;

                        for (int i = 1; i <= n; i++)
                        {
                            cin.ignore();
                            string str4;
                            int x4, y4;
                            cout << "\t#" << i << endl;
                            cout << "\tName : ";
                            getline(cin, str4);
                            cout << "\tPrice : ";
                            cin >> x4;
                            cout << "\tAmount : ";
                            cin >> y4;
                            cout << endl;
                            Resturent xy;
                            xy.SetValueFood(str4, x4, y4);
                            food.push_back(xy);
                        }
                        cnt += n;
                    }
                    //View all food
                    else if (select2 == 3) //View all food
                    {
                        for (int i = 1; i <= cnt; i++)
                        {
                            cout <<BLUE <<  "\t#" << i  << RESET << endl;
                            food[i].show();
                        }
                    }

                    else if (select2 == 5) // delete food item
                    {

                        cout << "\twhich item do you want to delete?" << endl;
                        int del;
                        cin >> del;
                        cnt--;
                        food.erase(food.begin() + del, food.begin() + del + 1);                       
                    }

                    else if (select2 == 4)  ///for showing previous billing information
                    {
                        cout << endl;
                        string line_;
                        ifstream file_("bill.txt");
                        if (file_.is_open())
                        {
                            while (getline(file_, line_))
                            {
                                cout << line_ << endl;
                            }
                            cout << endl;
                            file_.close();
                        }
                        cin.get();
                    }

                    //Edit existing food info
                    else if (select2 == 2)
                    {
                        int edit;
                        cout << YELLOW;
                        cout << "\tSelect : " << endl;
                        cout << "\t1. Edit the name of item" << endl;
                        cout << "\t2. Edit the price of item" << endl;
                        cout << "\t3. Edit the amount of item" << endl;
                        cout << RESET;

                        cin >> edit;

                        int change_no;
                        cout << "Item number you want to edit : ";
                        cin >> change_no;
                        string new_name;
                        int new_price, new_amount;
                        //Name edit
                        if (edit == 1) //name edit
                        {
                            cin.ignore();
                            cout << "\t\t\t\tNew name : ";
                            getline(cin, new_name);
                            cout << endl;
                            food[change_no].change_name(new_name);
                        }

                        //Price edit
                        else if (edit == 2)
                        {
                        Price:

                            cout << "\t\t\t\tNew price : ";
                            cin >> new_price;
                            if (new_price < 0)
                            {
                                cout << RED << "Invalid Price" << RESET << endl;
                                goto Price;
                            }
                            else
                            {
                                cout << endl;
                                food[change_no].change_price(new_price);
                            }
                        }
                        //Amount edit
                        else if (edit == 3)
                        {
                        Amount:
                            cout << "\t\t\t\tNew amount : ";
                            cin >> new_amount;
                            if (new_amount < 0)
                            {

                                cout << RED << "Invalid Amount" << RESET << endl;
                                goto Amount;
                            }
                            else
                            {
                                cout << endl;
                                food[change_no].change_amount(new_amount);
                            }
                        }
                    }
                }

            }
 
                        ///food menu making part finish]


            if (a == 2 || cstmr == true)
            {
                cout << YELLOW;
                cout << "\t\t\t\t\t******************Welcome*****************" << endl;
                cout << RESET;

                ///customer log in and file making part start

                vector<Customer> arrC;
                Customer cus;
                arrC.push_back(cus);

                ifstream customer;
                customer.open("customer.txt", ios::in);
                string uname, name, pass;
                string temp;
                int count = 0, count2 = 1;
                string str2;
                int pass2;

                //Transfer data ---> object array (from file)
                while (getline(customer, temp))
                {
                    if (count2 == 1)
                        uname = temp;
                    if (count2 == 2)
                        name = temp;
                    if (count2 == 3)
                    {
                        pass = temp;
                        count2 = 0;
                        Customer temp1;
                        temp1.SetValueCustomer(uname, name, stoi(pass));
                        arrC.push_back(temp1);
                        count++;
                    }
                    count2++;
                }

                while (1)
                {
                    cout << YELLOW;
                    cout << "\nSelect : \n";
                    cout << "1. Add a new Customer" << endl;
                    cout << "2. Customer's List" << endl;
                    cout << "3. Customer Login" << endl;
                    cout << RESET;

                    int select;
                    cin >> select;
                    if (select == 1)
                    {

                        ofstream customer;
                        customer.open("customer.txt", ios::out | ios::app);
                        //Store customer data--->file (New Added Customer)

                        cout << "\tHow many customer you add : ";
                        int new_cus;
                        cin >> new_cus;

                        for (int i = 0; i < new_cus; i++)
                        {

                            string str, str1;
                            int pass1;

                            cout << "\tUser Name : ";
                            cin >> str;
                            customer << str << endl;
                            cout << "\tName : ";
                            cin.ignore();
                            getline(cin, str1);
                            customer << str1 << endl;

                            cout << "\tPassword : ";
                            cin >> pass1;
                            customer << pass1 << endl;                           
                            cout << endl;                           
                            Customer temp;
                            temp.SetValueCustomer(str, str1, pass1);

                            arrC.push_back(temp);
                        }
                        customer.close();
                        count += new_cus;
                    }
                    else if (select == 2) ///for showing billing information
                    {
                        for (int i = 1; i <= count; i++)
                        {
                            cout << endl
                              << BLUE   << "#" << i << endl << endl;
                            arrC[i].show_customer();
                        }
                    }
                    //Customer Login
                    else if (select == 3)
                    {
                        bool cstmr = false;
                        cout << endl
                             << "\tEnter User Name : ";
                        cin >> str2;
                        cout << "\tEnter Password : ";
                        cin >> pass2;
                        //Username+Password Checking
                        for (int i = 1; i <= count; i++)
                        {
                            if (arrC[i].user_Name == str2 && arrC[i].PASSWORD == pass2)
                            {
                                cstmr = true;
                                break;
                            }
                        }
                        if (cstmr == true) //If username+password matched
                        {
                            // cout << "\n******" << endl;
                            // cout << "\t\t\t\t\t       Logged in as " << str2 << endl;
                            // cout << "\n******" << endl;
                            cout << GREEN;
                            cout << "\n\t\t\t\t\t******************************************\n"
                                 << endl;
                            cout << "\t\t\t\t\t           Logged in as " << str2 << endl;
                            cout << "\n\t\t\t\t\t******************************************" << endl;
                            cout << RESET;

                            break;
                        }
                        else //If username+password did not match
                        {
                            // cout << "\n******" << endl;
                            // cout << "\t\t\t\t\t       Access denied..Try again..\n";
                            // cout << "\n******" << endl;
                            cout << RED;
                            cout << "\n\t\t\t\t\t******************************************\n"
                                 << endl;
                            cout << "\t\t\t\t\t        Access denied..Try again..\n";
                            cout << "\n\t\t\t\t\t******************************************" << endl;
                            cout << RESET;
                        }
                    }
                }

                ///customer log in and file making part finish



                ///customer ordering part start
                for (int i = 1; i >= 0; i++)
                {
                    cout << YELLOW;
                    cout << "1.See The Full Menu" << endl;
                    cout << "2.Select Item" << endl;
                    cout << "3.Complete Order\n"
                         << endl;
                    cout << RESET;
                    int s;
                    cin >> s;
                    cout << endl;
                    if (s == 3)
                    {
                        cstmr = false;
                        break;
                    }
                    if (s == 1) ///for showing the full menu
                    {
                        cout << "\n******************************************" << endl;
                        for (int i = 1; i <= cnt; i++)
                        {
                            cout <<BLUE << "\t#" << i << RESET << endl;
                            food[i].show();
                        }
                        cstmr = true;
                    }
                    cout << "\n******************************************" << endl;
                   
                   
                    if (s == 2) ///for selecting item
                    {
                        cout << "Select item number : ";
                        int s1, a1;
                        cin >> s1;
                        cout << "Quentity : ";
                        cin >> a1;
                        cout << endl;
                        bool bl1 = food[s1].Amount(a1);
                        if (bl1 == true)
                        {
                            cout << YELLOW;
                            cout << "\n\t\t\t\t******************************************\n"
                                 << endl;
                            cout << "\t\t\t\t\t       -----Bill-----\n\n";
                            cout << "\t\t\t\t\tYou have selected item : #" << s1 << endl;
                            cout << RESET;
                            food[s1].Bill(a1);
                            cout << endl;
                            food[s1].filebill(a1);
                        }
                        else
                        {
                            cout << RED;
                            cout << "\n\t\t\t\t\t******************************************\n"
                                 << endl;
                            cout << "\t\t\t\t\t\tSorry..Insufficient amount!\n";
                            cout << "\n\t\t\t\t\t******************************************" << endl;
                            cout << RESET;
                        }
                    }
                }
            }
            for (int i = 1; i <= cnt; i++)
            //Send all data into file
            {
                food[i].add_file();
            }
            if (logIn == true)
                break;
        }
        else
        {
            cout << RED;
            cout << "\n\t\t\t\t\t******************************************\n"
                 << endl;
            cout << "\t\t\t\t\t        Access denied..Try again..\n";
            cout << "\n\t\t\t\t\t******************************************" << endl;
            cout << RESET;
        }
    }
    return 0;
}
