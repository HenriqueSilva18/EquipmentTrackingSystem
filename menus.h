/* 
 *  @file menus.h
 *  @author Henrique Silva
 *  @date 07-02-2024
 *  @version 1.0
 * 
 *  @brief Header file for menu-related functions.
 * 
 *  This file contains declarations for functions related to menus, including main menu, user menu, and equipment menu.
 *  It also includes functions to handle options within these menus.
 * 
 *  @copyright Copyright (C) Henrique Silva 2024. All Rights Reserved.
 */

#ifndef MENUS_H
#define MENUS_H
#include "utilities.h"

/**
 * @brief Displays the main menu and prompts the user for an option.
 * 
 * @param option Pointer to an integer where the selected option will be stored.
 */
void mainMenu(int *option);

/**
 * @brief Displays the user menu and prompts the user for an option.
 * 
 * @param option Pointer to an integer where the selected option will be stored.
 * @param e Pointer to the Equipments structure.
 * @param u Pointer to the Users structure.
 */
void userMenu(int *option, Equipments *e, Users *u);

/**
 * @brief Displays the equipment menu and prompts the user for an option.
 * 
 * @param option Pointer to an integer where the selected option will be stored.
 * @param e Pointer to the Equipments structure.
 * @param m Pointer to the Maintenances structure.
 * @param u Pointer to the Users structure.
 */
void equipmentMenu(int *option, Equipments *e, Maintenances *m, Users *u);

/**
 * @brief Handles the selected option in the equipment menu.
 * 
 * @param option The selected option.
 * @param e Pointer to the Equipments structure.
 * @param m Pointer to the Maintenances structure.
 * @param u Pointer to the Users structure.
 */
void handleEquipmentMenuOption(int option, Equipments *e, Maintenances *m, Users *u);

/**
 * @brief Handles the selected option in the user menu.
 * 
 * @param option The selected option.
 * @param e Pointer to the Equipments structure.
 * @param u Pointer to the Users structure.
 */
void handleUserMenuOption(int option, Equipments *e, Users *u);

#endif /* MENUS_H */

