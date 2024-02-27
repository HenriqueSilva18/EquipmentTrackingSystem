#include "equipments.h"
#include "utilities.h"
#include "users.h"
#include "stdio.h"
#include "stdlib.h"

void addEquipment(Equipments *eq, Maintenances *m, Users *u) {
    int *temp;
    Date acquisition_date;
    Equipment new_equipment, *temp2;
    if (eq->allocated == eq->counter) {
        eq->allocated *= 2;
        temp2 = (Equipment *) realloc(eq->equipments, eq->allocated * sizeof(Equipment));
        if (temp2 == NULL) {
            printf("\nError reallocating memory.");
            exit(EXIT_FAILURE);
        }
        eq->equipments = temp2;
        if (eq->equipments == NULL) {
            printf("\nError reallocating memory.");
            exit(EXIT_FAILURE);
        }
    }
    readString(new_equipment.designation, MAX_CHAR, "\nEnter equipment's designation: ");
    new_equipment.id_equipment = ++eq->id_count;
    new_equipment.category = getCategory(getInt(1, 12, MESSAGE_GET_EQUIPMENT_CATEGORY));
    new_equipment.status = getStatus(getInt(1, 4, MESSAGE_GET_EQUIPMENT_STATUS));
    if (new_equipment.status != READY_TO_RECYCLE) {
        if (u->id_count > 0) {
            listUsers(u);
            new_equipment.id_code_user = getInt(0, u->id_count, "\n\nDo you pretend to associate this equipment with any user?\nEnter its ID (0 for no association): ");
            if (new_equipment.id_code_user != 0) {
                if (u->users[new_equipment.id_code_user - 1].status == INACTIVE) {
                    printf("This user can't have any equipments assigned to it, since it's inactive. ");
                    new_equipment.id_code_user = 0;
                } else {
                    temp = realloc(u->users[new_equipment.id_code_user - 1].equipments, sizeof(int) * (u->users[new_equipment.id_code_user - 1].count_equipments + 1));
                    if (temp == NULL) {
                        printf("Error reallocating memory.\n");
                        return;
                    }
                    u->users[new_equipment.id_code_user - 1].equipments = temp;
                    u->users[new_equipment.id_code_user - 1].equipments[u->users[new_equipment.id_code_user - 1].count_equipments] = eq->id_count;
                    u->users[new_equipment.id_code_user - 1].count_equipments++;
                }
            }
        } else {
            new_equipment.id_code_user = 0;
        }
    } else {
        new_equipment.id_code_user = 0;
    }
    acquisition_date = getDate("\nEnter acquisition day: ", "Enter acquisition month: ", "Enter acquisition year: ");
    new_equipment.date_aquisition = acquisition_date;
    new_equipment.number_maintenances = 0;
    new_equipment.maintenance = NULL;
    eq->equipments[eq->counter] = new_equipment;
    eq->counter++;
    printf("\nEquipment sucessfully created. ");
}

void listFreeEquipments(Equipments *eq) {
    int i;
    printf("List of Free Equipments:\n");
    printf("ID | Designation         | Category | Date of Acquisition  | Status\n");
    printf("-------------------------------------------------------------------\n");
    
    for (i = 0; i < eq->id_count; i++) {
        if (eq->equipments[i].id_equipment == 0) {
            continue;
        }
        if (eq->equipments[i].id_code_user == 0 && eq->equipments[i].status != READY_TO_RECYCLE) {
            printf("%2d | %-20s | %-8s | %02d/%02d/%04d       | %s\n", 
                   eq->equipments[i].id_equipment, 
                   eq->equipments[i].designation, 
                   getEquipmentCategoryString(eq->equipments[i].category), 
                   eq->equipments[i].date_aquisition.day,
                   eq->equipments[i].date_aquisition.month,
                   eq->equipments[i].date_aquisition.year,
                   getEquipmentStatusString(eq->equipments[i].status));
        }
    }
}

