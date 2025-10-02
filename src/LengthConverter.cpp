#include "LengthConverter.h"
#include <stdexcept>
#include <sstream>

LengthConverter::LengthConverter() {
    // Initialize conversion factors to meters
    toMeters["m"] = 1.0;
    toMeters["meter"] = 1.0;
    toMeters["meters"] = 1.0;
    
    toMeters["km"] = 1000.0;
    toMeters["kilometer"] = 1000.0;
    toMeters["kilometers"] = 1000.0;
    
    toMeters["mi"] = 1609.34;
    toMeters["mile"] = 1609.34;
    toMeters["miles"] = 1609.34;
    
    toMeters["ft"] = 0.3048;
    toMeters["foot"] = 0.3048;
    toMeters["feet"] = 0.3048;
    
    toMeters["in"] = 0.0254;
    toMeters["inch"] = 0.0254;
    toMeters["inches"] = 0.0254;
    
    toMeters["yd"] = 0.9144;
    toMeters["yard"] = 0.9144;
    toMeters["yards"] = 0.9144;
}

double LengthConverter::convert(double value, const std::string& fromUnit, const std::string& toUnit) const {
    // Check if units are supported
    if (toMeters.find(fromUnit) == toMeters.end()) {
        throw std::invalid_argument("Unknown source unit: " + fromUnit);
    }
    if (toMeters.find(toUnit) == toMeters.end()) {
        throw std::invalid_argument("Unknown target unit: " + toUnit);
    }
    
    // Convert to meters, then to target unit
    double meters = value * toMeters.at(fromUnit);
    return meters / toMeters.at(toUnit);
}

std::string LengthConverter::getConverterType() const {
    return "length";
}

std::string LengthConverter::getSupportedUnits() const {
    std::ostringstream oss;
    oss << "Supported length units:\n"
        << "  - meters (m, meter, meters)\n"
        << "  - kilometers (km, kilometer, kilometers)\n"
        << "  - miles (mi, mile, miles)\n"
        << "  - feet (ft, foot, feet)\n"
        << "  - inches (in, inch, inches)\n"
        << "  - yards (yd, yard, yards)";
    return oss.str();
}
