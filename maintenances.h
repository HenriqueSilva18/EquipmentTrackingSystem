/**
 * @file maintenances.h
 * @author Henrique Silva
 * @date 07-02-2024
 * @version 1.0
 * 
 * @brief Defines functions for managing maintenance records for equipment.
 * 
 * This header file includes functions for adding new maintenance records for specific equipment 
 * and for viewing the maintenance history of equipment.
 * 
 * @copyright Copyright (C) Henrique Silva 2024. All Rights Reserved.
 */

#ifndef MAINTENANCES_H
#define MAINTENANCES_H

#include "utilities.h"
#define INITIAL_ALLOCATED_MAINTENANCES  5

/**
 * @brief Adds a new maintenance record for a specific equipment.
 * 
 * This function allows the user to add a new maintenance record for a specific equipment in the system.
 * It prompts the user to enter the equipment ID, maintenance date, type, and information.
 * The maintenance record is then added to both the equipment's maintenance history and the system-wide maintenance records.
 * 
 * @param eq Pointer to the Equipments structure.
 * @param maintenances Pointer to the Maintenances structure.
 */
void addNewMaintenance(Equipments *eq, Maintenances *maintenances);

/**
 * @brief Displays the maintenance history of a specific equipment.
 * 
 * This function allows the user to view the maintenance history of a specific equipment in the system.
 * It prompts the user to enter the equipment ID and then prints the maintenance records associated with that equipment.
 * 
 * @param eq Pointer to the Equipments structure.
 * @param maintenances Pointer to the Maintenances structure.
 */
void viewEquipmentHistory(Equipments *eq, Maintenances *maintenances);

#endif /* MAINTENANCES_H */

