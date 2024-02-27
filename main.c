/* 
 *  @file main.c
 *  @author Henrique Silva
 *  @date 07-02-2024
 *  @version 1.0
 * 
 *  @brief Main entry point for the Equipment Managing System.
 * 
 *  This file contains the main function which serves as the entry point for the Equipment Managing System.
 *  It initializes the necessary structures and enters the main loop which handles the user interface and
 *  interactions. The program allows for managing equipment, maintenance records, and user data, providing 
 *  various functionalities like adding, editing, listing, and removing equipments and users, as well as assigning
 *  and returning equipments.
 * 
 *  Usage:
 *  Run the program and follow the on-screen prompts to interact with the system.
 * 
 *  @copyright Copyright (C) Henrique Silva 2024. All Rights Reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"
#include "data.h"
#include "menus.h"
#include "input.h"
#include "equipments.h"
#include "users.h"
#include "maintenances.h"

int main(int argc, char** argv) {
    int option;
    
    Maintenances m;
    Users u;
    Equipments e;
    
    loadFiles(&e, &m, &u, EQUIPMENT_FILE, MAINTENANCE_FILE, USER_FILE);
    
    menuFrame(&option, &e, &m, &u);
    
    saveFiles(&e, &m, &u, EQUIPMENT_FILE, MAINTENANCE_FILE, USER_FILE);
    freeData(&e, &m, &u);
    
    return (EXIT_SUCCESS);
}