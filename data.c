#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utilities.h"
#include "equipments.h"
#include "maintenances.h"
#include "users.h"
#include "data.h" 

void loadFiles(Equipments *e, Maintenances *m, Users *u, const char *equipment_file, const char *maintenance_file, const char *user_file) {
  
    loadEquipmentFiles(e, equipment_file);
    loadMaintenanceFiles(m, maintenance_file);
    loadUserFiles(u, user_file);
    
}

void saveFiles(Equipments *e, Maintenances *m, Users *u, const char *equipment_file, const char *maintenance_file, const char *user_file) {
    
    saveEquipmentFiles(e, equipment_file);
    saveMaintenanceFiles(m, maintenance_file);
    saveUserFiles(u, user_file);
    
}

void freeData(Equipments *e, Maintenances *m, Users *u) {
    int i;
    
    for (i = 0; i < e->counter; i++) {
        if (e->equipments[i].maintenance != NULL) {
            free(e->equipments[i].maintenance);
            e->equipments[i].maintenance = NULL;
        }
    }
    free(e->equipments);

    free(m->maintenance);

    for (i = 0; i < u->counter; i++) {
        if (u->users[i].equipments != NULL) {
            free(u->users[i].equipments);
            u->users[i].equipments = NULL;
        }
    }
    free(u->users);
}

void loadEquipmentFiles(Equipments *e, const char *equipment_file) {
    int i, success_eq = 0;
    
    FILE *fp_eq = fopen(equipment_file, "rb");
    if (fp_eq != NULL) {
        fread(&e->counter, sizeof(int), 1, fp_eq);
        fread(&e->id_count, sizeof(int), 1, fp_eq);
        fread(&e->allocated, sizeof(int), 1, fp_eq);
        e->equipments = (Equipment*) malloc(e->allocated * sizeof(Equipment));
        if (e->equipments == NULL) {
            printf("Error allocating memory. ");
            exit(EXIT_FAILURE);
        }
        if (e->counter > 0) {
            for (i = 0; i < e->counter; i++) {
                fread(&e->equipments[i], sizeof(Equipment), 1, fp_eq);
                if (e->equipments[i].number_maintenances > 0) {
                    e->equipments[i].maintenance = (int *) calloc(e->equipments[i].number_maintenances, sizeof(int));
                    fread(e->equipments[i].maintenance, sizeof(int), e->equipments[i].number_maintenances, fp_eq);
                } else {
                    e->equipments[i].maintenance = NULL;
                }
            }
        }
        success_eq = 1;
        fclose(fp_eq);
    }
    if (!success_eq) {
        fp_eq = fopen(equipment_file, "wb");
        if (fp_eq != NULL) {
            e->equipments = (Equipment*) malloc(INITIAL_ALLOCATED_EQUIPMENTS * sizeof(Equipment));
            if (e->equipments == NULL) {
                printf("Error allocating memory. ");
                exit(EXIT_FAILURE);
            }
            e->counter = 0;
            e->id_count = 0;
            e->allocated = INITIAL_ALLOCATED_EQUIPMENTS;
            
            fclose(fp_eq);
        }
    }
}

void loadMaintenanceFiles(Maintenances *m, const char *maintenance_file) {
    int i, success_maintenances = 0;
    
    FILE *fp_main = fopen(maintenance_file, "rb");
    if (fp_main != NULL) {
        fread(&m->counter, sizeof(int), 1, fp_main);
        fread(&m->id_count, sizeof(int), 1, fp_main);
        fread(&m->allocated, sizeof(int), 1, fp_main);
        m->maintenance = (Maintenance *) malloc(m->allocated * sizeof(Maintenance));
        if (m->maintenance == NULL) {
            printf("Error allocating memory. ");
            exit(EXIT_FAILURE);
        }
        
        if (m->counter > 0) {
            for (i = 0; i < m->counter; i++) {
                fread(&m->maintenance[i], sizeof(Maintenance), 1, fp_main);
            }
        }
        success_maintenances = 1;
        fclose(fp_main);
    }
    if (!success_maintenances) {
        fp_main = fopen(maintenance_file, "wb");
        if (fp_main != NULL) {
            m->maintenance = (Maintenance *) malloc(INITIAL_ALLOCATED_MAINTENANCES * sizeof(Maintenance));
            if (m->maintenance == NULL) {
                printf("Error allocating memory. ");
                exit(EXIT_FAILURE);
            }
            m->counter = 0;
            m->id_count = 0;
            m->allocated = INITIAL_ALLOCATED_MAINTENANCES;
            
            fclose(fp_main);
        }
    }
}

