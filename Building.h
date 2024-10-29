#ifndef BUILDING_H
#define BUILDING_H

//include "Resources.h"
//#include "Citizen.h"
#include "TaxAuthority.h"
#include <memory>
#include <string>

class TaxAuthority;
/**
 * @brief Represents a building in the city.
 *
 * Product participant in the Factory Method pattern. It defines the properties and methods shared by all types of buildings.
 */
class Building {
private:
    int cost;  ///< The construction cost of the building.
    std::weak_ptr<TaxAuthority> taxAuth;
    /*std::string location;  ///< The location of the building.
    Resources* resources;  ///< Resources used by the building.
    int size;  ///< The size of the building.
    Citizen* owner;  ///< The owner of the building.
    TaxAuthority* taxAuthority;  ///< Tax authority associated with the building.
*/
public:
    /**
     * @brief Constructs a new Building object.
     * @param cost The construction cost.
     * @param location The location of the building.
     * @param resources Pointer to the resources used by the building.
     * @param size The size of the building.
     * @param owner Pointer to the citizen who owns the building.
     * @param taxAuthority Pointer to the tax authority.
     */
    Building(int cost, std::weak_ptr<TaxAuthority> taxAuth/*, std::string location, Resources* resources, int size, Citizen* owner, TaxAuthority* taxAuthority*/);

    /**
     * @brief Destroys the Building object.
     */
    ~Building() = default;

    /**
     * @brief Gets details about the building.
     * @return A string containing details about the building.
     */
     std::string getDetails();

    /**
     * @brief Pays taxes on the building.
     * @param amount The amount of tax to be paid.
     * @param owner Pointer to the building's owner.
     */
     void payTax(int amount);

    int getCost();    
};

#endif // BUILDING_H
