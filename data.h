/* 
 *  @file data.h
 *  @author Henrique Silva
 *  @date 07-02-2024
 *  @version 1.0
 * 
 *  @brief Defines functions for loading, saving, and managing equipment, maintenance, and user data.
 * 
 *  This header file includes essential functions for persistent data handling in an equipment 
 *  management system. It covers operations for loading data from and saving data to external files, 
 *  and for properly freeing allocated memory resources.
 * 
 *  @copyright Copyright (C) Henrique Silva 2024. All Rights Reserved.
 */

#ifndef DATA_H
#define DATA_H

#define EQUIPMENT_FILE     "equipment_data.bin"
#define MAINTENANCE_FILE   "maintenance_data.bin"
#define USER_FILE          "user_data.bin"

/**
 * @brief Loads data from files into program structures.
 *
 * This function reads data from specified files and loads it into program structures for equipments, maintenances, and users. It ensures that the program's memory is populated with the most recent data, allowing for seamless continuity in the application's operation across sessions. The function internally calls specialized functions for loading each type of data.
 *
 * @param e Pointer to the Equipments structure to store loaded equipment data.
 * @param m Pointer to the Maintenances structure to store loaded maintenance data.
 * @param u Pointer to the Users structure to store loaded user data.
 * @param equipment_file Path to the file from which equipment data will be loaded.
 * @param maintenance_file Path to the file from which maintenance data will be loaded.
 * @param user_file Path to the file from which user data will be loaded.
 */
void loadFiles(Equipments *e, Maintenances *m, Users *u, const char *equipment_file, const char *maintenance_file, const char *user_file);

/**
 * @brief Saves data from program structures into files.
 *
 * This function writes the current data from the program's structures for equipments, maintenances, and users into specified files. This ensures data persistence, saving the state of the program's data for future sessions. The function internally calls specialized functions for saving each type of data.
 *
 * @param e Pointer to the Equipments structure containing data to be saved.
 * @param m Pointer to the Maintenances structure containing data to be saved.
 * @param u Pointer to the Users structure containing data to be saved.
 * @param equipment_file Path to the file where equipment data will be saved.
 * @param maintenance_file Path to the file where maintenance data will be saved.
 * @param user_file Path to the file where user data will be saved.
 */
void saveFiles(Equipments *e, Maintenances *m, Users *u, const char *equipment_file, const char *maintenance_file, const char *user_file);

/**
 * @brief Frees dynamically allocated memory for program structures.
 *
 * This function ensures that all dynamically allocated memory used within the program for storing equipments, maintenances, and users is properly freed. It is essential for preventing memory leaks and maintaining the health of the application, especially before the program is terminated or when re-initializing data structures. Each structure's elements are iteratively freed, followed by the structures themselves.
 *
 * @param e Pointer to the Equipments structure from which dynamically allocated memory will be freed.
 * @param m Pointer to the Maintenances structure from which dynamically allocated memory will be freed.
 * @param u Pointer to the Users structure from which dynamically allocated memory will be freed.
 */
void freeData(Equipments *e, Maintenances *m, Users *u);

/**
 * @brief Loads equipment data from a file.
 * 
 * This function reads equipment data from a binary file specified by 'equipment_file'. It dynamically allocates memory for storing the equipment data, ensuring proper handling of memory allocation failures. The function reads the number of equipments, their IDs, and allocated memory size from the file. It then reads each equipment's details, including its maintenance history if present.
 *
 * @param e Pointer to the Equipments structure where the loaded data will be stored.
 * @param equipment_file Path to the file from which equipment data is loaded.
 */
void loadEquipmentFiles(Equipments *e, const char *equipment_file);

/**
 * @brief Loads maintenance data from a file.
 * 
 * This function reads maintenance records from a binary file specified by 'maintenance_file'. It allocates memory for the maintenance records and reads the total count, ID count, and allocated size for maintenances. Each maintenance record is then read from the file into the allocated memory.
 *
 * @param m Pointer to the Maintenances structure where the loaded data will be stored.
 * @param maintenance_file Path to the file from which maintenance data is loaded.
 */
void loadMaintenanceFiles(Maintenances *m, const char *maintenance_file);

/**
 * @brief Loads user data from a file.
 * 
 * This function reads user data from a binary file specified by 'user_file'. It allocates memory for storing user data and reads the total count, ID count, and allocated size for users. Each user's data, including their assigned equipments if any, is read from the file into the allocated memory.
 *
 * @param u Pointer to the Users structure where the loaded data will be stored.
 * @param user_file Path to the file from which user data is loaded.
 */
void loadUserFiles(Users *u, const char *user_file);

/**
 * @brief Saves equipment data to a file.
 * 
 * This function writes equipment data to a binary file specified by 'equipment_file'. It writes the total count, ID count, and allocated memory size for equipments, followed by details of each equipment, including their maintenance history.
 *
 * @param e Pointer to the Equipments structure containing the data to be saved.
 * @param equipment_file Path to the file where equipment data will be saved.
 */
void saveEquipmentFiles(Equipments *e, const char *equipment_file);

/**
 * @brief Saves maintenance data to a file.
 * 
 * This function writes maintenance records to a binary file specified by 'maintenance_file'. It writes the total count, ID count, and allocated memory size for maintenances, followed by details of each maintenance record.
 *
 * @param m Pointer to the Maintenances structure containing the data to be saved.
 * @param maintenance_file Path to the file where maintenance data will be saved.
 */
void saveMaintenanceFiles(Maintenances *m, const char *maintenance_file);

/**
 * @brief Saves user data to a file.
 * 
 * This function writes user data to a binary file specified by 'user_file'. It writes the total count, ID count, and allocated memory size for users, followed by details of each user, including their assigned equipments if any.
 *
 * @param u Pointer to the Users structure containing the data to be saved.
 * @param user_file Path to the file where user data will be saved.
 */
void saveUserFiles(Users *u, const char *user_file);
#endif /* DATA_H */