void loadUserFiles(Users *u, const char *user_file) {
    int i, success_user = 0;
    
    FILE *fp_user = fopen(user_file, "rb");
    if (fp_user != NULL) {
        fread(&u->counter, sizeof(int), 1, fp_user);
        fread(&u->id_count, sizeof(int), 1, fp_user);
        fread(&u->allocated, sizeof(int), 1, fp_user);
        u->users = (User *) malloc(u->allocated * sizeof(User));
        if (u->users == NULL) {
            printf("Error allocating memory. ");
            exit(EXIT_FAILURE);
        }
        
        if (u->counter > 0) {
            for (i = 0; i < u->counter; i++) {
                fread(&u->users[i].id_code_user, sizeof(int), 1, fp_user);
                fread(&u->users[i].count_equipments, sizeof(int), 1, fp_user);
                fread(u->users[i].acronym, sizeof(char), MAX_CHAR, fp_user);
                fread(u->users[i].name, sizeof(char), MAX_CHAR, fp_user);
                fread(u->users[i].function, sizeof(char), MAX_CHAR, fp_user);
                fread(&u->users[i].status, sizeof(UserStatus), 1, fp_user);

                if (u->users[i].count_equipments > 0) {
                    u->users[i].equipments = (int *) malloc(u->users[i].count_equipments * sizeof(int));
                    fread(u->users[i].equipments, sizeof(int), u->users[i].count_equipments, fp_user);
                } else {
                    u->users[i].equipments = NULL;
                }
            }
        }
        success_user = 1;
        fclose(fp_user);
    }
    if (!success_user) {
        fp_user = fopen(user_file, "wb");
        if (fp_user != NULL) {
            u->users = (User *) malloc(INITIAL_ALLOCATED_USERS * sizeof(User));
            if (u->users == NULL) {
                printf("Error allocating memory. ");
                exit(EXIT_FAILURE);
            }
            u->counter = 0;
            u->id_count = 0;
            u->allocated = INITIAL_ALLOCATED_USERS;
            
            fclose(fp_user);
        }
    }        
}

void saveEquipmentFiles(Equipments *e, const char *equipment_file) {
    int i;
    
    FILE *fp_eq = fopen(equipment_file, "wb");
    if (fp_eq == NULL) {
        exit(EXIT_FAILURE);
    }
    
    fwrite(&e->counter, sizeof(int), 1, fp_eq);
    fwrite(&e->id_count, sizeof(int), 1, fp_eq);
    fwrite(&e->allocated, sizeof(int), 1, fp_eq);
    
    for (i = 0; i < e->counter; i++) {
        fwrite(&e->equipments[i], sizeof(Equipment), 1, fp_eq);
        fwrite(e->equipments[i].maintenance, sizeof(int), e->equipments[i].number_maintenances, fp_eq);
    }
    
    fclose(fp_eq);
}

void saveMaintenanceFiles(Maintenances *m, const char *maintenance_file) {
    int i;
    
    FILE *fp_main = fopen(maintenance_file, "wb");
    if (fp_main == NULL) {
        exit(EXIT_FAILURE);
    }
    fwrite(&m->counter, sizeof(int), 1, fp_main);
    fwrite(&m->id_count, sizeof(int), 1, fp_main);
    fwrite(&m->allocated, sizeof(int), 1, fp_main);
    for (i = 0; i < m->counter; i++) {
        fwrite(&m->maintenance[i], sizeof(Maintenance), 1, fp_main);
    }
    fclose(fp_main);
}

void saveUserFiles(Users *u, const char *user_file) {
    int i;
    
    FILE *fp_user = fopen(user_file, "wb");
    if (fp_user == NULL) {
        exit(EXIT_FAILURE);
    }
    fwrite(&u->counter, sizeof(int), 1, fp_user);
    fwrite(&u->id_count, sizeof(int), 1, fp_user);
    fwrite(&u->allocated, sizeof(int), 1, fp_user);
    for (i = 0; i < u->counter; i++) {
        fwrite(&u->users[i].id_code_user, sizeof(int), 1, fp_user);
        fwrite(&u->users[i].count_equipments, sizeof(int), 1, fp_user);
        fwrite(u->users[i].acronym, sizeof(char), MAX_CHAR, fp_user);
        fwrite(u->users[i].name, sizeof(char), MAX_CHAR, fp_user);
        fwrite(u->users[i].function, sizeof(char), MAX_CHAR, fp_user);
        fwrite(&u->users[i].status, sizeof(UserStatus), 1, fp_user);
        
        if(u->users[i].count_equipments > 0) {
            fwrite(u->users[i].equipments, sizeof(int), u->users[i].count_equipments, fp_user);
        }
    }
    fclose(fp_user);
}