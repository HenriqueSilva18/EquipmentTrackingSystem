/**
 *  @file equipments.h
 *  @author Henrique Silva
 *  @date 07-02-2024
 *  @version 1.0
 * 
 *  @brief Defines functions for managing equipment data in the equipment management system.
 * 
 *  This header file contains declarations for functions related to managing equipment data within the equipment management system. It provides functionality for adding, listing, removing, and editing equipment entries, as well as searching for equipment by ID or category. Additionally, it includes functions for retrieving equipment status and category information.
 * 
 *  @copyright Copyright (C) Henrique Silva 2024. All Rights Reserved.
 */

#ifndef EQUIPMENTS_H
#define EQUIPMENTS_H

#include "utilities.h"

#define INITIAL_ALLOCATED_EQUIPMENTS    5
#define MAX_CHAR                        50
#define MESSAGE_GET_EQUIPMENT_STATUS    "\nEnter equipment's status (1-4)\n1 - Operational; 2 - Not operational; 3 - Under Maintenance; 4 - Ready to recycle:\n"
#define MESSAGE_GET_EQUIPMENT_CATEGORY  "\nEnter equipment's category (1 - 12)\n1 - Printer; 2 - Desktop; 3 - Laptop; 4 - Monitor; 5 - Router; 6 - Switch; 7 - TV; 8 - Projector; 9 - Access Controller; 10 - Mouse; 11 - Accessory; 12 - Other:\n"

/**
 * @brief Returns the category enum value corresponding to the given category number.
 * 
 * This function maps a category number to its corresponding Category enum value.
 * 
 * @param category_number The category number to be mapped.
 * @return The Category enum value corresponding to the given category number.
 */
Category getCategory (int category_number);

/**
 * @brief Returns the EquipmentStatus enum value corresponding to the given status number.
 * 
 * This function maps a status number to its corresponding EquipmentStatus enum value.
 * 
 * @param status_number The status number to be mapped.
 * @return The EquipmentStatus enum value corresponding to the given status number.
 */
EquipmentStatus getStatus (int status_number);

/**
 * @brief Returns the string representation of the given EquipmentStatus.
 * 
 * This function returns the string representation of the given EquipmentStatus enum value.
 * 
 * @param status The EquipmentStatus enum value.
 * @return The string representation of the given EquipmentStatus.
 */
const char* getEquipmentStatusString(EquipmentStatus status);

/**
 * @brief Returns the string representation of the given equipment category.
 * 
 * This function returns the string representation of the given equipment category.
 * 
 * @param category The category number in the enum.
 * @return The string representation of the given equipment category.
 */
const char* getEquipmentCategoryString(int category);

/**
 *  @brief Adds a new equipment to the system.
 * 
 *  This function adds a new equipment to the system. It prompts the user to input the designation,
 *  category, status, and acquisition date of the equipment. Additionally, it allows associating the 
 *  equipment with a user from the system, if desired.
 * 
 *  @param eq Pointer to the Equipments structure.
 *  @param m Pointer to the Maintenances structure.
 *  @param u Pointer to the Users structure.
 */
void addEquipment(Equipments *eq, Maintenances *m, Users *u);

/**
 * @brief Lists all equipments marked as 'Ready to Recycle'.
 * 
 * This function displays a list of all equipments in the system that are marked as 'Ready to Recycle'.
 * The list includes each equipment's ID, designation, category, and date of acquisition.
 * 
 * @param eq Pointer to the Equipments structure.
 */
void listToRecycleEquipments(Equipments *eq);

/**
 * @brief Lists all free equipments in the system.
 * 
 * This function prints a list of all equipments that are currently not assigned to any user 
 * and are not marked as 'Ready to Recycle'. The list includes the equipment's ID, designation, 
 * category, date of acquisition, and status.
 * 
 * @param eq Pointer to the Equipments structure.
 */
void listFreeEquipments(Equipments *eq);

/**
 * @brief Removes an equipment from the system.
 * 
 * This function allows the user to remove an equipment from the system by providing its ID. 
 * The equipment must be marked as 'Ready to Recycle' and not assigned to any user in order to be removed.
 * 
 * @param eq Pointer to the Equipments structure.
 */
void removeEquipment(Equipments *eq);

/**
 * @brief Edits an existing equipment in the system.
 * 
 * This function allows the user to edit an existing equipment in the system by providing its ID. 
 * The user can modify the equipment's designation, category, status, acquisition date, and association with a user.
 * 
 * @param eq Pointer to the Equipments structure.
 * @param u Pointer to the Users structure.
 */
void editEquipment(Equipments *eq, Users *u);

/**
 * @brief Edits the status of an existing equipment.
 * 
 * This function allows the user to edit the status of an existing equipment in the system by providing its ID. 
 * The user is allowed to change the equipment to any status, unless the equipment is assigned to a user (in that case, it can't have the status 'Ready to Recycle').
 * 
 * @param eq Pointer to the Equipments structure.
 */
void editEquipmentStatus(Equipments *eq);

/**
 * @brief Displays a menu for searching equipments by ID or category.
 * 
 * This function presents a menu for the user to choose between searching equipments by their ID or category.
 * It then calls the appropriate function based on the user's choice.
 * 
 * @param eq Pointer to the Equipments structure.
 */
void searchEquipmentsMenu(Equipments *eq);

/**
 * @brief Searches for equipments by category and prints the list.
 *
 * This function searches for equipments by a specified category and prints the list of equipments found.
 *
 * @param eq Pointer to the Equipments structure.
 */
void searchEquipmentsByCategory(Equipments *eq);

/**
 * @brief Searches for equipments by ID and prints the details.
 *
 * This function searches for equipments by a specified ID and prints its details if found.
 *
 * @param eq Pointer to the Equipments structure.
 */
void searchEquipmentsByID(Equipments *eq);
#endif /* EQUIPMENTS_H */

