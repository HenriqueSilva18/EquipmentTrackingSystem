/**
 * @file utilities.h
 * @author Henrique Silva
 * @date 07-02-2024
 * @version 1.0
 * 
 * @brief Header file containing utility functions and data structures for equipment and user management.
 * 
 * This header file defines utility functions and data structures used for managing equipment and users in the system.
 * It includes enums for equipment category, maintenance type, equipment status, and user status. Additionally, it
 * defines structs for maintenance records, equipments, and users along with utility functions for date validation
 * and retrieval.
 * 
 * @copyright Copyright (C) Henrique Silva 2024. All Rights Reserved.
 */

#ifndef UTILIZADOR_H
#define UTILIZADOR_H

#define MAX_CHAR            50

#define MIN_DAY             1
#define MAX_DAY             31
#define MIN_MONTH           1
#define MAX_MONTH           12
#define MIN_YEAR            2000
#define MAX_YEAR            2030

/**
 * @brief Enumeration defining the category of equipment.
 */
typedef enum { 
    PRINTER = 1, DESKTOP, LAPTOP, MONITOR, ROUTER, SWITCH, TV, PROJECTOR, ACCESS_CONTROLLER, MOUSE, ACCESSORY, OTHER
} Category;

/**
 * @brief Enumeration defining the type of maintenance.
 */
typedef enum { 
    SOFTWARE_UPDATE = 1, COMPONENT_REPLACEMENT, TECHNICAL, OTHER_MAINTENANCE 
} MaintenanceType;

/**
 * @brief Enumeration defining the status of equipment.
 */
typedef enum { 
    OPERATIONAL = 1, NOT_OPERATIONAL, UNDER_MAINTENANCE, READY_TO_RECYCLE 
} EquipmentStatus;

/**
 * @brief Enumeration defining the status of a user.
 */
typedef enum { 
    INACTIVE = 0, ACTIVE 
} UserStatus;

/**
 * @brief Structure representing a date.
 */
typedef struct {
    int day, month, year;
} Date;

/**
 * @brief Structure representing a maintenance record.
 */
typedef struct {
    char information[MAX_CHAR];
    int movement_number;
    MaintenanceType type;
    Date date_maintenance;
} Maintenance;

/**
 * @brief Structure representing a collection of maintenance records.
 */
typedef struct {
    int counter;
    int allocated;
    int id_count;
    Maintenance *maintenance;
} Maintenances;

/**
 * @brief Structure representing an equipment.
 */
typedef struct{
    int id_equipment;
    int id_code_user;
    int number_maintenances;
    int *maintenance;
    char designation[MAX_CHAR];
    EquipmentStatus status;
    Category category;
    Date date_aquisition;
} Equipment;

/**
 * @brief Structure representing a collection of equipments.
 */
typedef struct {
    int counter;
    int allocated;
    int id_count;
    Equipment *equipments;
} Equipments;

/**
 * @brief Structure representing a user.
 */
typedef struct {
    int id_code_user;
    int count_equipments;
    int *equipments;
    char acronym[MAX_CHAR];
    char name[MAX_CHAR];
    char function[MAX_CHAR];
    UserStatus status;
} User;

/**
 * @brief Structure representing a collection of users.
 */
typedef struct {
    int counter;
    int allocated;
    int id_count;
    User *users;
} Users;

/**
 * @brief Checks if a given year is a leap year.
 * 
 * This function determines whether the specified year is a leap year or not according to the Gregorian calendar.
 * A leap year occurs every four years, except for years that are divisible by 100 but not divisible by 400.
 * 
 * @param year The year to check for leap year.
 * @return 1 if the year is a leap year, 0 otherwise.
 */
int isLeapYear(int year);

/**
 * @brief Validates a date.
 * 
 * This function checks if the specified day, month, and year combination represents a valid date.
 * It considers leap years and the varying number of days in each month.
 * 
 * @param day The day of the month.
 * @param month The month of the year.
 * @param year The year.
 * @return 1 if the date is valid, 0 otherwise.
 */
int isValidDate(int day, int month, int year);

/**
 * @brief Prompts the user to enter a valid date.
 * 
 * This function prompts the user to enter a valid date by asking for the day, month, and year.
 * It ensures that the entered date is valid by checking leap years and the number of days in each month.
 * 
 * @param dayPrompt The prompt for the day of the month.
 * @param monthPrompt The prompt for the month of the year.
 * @param yearPrompt The prompt for the year.
 * @return A Date structure representing the valid date entered by the user.
 */
Date getDate(char *dayPrompt, char *monthPrompt, char *yearPrompt);

#endif /* UTILITIES_H */