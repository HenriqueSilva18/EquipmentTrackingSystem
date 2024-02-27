#include "users.h"
#include "utilities.h"
#include "stdio.h"
#include "stdlib.h"

void addUser(Users *users) {
    int newAllocated;
    User newUser, *temp;
    
    if (users->allocated == users->counter) {
        newAllocated = users->allocated * 2;
        temp = (User *) realloc(users->users, newAllocated * sizeof(User));
        if (temp == NULL) {
            printf("\nErro a realocar memória.");
            exit(EXIT_FAILURE);
        }
        users->users = temp;
        users->allocated = newAllocated;
    }
    readString(newUser.name, MAX_CHAR, "Enter user's name: ");
    readString(newUser.function, MAX_CHAR, "Enter user's function: ");
    readString(newUser.acronym, MAX_CHAR, "Enter user's acronym: ");
    newUser.id_code_user = ++users->id_count;
    newUser.equipments = NULL;
    newUser.status = ACTIVE;
    newUser.count_equipments = 0;
            
    users->users[users->counter] = newUser;
    users->counter++;
    printf("\nUser sucessfully created. ");
}

void listUsers(Users *users) {
    int i;
    printf("\nUser's list");
    printf("\nID  |Name                |Status         |Number of Equipments");
    printf("\n-----------------------------------------------------------------");
    for (i = 0; i < users->counter; i++) {
        printf("\n%-3d |%-20s |%-15s |%d",
               users->users[i].id_code_user, 
               users->users[i].name, 
               getUserStatusString(users->users[i].status), 
               users->users[i].count_equipments);
    }
}

void editUser(Users *users) {
    int id, i, active_status;
    listUsers(users);
    id = getInt(0, users->id_count, "\nWhich user you which to edit? (0 to cancel) ");
    if (id == 0) {
        printf("Returning to the previous menu. ");
        return;
    }
    for (i = 0; i < users->counter; i++) {
        if (users->users[i].id_code_user == id) {
            readString(users->users[i].name, MAX_CHAR, "Enter user's new name: ");
            readString(users->users[i].function, MAX_CHAR, "Enter user's new function: ");
            readString(users->users[i].acronym, MAX_CHAR, "Enter user's new acronym: ");
            if (users->users[i].status == INACTIVE) {
                active_status = getInt(0, 1, "This user is inactive.\nDo you pretend to activate this user? 1 - Yes\t2 - No: ");
                if (active_status == 1) {
                    users->users[i].status == ACTIVE;
                }
            }
            printf("\nUser successfully updated.");
            return;
        }
        printf("There's no user with that ID. ");
    }
}

void removeUser(Users *users) {
    int id, i, j;
    listUsers(users);
    id = getInt(0, users->id_count, "\nWhich user you which to remove? (0 to cancel) ");
    
    if (id == 0) {
        printf("Returning to the previous menu. ");
        return;
    }
    for (i = 0; i < users->counter; i++) {
        if (users->users[i].id_code_user == id) {
            if (users->users[i].count_equipments == 0) {
                for (j = i; j < users->counter - 1; j++) {
                    users->users[j] = users->users[j + 1];
                }
                users->counter--;
                users->users = (User *)realloc(users->users, sizeof(User) * (users->allocated));
                printf("User successfully removed.");
                return;
            } else {
                users->users[i].status = INACTIVE;
                printf("Since user had associated equipments, it's status is now %s.", getUserStatusString(users->users[i].status));
                return;
            }
        }
        printf("There's no user with that ID. ");
    }
}

void getEquipment(Equipments *eq, Users *users) {
    int id_user, id_equipment, *temp;
    
    id_user = getInt(0, users->id_count, "Insert user's ID (0 to cancel): ");
    if (id_user == 0) {
        return;
    } else if (users->users[id_user - 1].status == INACTIVE) {
        printf("This user is inactive, it's impossible to assign him any equipment.");
    }
    listFreeEquipments(eq);
    id_equipment = getInt(0, eq->id_count, "Insert equipment's ID (0 to cancel): ");
    if (id_equipment == 0) {
        return;
    }
    if (eq->equipments[id_equipment - 1].id_code_user == -1) {
        printf("This equipment ID is not available for assignment.\n");
        return;
    }
    
    if (eq->equipments[id_equipment - 1].id_code_user == 0) {
        if (eq->equipments[id_equipment - 1].status != READY_TO_RECYCLE) {
            eq->equipments[id_equipment - 1].id_code_user = id_user;
            temp = realloc(users->users[id_user - 1].equipments, sizeof(int) * (users->users[id_user - 1].count_equipments + 1));
            if (temp == NULL) {
                printf("ERROR ALLOCATING MEMORY.\n");
                return;
            }
            users->users[id_user - 1].equipments = temp;
            users->users[id_user - 1].equipments[users->users[id_user - 1].count_equipments] = id_equipment;
            printf("Equipment successfully assigned to the user. ");
            users->users[id_user - 1].count_equipments++;
        } else {
            printf("This equipment is ready to recycle, so it's unavailable. ");
        }
    } else {
        printf("This equipment is already assigned to another user. ");
    }
}

void returnEquipment(Equipments *eq, Users *users) {
    int id_equipment, id_user, i, j;
    id_user = getInt(0, users->id_count, "Enter the User ID (0 to cancel): ");
    if (id_user == 0) {
        return;
    }
    id_equipment = getInt(0, eq->id_count, "Enter the equipment's id that you want to return (0 to cancel): ");
    if (id_equipment == 0) {
        return;
    }
    if (eq->equipments[id_equipment - 1].id_code_user == 0 || eq->equipments[id_equipment - 1].id_code_user == -1) {
        printf("This equipment is not assigned to anyone. ");
    } else {
        for (i = 0; i < users->users[eq->equipments[id_equipment - 1].id_code_user - 1].count_equipments; i++) {
            if (users->users[id_user - 1].equipments[i] == id_equipment) {
            for (j = i; j < users->users[id_user - 1].count_equipments - 1; j++) {
                users->users[id_user - 1].equipments[j] = users->users[id_user - 1].equipments[j + 1];
            }
            users->users[id_user - 1].count_equipments--;
            eq->equipments->id_code_user = 0;
            
            printf("Equipment returned successfully.");
            break;
            }
        }
    }
}

const char* getUserStatusString(UserStatus status) {
    switch (status) {
        case ACTIVE: return "Active";
        case INACTIVE: return "Inactive";
        default: return "Unknown";
    }
}