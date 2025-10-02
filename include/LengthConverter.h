#ifndef LENGTH_CONVERTER_H
#define LENGTH_CONVERTER_H

#include "UnitConverter.h"
#include <map>

/**
 * @brief Converter for length/distance units
 * 
 * Supports conversions between: meters, kilometers, miles, feet, inches, yards
 */
class LengthConverter : public UnitConverter {
private:
    // Conversion factors to meters (base unit)
    std::map<std::string, double> toMeters;
    
public:
    LengthConverter();
    
    double convert(double value, const std::string& fromUnit, const std::string& toUnit) const override;
    std::string getConverterType() const override;
    std::string getSupportedUnits() const override;
};

#endif // LENGTH_CONVERTER_H
