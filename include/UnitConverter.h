#ifndef UNIT_CONVERTER_H
#define UNIT_CONVERTER_H

#include <string>

/**
 * @brief Abstract base class for unit converters
 * 
 * This class provides a common interface for all unit conversion implementations.
 */
class UnitConverter {
public:
    virtual ~UnitConverter() = default;
    
    /**
     * @brief Convert a value from one unit to another
     * 
     * @param value The value to convert
     * @param fromUnit The unit to convert from
     * @param toUnit The unit to convert to
     * @return double The converted value
     */
    virtual double convert(double value, const std::string& fromUnit, const std::string& toUnit) const = 0;
    
    /**
     * @brief Get the name of this converter type
     * 
     * @return std::string The converter type name (e.g., "length", "temperature")
     */
    virtual std::string getConverterType() const = 0;
    
    /**
     * @brief Get a list of supported units for this converter
     * 
     * @return std::string A formatted string listing all supported units
     */
    virtual std::string getSupportedUnits() const = 0;
};

#endif // UNIT_CONVERTER_H
