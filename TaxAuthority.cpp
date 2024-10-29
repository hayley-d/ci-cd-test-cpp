#include "TaxAuthority.h"

TaxAuthority::TaxAuthority(){
    this->buildings = std::make_unique<BuildingCollection>();
    this->strategy = std::make_unique<FlatTaxStrategy>();
    this->collectedTax = 0;
}

void TaxAuthority::registerBuilding(std::shared_ptr<Building> building) {
    this->buildings->addBuilding(building);
}

void TaxAuthority::registerCitizen(std::shared_ptr<Citizen> citizen) {
    this->citizens.push_back(citizen);
}

void TaxAuthority::collectTaxes() {
    this->collectedTax = 0; // Reset the collected tax for the new cycle
    
    // Collect Taxes
    this->notifyBuildings();
    this->notifyCitizens();
}

void TaxAuthority::notifyCitizens() {
    for(auto c : this->citizens) {
        c->payTax(calculateCitizenTax(c->getFunds()));
    }
}

void TaxAuthority::notifyBuildings() {
    int counter = 0;
    for(auto it = buildings->begin(); it != buildings->end(); ++it) {
        counter++;
        auto building = *it;
        building->payTax(calculateBuildingTax(building->getCost()));
    }
}

void TaxAuthority::setStrategy(std::unique_ptr<TaxStrategy> taxStrategy) {
    this->strategy = std::move(taxStrategy);
}

int TaxAuthority::calculateBuildingTax(int value) {
    return this->strategy->calculateBuildingTax(value);
}

int TaxAuthority::calculateCitizenTax(int earnings) {
    return this->strategy->calculateCitizenTax(earnings);
}

void TaxAuthority::sendTax(int amount) {
    this->collectedTax += amount;
}
