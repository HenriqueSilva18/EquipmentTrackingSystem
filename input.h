/* 
 *  @file input.h
 *  @author Henrique Silva
 *  @date 07-02-2024
 *  @version 1.0
 * 
 *  @brief Header file for input handling functions.
 * 
 *  This file declares functions for handling user input. It includes functions to read integers within a specified 
 *  range and to read strings of a specified length from the user input. These functions are useful for getting 
 *  validated input from the user in a controlled manner.
 * 
 *  @copyright Copyright (C) Henrique Silva 2024. All Rights Reserved.
 */

#ifndef INPUT_H
#define INPUT_H

/**
 * @brief Prompts the user to enter an integer within a specified range.
 * 
 * This function prompts the user to enter an integer. It ensures that the input is within the specified range (min_value to max_value).
 * If the input is not within this range, the user is prompted again until a valid input is provided.
 * 
 * @param min_value The minimum value in the range.
 * @param max_value The maximum value in the range.
 * @param msg The prompt message displayed to the user.
 * @return The integer entered by the user that falls within the specified range.
 */
int getInt(int min_value, int max_value, char *msg);

/**
 * @brief Reads a string from the user input.
 * 
 * This function prompts the user to enter a string. It reads a line of text from the user input and stores it in
 * the provided character array 'string'. The function ensures that the length of the input does not exceed the specified limit 'size'.
 * 
 * @param string Pointer to the character array where the input string will be stored.
 * @param size The maximum number of characters to read, including the null terminator.
 * @param msg The prompt message displayed to the user.
 */
void readString(char *string, unsigned int size, char *msg);

#endif /* INPUT_H */

