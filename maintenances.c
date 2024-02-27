#include "maintenances.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>

void addNewMaintenance(Equipments *eq, Maintenances *maintenances) {
    int id_eq, type, *temp;
    Maintenance new_maintenance, *temp2;
    Equipment *equipment;
    id_eq = getInt(0, eq->id_count, "Enter the equipment ID for maintenance (0 to cancel): ");
    if (id_eq == 0) {
        return;
    }
    equipment = &eq->equipments[id_eq - 1];
    
    new_maintenance.date_maintenance = getDate("Enter maintenance day: ", "Enter maintenance month: ", "Enter maintenance year: ");
    type = getInt(1, 4, "Enter the type of maintenance (1 - Software Update, 2 - Replacements, 3 - Technical, 4 - Other: ");
    
    new_maintenance.type = (MaintenanceType)type;
    
    readString(new_maintenance.information, MAX_CHAR, "Enter maintenance information: ");
    new_maintenance.movement_number = maintenances->id_count + 1;

    temp = realloc(equipment->maintenance, sizeof(int) * (equipment->number_maintenances + 1));
    if (temp == NULL) {
        printf("ERROR ALLOCATING MEMORY.\n");
        return;
    }
    equipment->maintenance = temp;
    equipment->maintenance[equipment->number_maintenances] = new_maintenance.movement_number;
    equipment->number_maintenances++;
    
    if (maintenances->allocated == maintenances->counter) {
        maintenances->allocated *= 2;
        temp2 = realloc(maintenances->maintenance, sizeof(Maintenance) * maintenances->allocated);
        if (temp2 == NULL) {
            printf("ERROR ALLOCATING MEMORY FOR MAINTENANCES.\n");
            return;
        }
        maintenances->maintenance = temp2;
    }
    maintenances->maintenance[maintenances->counter] = new_maintenance;
    maintenances->counter++;
    maintenances->id_count++;

    printf("Maintenance successfully added.\n");
}

void viewEquipmentHistory(Equipments *eq, Maintenances *maintenances) {
    int id_eq, maintenance_id, i, j, found;
    Maintenance maintenance;
    
    id_eq = getInt(0, eq->id_count, "Enter the equipment ID to view it's historic maintenance (0 to cancel): ");
    if (id_eq == 0){
        return;
    }
    found = 0;
    for (i = 0; i < eq->counter; i++) {
        if (eq->equipments[i].id_equipment == id_eq) {
            found = 1;
            printf("Maintenance history to '%s' (ID: %d):\n", eq->equipments[i].designation, id_eq);
            if (eq->equipments[i].number_maintenances == 0) {
                printf("No maintenance registered to this equipment.\n");
            } else {
                printf("Maintenance ID | Maintenance Date | Informations\n");
                printf("--------------------------------------------\n");
                for (j = 0; j < eq->equipments[i].number_maintenances; j++) {
                    maintenance_id = eq->equipments[i].maintenance[j];
                    maintenance = maintenances->maintenance[maintenance_id - 1];
                    printf("%16d | %02d/%02d/%04d | %s\n",
                           maintenance.movement_number,
                           maintenance.date_maintenance.day,
                           maintenance.date_maintenance.month,
                           maintenance.date_maintenance.year,
                           maintenance.information);
                }
            }
            break;
        }
    }
    if (!found) {
        printf("Equipment's ID %d not found.\n", id_eq);
    }
}