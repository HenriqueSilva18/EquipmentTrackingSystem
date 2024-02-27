/**
 * @file users.h
 * @author Henrique Silva
 * @date 07-02-2024
 * @version 1.0
 * 
 * @brief Header file containing declarations related to user management in the system.
 * 
 * This file declares functions and data structures related to managing users in the system,
 * including adding new users, listing existing users, editing user details, removing users,
 * and handling user equipment assignments and returns.
 * 
 * @copyright Copyright (C) Henrique Silva 2024. All Rights Reserved.
 */

#ifndef USERS_H
#define USERS_H

#include "utilities.h"

#define INITIAL_ALLOCATED_USERS  5

/**
 * @brief Adds a new user to the system.
 * 
 * This function allows the user to add a new user to the system. It prompts the user to enter the user's name,
 * function, and acronym. The user is assigned a unique ID code, and their status is set to ACTIVE by default.
 * 
 * @param users Pointer to the Users structure.
 */
void addUser(Users *users);

/**
 * @brief Lists all users in the system.
 * 
 * This function displays a list of all users in the system, including their ID, name, status, and the number of
 * equipments assigned to them.
 * 
 * @param users Pointer to the Users structure.
 */
void listUsers(Users *users);

/**
 * @brief Edits an existing user in the system.
 * 
 * This function allows the user to edit the details of an existing user in the system. It prompts the user to enter
 * the ID of the user to edit and then provides options to update the user's name, function, and acronym. If the user
 * is inactive, the function also offers the option to activate the user.
 * 
 * @param users Pointer to the Users structure.
 */
void editUser(Users *users);

/**
 * @brief Removes a user from the system.
 * 
 * This function allows the user to remove a user from the system. It prompts the user to enter the ID of the user
 * to remove. If the user has no associated equipments, they are removed from the system entirely. Otherwise, their
 * status is set to INACTIVE.
 * 
 * @param users Pointer to the Users structure.
 */
void removeUser(Users *users);

/**
 * @brief Assigns an equipment to a user.
 * 
 * This function allows the user to assign an equipment to a specific user in the system. It prompts the user to enter
 * the ID of the user and the ID of the equipment to be assigned. If the equipment is available and the user is active,
 * the assignment is made.
 * 
 * @param eq Pointer to the Equipments structure.
 * @param users Pointer to the Users structure.
 */
void getEquipment(Equipments *eq, Users *users);

/**
 * @brief Returns an equipment from a user.
 * 
 * This function allows the user to return an equipment that was previously assigned to a user. It prompts the user
 * to enter the ID of the user and the ID of the equipment to be returned. If the user has the equipment assigned to
 * them, it is returned to the system.
 * 
 * @param eq Pointer to the Equipments structure.
 * @param users Pointer to the Users structure.
 */
void returnEquipment(Equipments *eq, Users *users);

/**
 * @brief Retrieves the string representation of a user's status.
 * 
 * This function returns the string representation of a user's status based on the provided status code.
 * 
 * @param status The status code of the user.
 * @return The string representation of the user's status.
 */
const char* getUserStatusString(UserStatus status);


#endif /* USERS_H */