void listToRecycleEquipments(Equipments *eq) {
    int i;
    printf("List of Equipments to Recycle:\n");
    printf("ID | Designation         | Category | Date of Acquisition\n");
    printf("------------------------------------------------------------\n");
    
    for (i = 0; i < eq->counter; i++) {
        if (eq->equipments[i].status == READY_TO_RECYCLE) {
            printf("%2d | %-20s | %-8s | %02d/%02d/%04d\n", 
                   eq->equipments[i].id_equipment, 
                   eq->equipments[i].designation, 
                   getEquipmentCategoryString(eq->equipments[i].category), 
                   eq->equipments[i].date_aquisition.day,
                   eq->equipments[i].date_aquisition.month,
                   eq->equipments[i].date_aquisition.year);
        }
    }
}

void removeEquipment(Equipments *eq) {
    int i, j, id;
    id = getInt(0, eq->id_count, "Enter the ID of the equipment to remove (0 to cancel): ");

    for (i = 0; i < eq->counter; i++) {
        if (eq->equipments[i].id_equipment == id) {
            if (eq->equipments[i].status == READY_TO_RECYCLE && eq->equipments[i].id_code_user == 0) {
                
                free(eq->equipments[i].maintenance);
                eq->equipments[i].id_code_user = -1;
                for (j = i; j < eq->counter - 1; j++) {
                    eq->equipments[j] = eq->equipments[j + 1];
                }
                eq->counter--;
                eq->equipments = (Equipment *)realloc(eq->equipments, sizeof(Equipment) * eq->allocated);
                printf("Equipment removed successfully.\n");
                return;
            } else {
                printf("Equipment cannot be removed. It must be 'Ready to Recycle' and not assigned to any user.\n");
                return;
            }
        }
    }
    if (id != 0) {
        printf("Equipment not found.\n");
    }
}

void searchEquipmentsMenu(Equipments *eq) {
    int choice;
    choice = getInt(1, 2, "Would you like to search equipments by 1 - ID or 2 - category?: ");
    switch (choice) {
        case 1:
            searchEquipmentsByID(eq);
            break;
        case 2:
            searchEquipmentsByCategory(eq);
            break;
    }
}

void editEquipment(Equipments *eq, Users *u) {
    int i, id;
    id = getInt(1, eq->id_count, "Enter the ID of the equipment to edit: ");

    for (i = 0; i < eq->counter; i++) {
        if (eq->equipments[i].id_equipment == id) {
            
            readString(eq->equipments[i].designation, MAX_CHAR, "Enter designation: ");
            eq->equipments[i].category = getCategory(getInt(1, 12, MESSAGE_GET_EQUIPMENT_CATEGORY));
            eq->equipments[i].status = getStatus(getInt(1, 4, MESSAGE_GET_EQUIPMENT_STATUS));
            eq->equipments[i].date_aquisition = getDate("Enter new acquisition day: ", "Enter new acquisition month: ", "Enter new acquisition year: ");
            
            if (u->counter > 0 && eq->equipments[i].status != READY_TO_RECYCLE) {
                listUsers(u);
                eq->equipments[i].id_code_user = getInt(0, u->id_count, "Enter new user ID (0 for no association): ");
            }
            printf("Equipment updated successfully.\n");
            return;
        }
    }
    printf("Equipment not found.\n");
}

void searchEquipmentsByCategory(Equipments *eq) {
    int category, i;
    category = getInt(1, 12, MESSAGE_GET_EQUIPMENT_CATEGORY);
    
    printf("List of Equipments:\n");
    printf("ID | Designation         | Category | Date of Acquisition  | Status\n");
    printf("-------------------------------------------------------------------\n");
    
    for (i = 0; i < eq->counter; i++) {
        if (eq->equipments[i].category == category) {
            if (eq->equipments[i].status == READY_TO_RECYCLE) {
                continue;
            }
            printf("%2d | %-20s | %-8s | %02d/%02d/%04d       | %s\n", 
                   eq->equipments[i].id_equipment, 
                   eq->equipments[i].designation, 
                   getEquipmentCategoryString(eq->equipments[i].category), 
                   eq->equipments[i].date_aquisition.day,
                   eq->equipments[i].date_aquisition.month,
                   eq->equipments[i].date_aquisition.year,
                   getEquipmentStatusString(eq->equipments[i].status));
        }
    }
}

