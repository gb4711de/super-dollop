#ifndef TEMPERATURE_CONVERTER_H
#define TEMPERATURE_CONVERTER_H

#include "UnitConverter.h"

/**
 * @brief Converter for temperature units
 * 
 * Supports conversions between: celsius, fahrenheit, kelvin
 */
class TemperatureConverter : public UnitConverter {
private:
    double celsiusToFahrenheit(double celsius) const;
    double fahrenheitToCelsius(double fahrenheit) const;
    double celsiusToKelvin(double celsius) const;
    double kelvinToCelsius(double kelvin) const;
    
public:
    double convert(double value, const std::string& fromUnit, const std::string& toUnit) const override;
    std::string getConverterType() const override;
    std::string getSupportedUnits() const override;
};

#endif // TEMPERATURE_CONVERTER_H
