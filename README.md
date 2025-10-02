# super-dollop
Github Copilot Playground

## Unit Converter CLI Tool

A flexible command-line tool for converting between different units of measurement. Written in C++ with an extensible architecture for adding new converter types.

### Features

- **Length Conversions**: Convert between meters, kilometers, miles, feet, inches, and yards
- **Temperature Conversions**: Convert between Celsius, Fahrenheit, and Kelvin
- **Extensible Design**: Easy to add new converter types
- **User-friendly CLI**: Simple command-line interface with helpful error messages

### Building the Project

#### Requirements

- CMake 3.10 or higher
- C++17 compatible compiler (GCC, Clang, MSVC)

#### Build Steps

```bash
# Create build directory
mkdir build
cd build

# Configure the project
cmake ..

# Build the project
cmake --build .

# The executable will be in the bin/ directory
```

### Usage

Basic syntax:
```bash
./bin/unit_converter <converter_type> <value> <from_unit> <to_unit>
```

#### Examples

**Length conversions:**
```bash
./bin/unit_converter length 10 km miles
./bin/unit_converter length 100 meters feet
./bin/unit_converter length 5 miles km
```

**Temperature conversions:**
```bash
./bin/unit_converter temperature 32 fahrenheit celsius
./bin/unit_converter temperature 0 celsius kelvin
./bin/unit_converter temperature 300 kelvin fahrenheit
```

#### Getting Help

View all converter types:
```bash
./bin/unit_converter
```

View supported units for a specific converter:
```bash
./bin/unit_converter length --help
./bin/unit_converter temperature --help
```

### Supported Units

#### Length
- meters (m, meter, meters)
- kilometers (km, kilometer, kilometers)
- miles (mi, mile, miles)
- feet (ft, foot, feet)
- inches (in, inch, inches)
- yards (yd, yard, yards)

#### Temperature
- celsius (c, celsius)
- fahrenheit (f, fahrenheit)
- kelvin (k, kelvin)

### Architecture

The project follows object-oriented design principles:

```
include/
├── UnitConverter.h          # Abstract base class
├── LengthConverter.h        # Length conversion implementation
└── TemperatureConverter.h   # Temperature conversion implementation

src/
├── main.cpp                 # CLI interface and argument parsing
├── LengthConverter.cpp      # Length conversion logic
└── TemperatureConverter.cpp # Temperature conversion logic
```

### Extending the Tool

To add a new converter type:

1. Create a new header file in `include/` that inherits from `UnitConverter`
2. Implement the required virtual methods:
   - `convert()` - Perform the actual conversion
   - `getConverterType()` - Return the converter name
   - `getSupportedUnits()` - Return help text for supported units
3. Create the implementation file in `src/`
4. Add the new files to `CMakeLists.txt`
5. Add the converter instantiation logic in `main.cpp`

Example structure for a new converter:
```cpp
class WeightConverter : public UnitConverter {
public:
    double convert(double value, const std::string& fromUnit, 
                   const std::string& toUnit) const override;
    std::string getConverterType() const override;
    std::string getSupportedUnits() const override;
};
```

### License

This project is part of the Github Copilot Playground.
