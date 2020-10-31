#include "entity.h"
#include "../entity/pharmacist.h"
#include "../entity/pharmacy.h"

/**
 * Part of application for manipulating with data stored in main
 */
#ifndef SEMESTRAL_PROJECT_DATA_MANAGEMENT_H
#define SEMESTRAL_PROJECT_DATA_MANAGEMENT_H

// Initialization

/**
 * @return DatabaseMetadata with initialized attributes
 */
DatabaseMetadata* init_db_metadata();

/**
 * Allocate initial memory for pharmacist holding structure
 * @return pointer to pointers of elements that we need to store
 */
Pharmacist** init_pharmacist_space();

/**
 * Allocate initial memory for pharmacy holding structure
 * @return pointer to pointers of elements that we need to store
 */
Pharmacy** init_pharmacy_space();

#endif //SEMESTRAL_PROJECT_DATA_MANAGEMENT_H
