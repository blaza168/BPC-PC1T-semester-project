#include "../../../entity/pharmacy.h"
#include "../../../entity/requests/create/pharmacy_create_request.h"
#include "../../../entity/pharmacist.h"
#include "../../../entity/requests/create/pharmacist_create_request.h"

#ifndef SEMESTRAL_PROJECT_ENTITY_CONVERTOR_H
#define SEMESTRAL_PROJECT_ENTITY_CONVERTOR_H

/**
 * Copy attributes from request to pharmacy
 * Free request and unused fields
 *
 * @param request with attributes
 * @return Pharmacy with fields from request
 */
Pharmacy* create_request_to_pharmacy(PharmacyCreateRequest* request);

/**
 * Copy attributes from request to pharmacist
 * Free request and unused fields
 *
 * @param request with attributes
 * @return Pharmacist with fields from request
 */
Pharmacist* create_request_to_pharmacist(PharmacistCreateRequest* request);

#endif //SEMESTRAL_PROJECT_ENTITY_CONVERTOR_H
