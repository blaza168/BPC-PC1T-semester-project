#include "../entity/pharmacist.h"
#include "../entity/pharmacy.h"

#ifndef SEMESTRAL_PROJECT_ALERTS_H
#define SEMESTRAL_PROJECT_ALERTS_H

/**
 * Alert after successful pharmacy creation
 *
 * @param pharmacy - created entity
 */
void display_pharmacy_creation_success_alert(Pharmacy* pharmacy);

/**
 * Display duplicate pharmacy name error
 */
void display_pharmacy_creation_error_alert();

/**
 * Alert after successful pharmacist creation
 *
 * @param pharmacist - created entity
 */
void display_pharmacist_creation_success_alert(Pharmacist* pharmacist);

/**
 * Display duplicate firstname + lastname combination
 */
void display_pharmacist_creation_error_alert();

/**
 * Display alert after successful assignment
 */
void display_assign_success_alert();

/**
 * Display alert after unsuccessful assignment
 *
 * @param error message to me displayed to user (NOT WHOLE ALERT!)
 */
void display_assign_error_alert(char* error_message);

/**
 * Display alert if pharmacy cannot be found
 */
void display_pharmacy_not_found_alert();

/**
 * Display alert if pharmacist cannot be found
 */
void display_pharmacist_not_found_alert();

/**
 * Display alert after successful pharmacy update
 */
void display_pharmacy_update_success_alert();

/**
 * Display alert after successful pharmacist update
 */
void display_pharmacist_update_success_alert();

/**
 * Display pharmacy details
 */
void display_pharmacy_detail_alert(Pharmacy* pharmacy);

/**
 * Display pharmacist details
 *
 * @param pharmacy - associated pharmacy
 */
void display_pharmacist_detail_alert(Pharmacist* pharmacist, Pharmacy* pharmacy);

/**
 * Display alert after successful deletion of pharmacist 
 */
void display_pharmacist_deletion_success_alert();

/**
 * Display alert if pharmacist is not registered in the system
 */
void display_pharmacist_deletion_error_alert();

/**
 * Display alert after successful deletion of pharmacy
 */
void display_pharmacy_deletion_success_alert();

/**
 * Display alert if pharmacy is not registered in the system
 */
void display_pharmacy_deletion_error_alert();

#endif //SEMESTRAL_PROJECT_ALERTS_H
