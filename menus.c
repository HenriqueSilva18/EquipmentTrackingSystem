#include "menus.h"
#include "utilities.h"
#include "equipments.h"
#include "maintenances.h"
#include <stdio.h>

void menuFrame(int *option, Equipments *e, Maintenances *m, Users *u) {
    do {
       mainMenu(option);
       
       switch (*option) {
            case 0:
                break;
            case 1:
                userMenu(option, e, u);
                break;
            case 2:
                equipmentMenu(option, e, m ,u);
                break;
            default:
                printf("\nInvalid option!");
        }
    } while (*option != 0);
}

void mainMenu(int *option) {
    printf("\nMain Menu------------------------------------------------------");
    printf("\n1 - User Management");
    printf("\n2 - Equipment Management");
    printf("\n\n0 - Exit Program");
    printf("\n------------------------------------------------------------");

    *option = getInt(0 ,2, "\nOption: ");
}

void userMenu(int *option, Equipments *e, Users *u) {
    do {
        printf("\nUser Menu------------------------------------------------------");
        printf("\n1 - Create user");
        printf("\n2 - Edit user");
        printf("\n3 - Remove user");
        printf("\n4 - List users");
        printf("\n5 - Search equipment");
        printf("\n6 - Get equipment");
        printf("\n7 - Return equipment");
        printf("\n\n9 - Return to the previous menu");
        printf("\n0 - Exit Program");
        printf("\n------------------------------------------------------------");
        
        *option = getInt(0, 9, "\nOption: ");
        handleUserMenuOption(*option, e, u);
        
    } while (*option != 0 && *option != 9);
}

void equipmentMenu(int *option, Equipments *e, Maintenances *m, Users *u) {
    do {
        printf("\nEquipment Menu------------------------------------------------------");
        printf("\n1 - Add equipment");
        printf("\n2 - Edit equipment");
        printf("\n3 - Edit equipment's status");
        printf("\n4 - List free equipments");
        printf("\n5 - List equipments to recycle");
        printf("\n6 - Remove equipment");
        printf("\n7 - Add maintenance");
        printf("\n8 - See maintenance equipment history");
        printf("\n\n9 - Return to the previous menu");
        printf("\n0 - Exit Program");
        printf("\n------------------------------------------------------------");
        
        *option = getInt(0, 9, "\nOption: ");
        handleEquipmentMenuOption(*option, e, m, u);
        
    } while (*option != 0 && *option != 9);
}

void handleEquipmentMenuOption(int option, Equipments *e, Maintenances *m, Users *u) {
    switch (option) {
        case 1:
            addEquipment(e, m, u);
            break;
        case 2:
            editEquipment(e, u);
            break;
        case 3:
            editEquipmentStatus(e);
            break;
        case 4:
            listFreeEquipments(e);
            break;
        case 5:
            listToRecycleEquipments(e);
            break;
        case 6:
            removeEquipment(e);
            break;
        case 7:
            addNewMaintenance(e, m);
            break;
        case 8:
            viewEquipmentHistory(e, m);
            break;
        case 9:
            /*OPTION TO RETURN TO THE PREVIOUS MENU*/
            break;
        default:
            /*OPTION TO EXIT PROGRAM*/
            break;
    }
}

void handleUserMenuOption(int option, Equipments *e, Users *u) {
    switch (option) {
        case 1:
            addUser(u);
            break;
        case 2:
            editUser(u);
            break;
        case 3:
            removeUser(u);
            break;
        case 4:
            listUsers(u);
            break;
        case 5:
            searchEquipmentsMenu(e);
            break;
        case 6:
            getEquipment(e, u);
            break;
        case 7:
            returnEquipment(e, u);
            break;
        case 9:
            break;
        default:
            if (option == 8) {
                printf("Invalid option. Please try again.\n");
            } else {
                /*OPTION TO EXIT PROGRAM*/
                break;
            }
    }
}