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




#endif //SEMESTRAL_PROJECT_ALERTS_H
