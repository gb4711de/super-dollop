# Unit Converter CLI Tool

A command-line tool for converting between different units of measurement.

## Features

- **Length Conversions**: kilometers ↔ miles, meters ↔ feet
- **Temperature Conversions**: Celsius ↔ Fahrenheit ↔ Kelvin
- **Weight Conversions**: kilograms ↔ pounds ↔ ounces

## Installation

### Prerequisites
- Python 3.7 or higher
- pip (Python package manager)

### Setup

1. Clone the repository:
```bash
git clone https://github.com/gb4711de/super-dollop.git
cd super-dollop
```

2. Install dependencies:
```bash
pip install -r requirements.txt
```

3. Install the CLI tool:
```bash
pip install -e .
```

## Usage

### Convert Units

Basic syntax:
```bash
convert <value> <from_unit> <to_unit>
```

### Examples

**Length conversions:**
```bash
convert 100 km miles          # Convert 100 kilometers to miles
convert 10 meters feet        # Convert 10 meters to feet
```

**Temperature conversions:**
```bash
convert 25 celsius fahrenheit # Convert 25°C to Fahrenheit
convert 98.6 fahrenheit celsius # Convert 98.6°F to Celsius
convert 0 celsius kelvin      # Convert 0°C to Kelvin
```

**Weight conversions:**
```bash
convert 70 kg lbs             # Convert 70 kilograms to pounds
convert 16 oz kg              # Convert 16 ounces to kilograms
```

### List Available Conversions

To see all available unit conversions:
```bash
convert list-conversions
```

### Help

Get help on using the tool:
```bash
convert --help
```

### Quick Demo

Run the examples script to see all conversions in action:
```bash
python3 examples.py
```

## Development

### Running Tests

Install pytest:
```bash
pip install pytest
```

Run the test suite:
```bash
pytest tests/
```

### Project Structure

```
super-dollop/
├── unit_converter/          # Main package directory
│   ├── __init__.py         # Package initialization
│   ├── cli.py              # CLI interface
│   ├── length.py           # Length conversion functions
│   ├── temperature.py      # Temperature conversion functions
│   └── weight.py           # Weight conversion functions
├── tests/                   # Test directory
│   ├── test_length.py      # Length conversion tests
│   ├── test_temperature.py # Temperature conversion tests
│   └── test_weight.py      # Weight conversion tests
├── requirements.txt         # Project dependencies
├── setup.py                # Package setup configuration
└── README.md               # This file
```

## Adding New Conversions

To add new unit conversions:

1. Create a new conversion function in the appropriate module (or create a new module)
2. Add the function to the conversion dictionary
3. Write tests for the new conversion
4. Update this README with examples

Example:
```python
# In unit_converter/length.py
def cm_to_inches(cm):
    """Convert centimeters to inches"""
    return cm * 0.393701

# Add to LENGTH_CONVERSIONS dictionary
LENGTH_CONVERSIONS = {
    # ... existing conversions ...
    'cm_to_inches': cm_to_inches,
}
```

## License

This project is open source and available under the MIT License.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.
