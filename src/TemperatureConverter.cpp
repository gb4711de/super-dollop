#include "TemperatureConverter.h"
#include <stdexcept>
#include <algorithm>

double TemperatureConverter::celsiusToFahrenheit(double celsius) const {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double TemperatureConverter::fahrenheitToCelsius(double fahrenheit) const {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double TemperatureConverter::celsiusToKelvin(double celsius) const {
    return celsius + 273.15;
}

double TemperatureConverter::kelvinToCelsius(double kelvin) const {
    return kelvin - 273.15;
}

double TemperatureConverter::convert(double value, const std::string& fromUnit, const std::string& toUnit) const {
    // Normalize unit strings to lowercase for comparison
    std::string from = fromUnit;
    std::string to = toUnit;
    std::transform(from.begin(), from.end(), from.begin(), ::tolower);
    std::transform(to.begin(), to.end(), to.begin(), ::tolower);
    
    // Handle same unit conversion
    if (from == to) {
        return value;
    }
    
    // Convert from source to celsius first
    double celsius;
    if (from == "c" || from == "celsius") {
        celsius = value;
    } else if (from == "f" || from == "fahrenheit") {
        celsius = fahrenheitToCelsius(value);
    } else if (from == "k" || from == "kelvin") {
        celsius = kelvinToCelsius(value);
    } else {
        throw std::invalid_argument("Unknown source unit: " + fromUnit);
    }
    
    // Convert from celsius to target unit
    if (to == "c" || to == "celsius") {
        return celsius;
    } else if (to == "f" || to == "fahrenheit") {
        return celsiusToFahrenheit(celsius);
    } else if (to == "k" || to == "kelvin") {
        return celsiusToKelvin(celsius);
    } else {
        throw std::invalid_argument("Unknown target unit: " + toUnit);
    }
}

std::string TemperatureConverter::getConverterType() const {
    return "temperature";
}

std::string TemperatureConverter::getSupportedUnits() const {
    return "Supported temperature units:\n"
           "  - celsius (c, celsius)\n"
           "  - fahrenheit (f, fahrenheit)\n"
           "  - kelvin (k, kelvin)";
}
