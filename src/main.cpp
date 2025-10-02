#include <iostream>
#include <string>
#include <memory>
#include <iomanip>
#include "LengthConverter.h"
#include "TemperatureConverter.h"

void printUsage(const char* programName) {
    std::cout << "Usage: " << programName << " <converter_type> <value> <from_unit> <to_unit>\n\n";
    std::cout << "Converter Types:\n";
    std::cout << "  length      - Convert length/distance units\n";
    std::cout << "  temperature - Convert temperature units\n\n";
    std::cout << "Examples:\n";
    std::cout << "  " << programName << " length 10 km miles\n";
    std::cout << "  " << programName << " temperature 32 fahrenheit celsius\n\n";
    std::cout << "For supported units, use:\n";
    std::cout << "  " << programName << " <converter_type> --help\n";
}

void printConverterHelp(const UnitConverter& converter) {
    std::cout << "\n" << converter.getConverterType() << " converter\n";
    std::cout << std::string(40, '-') << "\n";
    std::cout << converter.getSupportedUnits() << "\n\n";
}

int main(int argc, char* argv[]) {
    // Check for minimum arguments
    if (argc < 2) {
        printUsage(argv[0]);
        return 1;
    }
    
    std::string converterType = argv[1];
    
    // Create appropriate converter
    std::unique_ptr<UnitConverter> converter;
    
    if (converterType == "length") {
        converter = std::make_unique<LengthConverter>();
    } else if (converterType == "temperature") {
        converter = std::make_unique<TemperatureConverter>();
    } else {
        std::cerr << "Error: Unknown converter type '" << converterType << "'\n\n";
        printUsage(argv[0]);
        return 1;
    }
    
    // Check for help flag
    if (argc == 3 && (std::string(argv[2]) == "--help" || std::string(argv[2]) == "-h")) {
        printConverterHelp(*converter);
        return 0;
    }
    
    // Check for correct number of arguments for conversion
    if (argc != 5) {
        std::cerr << "Error: Incorrect number of arguments\n\n";
        printUsage(argv[0]);
        return 1;
    }
    
    // Parse conversion arguments
    try {
        double value = std::stod(argv[2]);
        std::string fromUnit = argv[3];
        std::string toUnit = argv[4];
        
        // Perform conversion
        double result = converter->convert(value, fromUnit, toUnit);
        
        // Display result
        std::cout << std::fixed << std::setprecision(4);
        std::cout << value << " " << fromUnit << " = " << result << " " << toUnit << "\n";
        
        return 0;
        
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n\n";
        printConverterHelp(*converter);
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
}