void searchEquipmentsByID(Equipments *eq) {
    int id, i;
    id = getInt(1, eq->id_count, "Enter the equipment's ID: ");
    
    printf("List of Equipments:\n");
    printf("ID | Designation         | Category | Date of Acquisition  | Status\n");
    printf("-------------------------------------------------------------------\n");
    
    for (i = 0; i < eq->counter; i++) {
        if (eq->equipments[i].id_equipment == id) {
            if (eq->equipments[i].status == READY_TO_RECYCLE) {
                continue;
            }
            printf("%2d | %-20s | %-8s | %02d/%02d/%04d       | %s\n", 
                   eq->equipments[i].id_equipment, 
                   eq->equipments[i].designation, 
                   getEquipmentCategoryString(eq->equipments[i].category), 
                   eq->equipments[i].date_aquisition.day,
                   eq->equipments[i].date_aquisition.month,
                   eq->equipments[i].date_aquisition.year,
                   getEquipmentStatusString(eq->equipments[i].status));
            return;
        }
    }
    printf("Equipment not found.\n");
}

void editEquipmentStatus(Equipments *eq) {
    int i, id, newStatus;
    id = getInt(1, eq->id_count, "Enter equipment ID to edit status: ");
    
    for (i = 0; i < eq->id_count; i++) {
        if (eq->equipments[i].id_equipment == id) {
            newStatus = getInt(1, 4, MESSAGE_GET_EQUIPMENT_STATUS);
            
            if(eq->equipments[eq->id_count - 1].id_code_user != 0 && getStatus(newStatus) == READY_TO_RECYCLE) {
                printf("\nThis equipment is assigned to a user, so it can't be recycled yet. ");
                return;
            }
            eq->equipments[i].status = getStatus(newStatus);
            printf("Equipment status updated successfully.\n");
            return;
        }
    }
    printf("Equipment not found.\n");
}

Category getCategory(int category_number) {
    switch (category_number){
        case 1: return PRINTER;
        case 2: return DESKTOP;
        case 3: return LAPTOP;
        case 4: return MONITOR;
        case 5: return ROUTER;
        case 6: return SWITCH;
        case 7: return TV;
        case 8: return PROJECTOR;
        case 9: return ACCESS_CONTROLLER;
        case 10: return MOUSE;
        case 11: return ACCESSORY;
        default: return OTHER;
    }
}

EquipmentStatus getStatus(int status_number) {
    switch (status_number){
        case 1: return OPERATIONAL;
        case 2: return NOT_OPERATIONAL; 
        case 3: return UNDER_MAINTENANCE; 
        default: return READY_TO_RECYCLE;
    }
}

const char* getEquipmentStatusString(EquipmentStatus status) {
    switch (status) {
        case OPERATIONAL: return "Operational";
        case NOT_OPERATIONAL: return "Not operational";
        case UNDER_MAINTENANCE: return "Under maintenance";
        default: return "Ready to recycle";
    }
}

const char* getEquipmentCategoryString(int category) {
    switch (category) {
        case 1: return "Printer"; 
        case 2: return "Desktop";
        case 3: return "Laptop";
        case 4: return "Monitor";
        case 5: return "Router";
        case 6: return "Switch";
        case 7: return "TV";
        case 8: return "Projector";
        case 9: return "Access Controller";
        case 10: return "Mouse";
        case 11: return "Accessory";
        default: return "Other";
    }
}

