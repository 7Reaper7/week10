#include <iostream>
#include <conio.h>
using namespace std;

const int size = 10;

string ApprovedPackage[size] = {"-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1"};
string name[size];
string passwords[size];
string role[size];
string packages[10] = {"-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1"};
int unique_id[size] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int prices[10];
int assignedPackage[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int userApprovePackage[size];
int userApproveId[size];
int packcheck;
int choice;
int current_user;
int x = 0;
int p = 0;
int c = 0;

void Header();
void subHeader(string);
int loginMenu();
int adminMenu();
int userMenu();

void AddUser(string, string);
void ConfirmUpdate(int);
void showData(int, int);
void CreatePackages(string, string, int);
void showPackages(int, int);
void apply(int);
void clearIt();
void approve(int);
int ChangePassword(string);
int showRequests();
int login(string, string);
int CheckUserExist(int);
int CheckTrue(string, string);
bool signUp(string, string, string);
bool DeleteUser(int);
bool DeleteConfirm(int);

main()
{
    system("cls");

    string username, password, roletemp;
    string amount, validity;
    int price;
    int check;
    int check_id;
    bool yes = true;
    bool flag = false;
    bool flag1;
    int getint;
    int choiceSub, choiceSubSub;

    while (yes)
    {
        Header();
        subHeader("Main Menu");
        choice = loginMenu();
        clearIt();
        if (choice == 1)
        {
            while (true)
            {
                Header();
                subHeader("SignUp Menu");
                cout << "Enter Username=> ";
                cin >> username;
                cout << "Enter Password=> ";
                cin >> password;
                cout << "Your role(admin/user)=> ";
                cin >> roletemp;
                clearIt();
                if (x == 0)
                {
                    if (roletemp != "admin")
                    {
                        Header();
                        subHeader("SignUp Menu");
                        cout << "No Admin exists!" << endl;
                        clearIt();
                        break;
                    }
                }
                else if (x > 0 && x < size)
                {
                    if (roletemp == "admin")
                    {
                        Header();
                        subHeader("SignUp Menu");
                        cout << "Admin already exists! signup as user." << endl;
                        clearIt();
                        break;
                    }
                }
                if (x == size)
                {
                    Header();
                    subHeader("SignUp Menu");
                    cout << "Records full! Delete users to add more." << endl;
                    clearIt();
                    break;
                }
                flag = signUp(username, password, roletemp);
                if (flag == false)
                {
                    Header();
                    subHeader("SignUp Menu");
                    cout << "User already exists." << endl;
                    clearIt();
                    break;
                }
                else
                {
                    Header();
                    subHeader("SignUp Menu");
                    cout << "You have successfully signed up." << endl;
                    clearIt();
                    break;
                }
            }
        }
        if (choice == 2)
        {
            if (flag == true || x > 0)
            {
                Header();
                subHeader("Login Menu");
                cout << "Enter your Username=> " << endl;
                cin >> username;
                cout << "Enter your Password=> " << endl;
                cin >> password;
                check = login(username, password);
                clearIt();
            }
            else if (flag == false && x == 0)
            {
                Header();
                subHeader("Login Menu");
                cout << "No user found! signup first." << endl;
                clearIt();
            }

            if (check == 3)
            {
                Header();
                subHeader("Login Menu");
                cout << "No match found." << endl;
                clearIt();
            }
            else if (check == 1 || check == 2)
            {
                Header();
                subHeader("Login Menu");
                cout << "Logged in Successfully!" << endl;
                clearIt();
                if (check == 1) //-----------------------ADMIN MENU-----------------------------
                {
                    while (true)
                    {
                        Header();
                        subHeader("Admin Menu");
                        choice = adminMenu();
                        clearIt();
                        if (choice == 1) //*************done
                        {
                            if (x == size)
                            {
                                Header();
                                subHeader("Add User");
                                cout << "Records full! Delete users to add more.";
                                clearIt();
                                break;
                            }

                            Header();
                            subHeader("Add User");
                            cout << "Enter Username=> ";
                            cin >> username;
                            cout << "Enter Password=> ";
                            cin >> password;
                            clearIt();

                            AddUser(username, password);
                        }
                        else if (choice == 2) //*************done
                        {
                            Header();
                            subHeader("Delete User");
                            cout << "Enter id of the user=> ";
                            cin >> check_id;
                            clearIt();
                            flag1 = DeleteUser(check_id);
                            if (flag1 == true)
                            {
                                Header();
                                subHeader("Delete User");
                                cout << "User deleted successfully!" << endl;
                                clearIt();
                            }
                            else
                            {
                                Header();
                                subHeader("Delete User");
                                cout << "No record found against the given id" << endl;
                                clearIt();
                            }
                        }
                        else if (choice == 3) //*************done
                        {
                            Header();
                            subHeader("Update Record");
                            cout << "Enter id of the user=> ";
                            cin >> check_id;
                            clearIt();
                            getint = CheckUserExist(check_id);
                            if (getint >= 0)
                            {
                                Header();
                                subHeader("Update Record");
                                ConfirmUpdate(getint);
                                cout << "Data updated successfully!" << endl;
                                clearIt();
                            }
                            else if (getint == -1)
                            {
                                Header();
                                subHeader("Update Record");
                                cout << "No record found against the given id" << endl;
                                clearIt();
                            }
                        }
                        else if (choice == 4) //*************done
                        {
                            Header();
                            subHeader("View User");
                            cout << "Enter id of the user=> ";
                            cin >> check_id;
                            clearIt();
                            getint = CheckUserExist(check_id);
                            if (getint >= 0)
                            {
                                Header();
                                subHeader("View User");
                                showData(getint, getint + 1);
                                clearIt();
                            }
                            else if (getint == -1)
                            {
                                Header();
                                subHeader("View User");
                                cout << "No record found against the given id" << endl;
                                clearIt();
                            }
                        }
                        else if (choice == 5) //*************done
                        {
                            Header();
                            subHeader("View All Users");
                            showData(1, size);
                            clearIt();
                        }
                        else if (choice == 6) //*************done
                        {
                            Header();
                            subHeader("Create Package");
                            if (p == 10)
                            {
                                cout << "Can not add more packages!";
                                clearIt();
                            }
                            else
                            {
                                cout << "Enter the amount of data(Mbs)=> ";
                                cin >> amount;
                                cout << "Enter the validity of package(days)=> ";
                                cin >> validity;
                                cout << "Enter price of the package=> ";
                                cin >> price;
                                CreatePackages(amount, validity, price);
                                cout << "Package added successfully!" << endl;
                                clearIt();
                            }
                        }
                        else if (choice == 7) //*************done
                        {
                            if (c != 0)
                            {
                                Header();
                                subHeader("Check Requests");
                                getint = showRequests();
                                if (getint == -1)
                                {
                                    clearIt();
                                }
                                else
                                {
                                    approve(getint);
                                    clearIt();
                                }
                            }
                            else
                            {
                                cout << "No requests found.";
                                clearIt();
                            }
                        }
                        else if (choice == 8) //*************done
                        {
                            Header();
                            subHeader("Change Credentials");
                            cout << "Enter your current Username=> ";
                            cin >> username;
                            cout << "Enter your current Password=> ";
                            cin >> password;
                            clearIt();
                            getint = CheckTrue(username, password);
                            if (getint >= 0)
                            {
                                Header();
                                subHeader("Change Credentials");
                                cout << "Enter New Username=> ";
                                cin >> name[getint];
                                cout << "Enter New Password=> ";
                                cin >> passwords[getint];
                                cout << "Credentials Changed successfully!" << endl;
                                clearIt();
                            }
                            else if (getint == -1)
                            {
                                Header();
                                subHeader("Change Credentials");
                                cout << "Wrong Username or Password." << endl;
                                clearIt();
                            }
                        }
                        else if (choice == 9) //*************done
                        {
                            break;
                        }
                    }
                }
                else if (check == 2) //-----------------------USER MENU-----------------------------
                {
                    while (true)
                    {
                        Header();
                        subHeader("User Menu");
                        choice = userMenu();
                        clearIt();
                        if (choice == 1)
                        {
                            Header();
                            subHeader("View Dues");
                            if (ApprovedPackage[current_user] == "-1")
                            {
                                cout << "No current connection.";
                                clearIt();
                            }
                            else
                            {
                                cout << prices[current_user];
                                clearIt();
                            }
                        }
                        else if (choice == 2)
                        {
                            //Not yet done
                        }
                        else if (choice == 3) //*************done
                        {
                            Header();
                            subHeader("Current Package");
                            if (assignedPackage[current_user] == -1)
                            {
                                cout << "No current package. press 1 to apply, press 2 to exit";
                                cin >> choiceSub;
                                clearIt();
                                if (choiceSub == 1)
                                {
                                    Header();
                                    subHeader("Current Package");
                                    showPackages(0, p);
                                    cout << "Press cooresponding number of the packages to apply=> ";
                                    cin >> choiceSubSub;
                                    apply(choiceSubSub);
                                    cout << "Request has been sent to the admin. wait for approval." << endl;
                                    assignedPackage[current_user] = 1;
                                    clearIt();
                                }
                                else if (choiceSub == 2)
                                {
                                    Header();
                                    subHeader("Current Package");
                                    clearIt();
                                }
                            }
                            else if (assignedPackage[current_user] == 1)
                            {
                                Header();
                                subHeader("Current Package");
                                showPackages(current_user, current_user + 1);
                                clearIt();
                            }
                        }
                        else if (choice == 4) //*************done
                        {
                            Header();
                            subHeader("Current Package");
                            showPackages(0, p);
                            clearIt();
                        }
                        else if (choice == 5)
                        {
                            //Not yet done
                        }
                        else if (choice == 6)
                        {
                            //Not yet done
                        }
                        else if (choice == 7) //*************done
                        {
                            Header();
                            subHeader("Change Password");
                            cout << "Enter your current Password=> ";
                            cin >> password;
                            clearIt();
                            getint = ChangePassword(password);
                            if (getint >= 0)
                            {
                                Header();
                                subHeader("Change Password");
                                cout << "Enter New Password=> ";
                                cin >> passwords[getint];
                                cout << "Password Changed successfully!" << endl;
                                clearIt();
                            }
                            else if (getint == -1)
                            {
                                Header();
                                subHeader("Change Password");
                                cout << "Wrong Password." << endl;
                                clearIt();
                            }
                        }
                        else if (choice == 8) //*************done
                        {
                            break;
                        }
                    }
                }
            }
        }
        if (choice == 3)
        {
            yes = false;
        }
    }
}

//__________________________________________________________________________________________
//******************************************************************************************
//__________________________________________________________________________________________

void approve(int getint)
{
    ApprovedPackage[getint] = packages[userApprovePackage[getint]];
}

int ChangePassword(string password)
{
    if (passwords[current_user] == password)
    {
        return current_user;
    }
    return -1;
}

int showRequests()
{
    int choiceSub;
    cout << "  " << "\t\t\t\t" << "User ID" << "\t\t\t\t" << "Name" << "\t\t\t\t" << "Package Name" << endl;
    for (int x = 0; x < c; x++)
    {
        cout << x + 1 << "\t\t\t\t" << unique_id[userApproveId[x]] << "\t\t\t\t" << name[userApproveId[x]] << "\t\t\t\t" << packages[userApprovePackage[x]] << endl;
    }
    cout << "Press cooresponding number of the request to approve or 0 to exit=> ";
    cin >> choiceSub;
    if (choiceSub != 0)
    {
        return choiceSub-1;
    }
    return -1;
}

void showPackages(int get, int itter)
{
    for (int x = get; x < itter; x++)
    {
        if (packages[x] != "-1")
        {
            cout << x + 1 << "\t" << packages[x] << " in " << prices[x] << "Rs" << endl;
        }
    }
}

void apply(int choiceSubSub)
{
    userApprovePackage[c] = choiceSubSub - 1;
    userApproveId[c] = current_user;
    c++;
}

void CreatePackages(string amount, string validity, int price)
{
    string packagename = amount + " Mbs for " + validity + " days";
    packages[p] = packagename;
    prices[p] = price;
    p++;
}

bool signUp(string username, string password, string roletemp)
{
    for (int y = 0; y < size; y++)
    {
        if (username == name[y])
        {
            return false;
        }
    }
    name[x] = username;
    passwords[x] = password;
    role[x] = roletemp;
    unique_id[x] = x;
    x++;
    return true;
}

int login(string username, string password)
{
    bool flag = false;
    int y = 0;
    int idx = -1;
    int check = 3;
    for (; y < size; y++)
    {
        if (username == name[y] && password == passwords[y])
        {
            flag = true;
            idx = y;
            break;
        }
    }
    if (idx != -1)
    {
        if (role[idx] == "admin" && flag == true)
        {
            check = 1;
        }
        else if (role[idx] == "user" && flag == true)
        {
            check = 2;
            current_user = idx;
        }
    }
    return check;
}

void AddUser(string username, string password)
{
    name[x] = username;
    passwords[x] = password;
    role[x] = "user";
    unique_id[x] = x;
    x++;
}

bool DeleteUser(int check_id)
{
    bool flag = false;

    for (int y = 0; y < 10; y++)
    {
        if (unique_id[y] == check_id && y != 0)
        {
            flag = DeleteConfirm(y);
            break;
        }
    }
    return flag;
}

bool DeleteConfirm(int y)
{
    char yes_or_no;
    bool flag = false;

    cout << "Are you sure you want to delete this record(y/n)?";
    cin >> yes_or_no;
    if (yes_or_no == 'y')
    {
        unique_id[y] = -1;
        name[y] = "null";
        passwords[y] = "null";
        flag = true;
    }
    else if (yes_or_no == 'n')
    {
        flag = true;
    }
    return flag;
}

void ConfirmUpdate(int y)
{
    int check;
    cout << "Enter new name of the user=> ";
    cin >> name[y];
    cout << "Enter new package number of the user=> ";
    cin >> check;
    ApprovedPackage[y] = packages[check];
}

int CheckUserExist(int check_id)
{
    for (int y = 0; y < 10; y++)
    {
        if (unique_id[y] == check_id)
        {
            return y;
        }
    }
    return -1;
}

void showData(int getint, int itter)
{
    cout << "ID \t\t\tName \t\t\tRole" << endl;
    for (int y = getint; y < itter; y++)
    {
        if (unique_id[y] != -1)
        {
            cout << unique_id[y] << "\t\t\t" << name[y] << "\t\t\t" << role[y] << endl;
        }
    }
}

int CheckTrue(string username, string password)
{
    int y = -1;
    for (int y = 0; y < size; y++)
    {
        if (username == name[y] && password == passwords[y] && role[y] == "admin")
        {
            return y;
        }
    }
    return y;
}

void Header()
{
    cout << "::::::::::: ::::    ::: ::::::::::: :::::::::: :::::::::  ::::    ::: :::::::::: :::::::::::       ::::::::: ::::::::::: :::        :::        ::::::::::: ::::    :::  ::::::::  " << endl;
    cout << "    :+:     :+:+:   :+:     :+:     :+:        :+:    :+: :+:+:   :+: :+:            :+:           :+:    :+:    :+:     :+:        :+:            :+:     :+:+:   :+: :+:    :+: " << endl;
    cout << "    +:+     :+:+:+  +:+     +:+     +:+        +:+    +:+ :+:+:+  +:+ +:+            +:+           +:+    +:+    +:+     +:+        +:+            +:+     :+:+:+  +:+ +:+        " << endl;
    cout << "    +#+     +#+ +:+ +#+     +#+     +#++:++#   +#++:++#:  +#+ +:+ +#+ +#++:++#       +#+           +#++:++#+     +#+     +#+        +#+            +#+     +#+ +:+ +#+ :#:        " << endl;
    cout << "    +#+     +#+  +#+#+#     +#+     +#+        +#+    +#+ +#+  +#+#+# +#+            +#+           +#+    +#+    +#+     +#+        +#+            +#+     +#+  +#+#+# +#+   +#+# " << endl;
    cout << "    #+#     #+#   #+#+#     #+#     #+#        #+#    #+# #+#   #+#+# #+#            #+#           #+#    #+#    #+#     #+#        #+#            #+#     #+#   #+#+# #+#    #+# " << endl;
    cout << "########### ###    ####     ###     ########## ###    ### ###    #### ##########     ###           ######### ########### ########## ########## ########### ###    ####  ########  " << endl;
    cout << "                                                             ::::::::  :::   :::  :::::::: ::::::::::: :::::::::: ::::    ::::                                                    " << endl;
    cout << "                                                            :+:    :+: :+:   :+: :+:    :+:    :+:     :+:        +:+:+: :+:+:+                                                   " << endl;
    cout << "                                                            +:+         +:+ +:+  +:+           +:+     +:+        +:+ +:+:+ +:+                                                   " << endl;
    cout << "                                                            +#++:++#++   +#++:   +#++:++#++    +#+     +#++:++#   +#+  +:+  +#+                                                   " << endl;
    cout << "                                                                   +#+    +#+           +#+    +#+     +#+        +#+       +#+                                                   " << endl;
    cout << "                                                            #+#    #+#    #+#    #+#    #+#    #+#     #+#        #+#       #+#                                                   " << endl;
    cout << "                                                             ########     ###     ########     ###     ########## ###       ###                                                   " << endl;
    cout << "                                                                                                                                                                                  " << endl;
    cout << "**********************************************************************************************************************************************************************************" << endl;
    cout << "**********************************************************************************************************************************************************************************" << endl;
    cout << endl << endl;
}

void subHeader(string sub)
{
    cout << "                                                                    _______________________________________________" << endl;
    cout << "                                                                                       " << sub << "                " << endl;
    cout << "                                                                   |_______________________________________________|" << endl;
    cout << endl;
}

int loginMenu()
{
    int choice;
    cout << "                                                                                       __________         " << endl;
    cout << "                                                                             1.       |__SignUp__|        " << endl;
    cout << "                                                                                       __________          " << endl;
    cout << "                                                                             2.       |__ Login__|         " << endl;
    cout << "                                                                                  _____________________    " << endl;
    cout << "                                                                             3.  |__Terminate Program__|   " << endl;
    cout << "Your choice=> ";
    cin >> choice;
    return choice;
}

int adminMenu()
{
    int choice;
    cout << "                                                                                      ____________" << endl;
    cout << "                                                                             1.      |__Add User__|" << endl;
    cout << "                                                                                     _______________" << endl;
    cout << "                                                                             2.     |__Delete User__|" << endl;
    cout << "                                                                                    _________________" << endl;
    cout << "                                                                             3.    |__Update Record__|" << endl;
    cout << "                                                                                      _____________" << endl;
    cout << "                                                                             4.      |__View User__|" << endl;
    cout << "                                                                                    __________________" << endl;
    cout << "                                                                             5.    |__View All Users__|" << endl;
    cout << "                                                                                    __________________" << endl;
    cout << "                                                                             6.    |__Create Package__|" << endl;
    cout << "                                                                                    __________________" << endl;
    cout << "                                                                             7.    |__Check Requests__|" << endl;
    cout << "                                                                                  ______________________" << endl;
    cout << "                                                                             8.  |__Change Credentials__|" << endl;
    cout << "                                                                                        __________" << endl;
    cout << "                                                                             9.        |__Logout__|" << endl;
    cout << "Your Choice=> ";
    cin >> choice;
    return choice;
}

int userMenu()
{
    int choice;
    cout << "                                                                                        _____________" << endl;
    cout << "                                                                             1.        |__View Dues__|" << endl;
    cout << "                                                                                   _______________________" << endl;
    cout << "                                                                             2.   |__Check Dues Deadline__|" << endl;
    cout << "                                                                                     ___________________" << endl;
    cout << "                                                                             3.     |__Current Package__|" << endl;
    cout << "                                                                                       ________________" << endl;
    cout << "                                                                             4.       |__All Packages__|" << endl;
    cout << "                                                                                 ____________________________" << endl;
    cout << "                                                                             5. |__Apply For Package Change__|" << endl;
    cout << "                                                                                       _______________" << endl;
    cout << "                                                                             6.       |__Submit Dues__|" << endl;
    cout << "                                                                                      ___________________" << endl;
    cout << "                                                                             7.      |__Change Password__|" << endl;
    cout << "                                                                                          __________" << endl;
    cout << "                                                                             8.          |__Logout__|" << endl;
    cout << "Your Choice=> ";
    cin >> choice;
    return choice;
}

void clearIt()
{
    cout << "Press any key to continue... ";
    getch();
    system("cls");
}